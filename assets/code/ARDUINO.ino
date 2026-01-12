#include "arduinoFFT.h"
#include <Servo.h>
#include <Wire.h>
#include <PCF8574.h>



Servo brnkServo;

#define SERVO_PIN 10
#define SERVO_LEFT 65
#define SERVO_RIGHT 122
#define SERVO_STOP 90

int direction = 1; // 1 = doprava, -1 = doleva (pro brnkací servo)
bool lastDirectionRight = true;
bool ignoreOnePluck = false;
bool stringJustFinished = false;
bool allStringsCompleted = false;

bool tuningEnabled = false;
bool tuningFinished = false;
bool programRunning = false;
bool manualMode = false;

bool waitForIgnoredPluck = false;

int noFreqCountString0 = 0;


#define SAMPLES 128
#define SAMPLING_FREQUENCY 2000 // Hz


arduinoFFT FFT;
double vReal[SAMPLES];
double vImag[SAMPLES];

unsigned long microseconds;
unsigned int sampling_period_us;

// Ukulele frekvence
double targetFreq[4] = {396.6, 266.6, 335.0, 447.0}; // 0=A, 1=C, 2=E, 3=G
int currentString = 0;

// --- POZOR: deklarace PCF8574 přesunuta sem (před setup) ---
PCF8574 pcf1(0x20);
PCF8574 pcf2(0x21);

#define MANUAL_RUN_TIME 30000UL   // 30 sekund


void setup() {
    Serial.begin(9600);
    brnkServo.attach(SERVO_PIN);
    brnkServo.write(SERVO_STOP);

    sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));

    Wire.begin();
    delay(50);
    pcf1.begin();
    pcf2.begin();

    
    for (int i = 0; i < 8; i++) {
        pcf1.write(i, LOW);
        pcf2.write(i, LOW);
    }

    Serial.println("Setup hotovo.");
}

void loop() {


      if (Serial.available()) {
        char c = Serial.read();

        // ---------- STOP ----------
        if (c == 'X') {
            programRunning = false;
            manualMode = false;
            ResetState();
            return;
        }

        // ---------- MANUÁLNÍ PŘÍKAZ ----------
        if (c == 'g' || c == 'c' || c == 'e' || c == 'a') {

            char dirChar = '\0';

            // počkej maximálně 100 ms na druhý znak (+ nebo -)
            unsigned long start = millis();
            while (!Serial.available() && (millis() - start < 100));
            if (Serial.available()) dirChar = Serial.read();
            else dirChar = '+'; // default, pokud nic nepřišlo

            ManualStep(c, dirChar);
            return;
        }

        // ---------- AUTOMAT ----------
        switch (c) {
            case 'K':
                Home();
                break;

            case 'S':
                manualMode = false;
                programRunning = true;
                break;
        }
    }


    if (manualMode) {
    brnkServo.write(SERVO_STOP);
    return;
    }


  
    if (!programRunning) {
        brnkServo.write(SERVO_STOP);
        return;
    }

    if (tuningFinished) {
        brnkServo.write(SERVO_STOP);  // jistota
        return;                       // loop už nic nedělá
    }


    static bool startWaitDone = false;

    if (!startWaitDone) {

        delay(500);

        startWaitDone = true;

    }
    // --- 1) SERVO UDĚLÁ KROK ---
    if (direction == 1) StepRight();
    else StepLeft();

    // --- 2) MIKROFON ZAČNE MĚŘIT DŘÍVE ---
    delay(10); // místo 50 → zachytí začátek tónu

    // --- 3) 2s měření ---
    double freq = MeasureForSeconds(2);
    Serial.print("Naměřeno: ");
    Serial.println(freq);

    


    brnkServo.write(SERVO_STOP);
    delay(500);

    if (ignoreOnePluck && freq > 0) {
    Serial.println("Ignoruji jedno brnknutí");

    ignoreOnePluck = false;
    waitForIgnoredPluck = false;   // ⬅️ ignorace hotová
    freq = 0;

    // TEĎ už smíme přejít na další strunu
    NextString();
    }


    if (freq != 0) {
        direction *= -1;
        lastDirectionRight = (direction == -1);
    }

    // --- 5) LADĚNÍ AKTUÁLNÍ STRUNY ---
    TuneCurrentString(freq);

    if (stringJustFinished) {

    // pokud poslední krok byl doprava → jdeme rovnou dál
    if (lastDirectionRight) {
        NextString();
    }
    // pokud byl vlevo → čekáme na ignorované brnknutí
    // (NextString() se zavolá až po ignoraci)

    stringJustFinished = false;
    }


    if (currentString == 0 && allStringsCompleted) {
        GoHome();
    }

    
}

// --------------------- FFT + ODSTRANĚNÍ ŠUMU ---------------------
#define BUFFER_SIZE 20
double freqBuffer[BUFFER_SIZE];
int bufferIndex = 0;

void AddFrequency(double f) {
    if (f < 220 || f > 600) return; // širší okno
    freqBuffer[bufferIndex] = f;
    bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
}


double ProcessFrequencies() {
    double sum = 0;
    int count = 0;
    double firstMeasuredFreq = 0;


    double minFreq = 1e6; // pro kontrolu rozptýlení
    double maxFreq = 0;
    double target = targetFreq[currentString];

    for (int i = 0; i < BUFFER_SIZE; i++) {
        double f = freqBuffer[i];
        if (f <= 0) continue;

        if (firstMeasuredFreq == 0) firstMeasuredFreq = f;

        if (abs(f - target) <= 30) {
            Serial.print("OK: ");
            Serial.println(f);

            sum += f;
            count++;
            

            if (f < minFreq) minFreq = f;
            if (f > maxFreq) maxFreq = f;
        }
        
    }
    Serial.println(firstMeasuredFreq);

    // ⬇⬇⬇ rozdílný minimální počet vzorků podle struny ⬇⬇⬇
    int minSamples = (currentString == 1 || currentString == 2) ? 3 : 2;

    if (count > 1 && (maxFreq - minFreq > 40)) {
        
        return 0;
    }

    if (currentString == 0 && count < minSamples && firstMeasuredFreq > 0) {
        if (abs(firstMeasuredFreq - target) <= 20) {
            return firstMeasuredFreq;
        } else {
            return 0; // nedá se použít
        }
    }



    if (count < minSamples) return 0;

    Serial.print("Použito vzorků: ");
    Serial.println(count);

    return sum / count;
}




double FindDominantFrequency() {
    
    
    for (int i = 0; i < SAMPLES; i++) {
        microseconds = micros();
        vReal[i] = analogRead(2);
        vImag[i] = 0;
        while (micros() < (microseconds + sampling_period_us));
    }

    double mean = 0;
    for (int i = 0; i < SAMPLES; i++) mean += vReal[i];
    mean /= SAMPLES;
    for (int i = 0; i < SAMPLES; i++) vReal[i] -= mean;

    double level = 0;
    for (int i = 0; i < SAMPLES; i++) level += abs(vReal[i]);
    level /= SAMPLES;

    if (level < 1) return 0;

    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    if (peak < 30) return 0;

    return peak;

}

// --------------------- LADĚNÍ STRUN ---------------------
void TuneCurrentString(double freq) {

    if (freq == 0) {

        return;
    }

    double target = targetFreq[currentString];
    double lowLimit = target - 0.5;
    double highLimit = target + 0.5;


    if (freq < lowLimit) {
        AdjustString(currentString, target, freq);
    } else if (freq > highLimit) {
        AdjustString(currentString, target, freq);
    } else {
        delay(800);

        stringJustFinished = true;

        if (!lastDirectionRight) {
            // poslední krok byl vlevo → musíme jedno brnknutí ignorovat
            ignoreOnePluck = true;
            waitForIgnoredPluck = true;
        }

        if (lastDirectionRight) direction = 1;
        else direction = 1;

        stringJustFinished = true;

        return;
    }
}


void StepRight() {
    brnkServo.write(SERVO_RIGHT);
    delay(200);
    brnkServo.write(SERVO_STOP);
}

void StepLeft() {
    brnkServo.write(SERVO_LEFT);
    delay(200);
    brnkServo.write(SERVO_STOP);
}

void GoHome() {
    brnkServo.write(1);
    delay(1000);
    brnkServo.write(SERVO_STOP);
    delay(100);
    brnkServo.write(180);
    delay(1000);
    brnkServo.write(1);
    delay(1000);
    brnkServo.write(SERVO_STOP);
    delay(100);
    brnkServo.write(180);
    delay(1000);
    brnkServo.write(1);
    delay(1000);
}

double MeasureForSeconds(float sec) {
    unsigned long tEnd = millis() + (unsigned long)(sec * 1000.0);
    for (int i = 0; i < BUFFER_SIZE; i++) freqBuffer[i] = 0;

    while (millis() < tEnd) {

        double f = FindDominantFrequency();

        if (f > 220) {   // jen smysluplné hodnoty
            Serial.print("FFT: ");
            Serial.println(f);
        }

        AddFrequency(f);
    }
    return ProcessFrequencies();
}

// -----------------------------------------------------------
// MAPOVÁNÍ STRUN NA KROKOVÉ MOTORY
// -----------------------------------------------------------
const int stepSeq[8][4] = {
    {1, 0, 0, 1}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0},
    {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}
};

void stepMotor(PCF8574 &pcf, int basePin, int stepIndex) {
    for (int i = 0; i < 4; i++) {
        pcf.write(basePin + i, stepSeq[stepIndex][i]);
    }
}

void stopMotor(PCF8574 &pcf, int basePin) {
    for (int i = 0; i < 4; i++) pcf.write(basePin + i, LOW);
}

void runStepper(PCF8574 &pcf, int basePin, unsigned long duration, int stepDir) {
    unsigned long start = millis();

    while (millis() - start < duration) {

        // ⬅⬅⬅ TOTO JE KLÍČ
        if (Serial.available()) {
            char c = Serial.read();
            if (c == 'X') {
                programRunning = false;
                stopMotor(pcf, basePin);
                ResetState();
                return;
            }
        }

        if (!programRunning && !manualMode) {
            stopMotor(pcf, basePin);
            return;
        }

        for (int s = 0; s < 8; s++) {

            if (Serial.available()) {
                char c = Serial.read();
                if (c == 'X') {
                    programRunning = false;
                    stopMotor(pcf, basePin);
                    ResetState();
                    return;
                }
            }

            if (!programRunning && !manualMode) {
            stopMotor(pcf, basePin);
            return;
            }

            stepMotor(pcf, basePin, stepDir > 0 ? s : 7 - s);
            delay(5);
        }
    }

    stopMotor(pcf, basePin);
}



// -----------------------------------------------------------
// VÝBĚR MOTORU PODLE STRUNY
// -----------------------------------------------------------
void getMotorForString(int stringIndex, PCF8574* &pcf, int &basePin) {
    switch (stringIndex) {
        case 0: pcf = &pcf1; basePin = 4; break; // G
        case 1: pcf = &pcf2; basePin = 0; break; // C
        case 2: pcf = &pcf1; basePin = 0; break; // E
        case 3: pcf = &pcf2; basePin = 4; break; // A
    }
}

// -----------------------------------------------------------
// AUTOMATICKÁ ÚPRAVA LADĚNÍ
// -----------------------------------------------------------
#define MS_PER_HZ 300

void AdjustString(int stringIndex, double target, double measured) {
    double diff = target - measured;

    PCF8574* pcf;
    int basePin = 0;
    getMotorForString(stringIndex, pcf, basePin);

    int stepDir;
    unsigned long duration;

    if (diff > 0) stepDir = 1; // utáhnout
    else { stepDir = -1; diff = -diff; } // povolit

    if (stringIndex == 0) stepDir = -stepDir; // invert pro G
    if (stringIndex == 1) stepDir = -stepDir;

    duration = (unsigned long)(diff * MS_PER_HZ);

    // ===== ZMĚNA: minimální doba, aby motor opravdu jelo =====
    if (duration < 50) duration = 50; // aspoň pár kroků

    Serial.print("Úprava struny "); Serial.print(stringIndex);
    Serial.print(" o "); Serial.print(diff); Serial.print(" Hz, čas: ");
    Serial.println(duration);
    Serial.print("Krokový směr: "); Serial.println(stepDir);

    runStepper(*pcf, basePin, duration, stepDir); // jen tato funkce
}


// -----------------------------------------------------------
// IMPLEMENTACE NextString
// -----------------------------------------------------------
void NextString() {
    ignoreOnePluck = false;   // jistota – reset

    direction = 1;            // vždy start doprava

    for (int i = 0; i < BUFFER_SIZE; i++) freqBuffer[i] = 0;
    delay(200);

    currentString++;
    if (currentString > 3) {
        currentString = 0;
        allStringsCompleted = true;
        tuningFinished = true;
    }
}


void Home() {
    brnkServo.write(SERVO_RIGHT);
    delay(2000);
    brnkServo.write(SERVO_LEFT);
    delay(2000);
    brnkServo.write(SERVO_STOP);
    delay(2000);
}

void ResetState() {

    // SERVO
    brnkServo.write(SERVO_STOP);

    // Vypni všechny krokáče
    stopMotor(pcf1, 0);
    stopMotor(pcf1, 4);
    stopMotor(pcf2, 0);
    stopMotor(pcf2, 4);

    // Reset proměnných
    direction = 1;
    lastDirectionRight = true;
    ignoreOnePluck = false;
    stringJustFinished = false;
    allStringsCompleted = false;
    tuningFinished = false;
    currentString = 0;

    for (int i = 0; i < BUFFER_SIZE; i++) freqBuffer[i] = 0;

    Home();  // návrat serva
}
void runStepperManual(PCF8574 &pcf, int basePin, int stepDir, int steps = 100) {
    for (int i = 0; i < steps; i++) {

        // --- kontrola STOP přes Serial ---
        if (Serial.available()) {
            char c = Serial.read();
            if (c == 'X') {
                stopMotor(pcf, basePin);
                    // Vypni všechny krokáče
                stopMotor(pcf1, 0);
                stopMotor(pcf1, 4);
                stopMotor(pcf2, 0);
                stopMotor(pcf2, 4);
                currentString = 0;
                return;
            }
        }

        // --- vykonání kroků ---
        for (int s = 0; s < 8; s++) {
            stepMotor(pcf, basePin, stepDir > 0 ? s : 7 - s);
            delay(5); // rychlost kroku
        }
    }

    stopMotor(pcf, basePin);
}


void ManualStep(char stringChar, char dirChar) {

    int stringIndex;

    switch (stringChar) {
        case 'g': stringIndex = 0; break;
        case 'c': stringIndex = 1; break;
        case 'e': stringIndex = 2; break;
        case 'a': stringIndex = 3; break;
        default: return;
    }

    // správně rozeznat + a -
    int stepDir;
    if (dirChar == '-') stepDir = -1;
    else stepDir = 1; // + nebo default

    // inverze pro fyzické zapojení
    if (stringIndex == 0 || stringIndex == 1) stepDir = -stepDir;

    PCF8574* pcf;
    int basePin;
    getMotorForString(stringIndex, pcf, basePin);

    Serial.print("MANUAL ");
    Serial.print(stringChar);
    Serial.print(dirChar);
    Serial.print(" | směr: ");
    Serial.println(stepDir);

    runStepperManual(*pcf, basePin, stepDir, MANUAL_RUN_TIME); // 200 kroků, uprav dle potřeby

}





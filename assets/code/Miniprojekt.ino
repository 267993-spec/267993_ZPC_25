#include "pitches.h"
#define REST 0

const int bzučák = 11;
const int tlacitkoDalsi = 3;
const int tlacitkoPredchozi = 4;
const int tlacitkoPrehrat = 2;
const int ledky[5] = {5, 6, 7, 8, 9};

// ------------ PÍSNIČKY -------------
int melodie1[] = {REST, REST, REST, NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E4, NOTE_DS4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_GS4, NOTE_B4, NOTE_D4, NOTE_F4, NOTE_GS4, NOTE_A4, NOTE_C4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_GS4, NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4, NOTE_E4, REST, NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E4, NOTE_DS4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_GS4, NOTE_B4, NOTE_D4, NOTE_F4, NOTE_GS4, NOTE_A4, NOTE_C4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_GS4, NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4, NOTE_E4};
int delky1[] = {4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 8, 8, 2};

int melodie2[] = {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, REST, REST, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_E5, NOTE_A5, NOTE_GS5, NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, REST, REST, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5, REST, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, REST, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, REST, NOTE_C5, NOTE_A4, NOTE_A4, REST};
int delky2[] = {4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, -4, 8, 4, 4, 4, 4, 4, 4, 8, 4, 8, 4, 8, 8, -4, 8, 4, 8, 8, 4, 8, 8, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 4, 4, 2, 1, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, -4, 8, 4, 4, 4, 4, 4, 4, 8, 4, 8, 4, 8, 8, 8, 4, 8, 4, 8, 8, 8, 4, 8, 4, 4, 8, 4, 8, 4, 4};

int melodie3[] = {REST, NOTE_D4, NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_GS4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_B4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_CS4, NOTE_B4, NOTE_G4, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_AS4, NOTE_D5, NOTE_CS5, NOTE_CS4, NOTE_D4, NOTE_D5, REST, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_F5, NOTE_E5, NOTE_DS5, NOTE_B4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_CS4, NOTE_AS4, NOTE_G4};
int delky3[] = {2, 4, -4, 8, 4, 2, 4, -2, -2, -4, 8, 4, 2, 4, -1, 4, -4, 8, 4, 2, 4, 2, 4, 2, 4, -4, 8, 4, 2, 4, -1, 4, 2, 4, 2, 4, 2, 4, 2, 4, -4, 8, 4, 2, 4, -1, 4, 4, 2, 4, 2, 4, 2, 4, -4, 8, 4, 2, 4, -1};

int melodie4[] = {NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, REST, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, REST, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_DS5, NOTE_D5, NOTE_DS5, REST, NOTE_A4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_C5, REST, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_DS5, NOTE_D5, NOTE_DS5, REST, NOTE_A4, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_C5, REST, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4};
int delky4[] = {-4, -4, 16, 16, 16, 16, 8, 8, -4, -4, 16, 16, 16, 16, 8, 8, 4, 4, 4, -8, 16, 4, -8, 16, 2, 4, 4, 4, -8, 16, 4, -8, 16, 2, 4, -8, 16, 4, -8, 16, 16, 16, 16, 8, 8, 8, 4, -8, 16, 4, -8, 16, 2, 4, -8, 16, 4, -8, 16, 16, 16, 16, 8, 8, 8, 4, -8, 16, 4, -8, 16, 2};

int melodie5[] = {NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, REST, NOTE_AS4, NOTE_B4, NOTE_B4, NOTE_AS4, NOTE_B4, NOTE_A4, REST, NOTE_GS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, REST, NOTE_AS4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, REST, NOTE_AS4, NOTE_B4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_B4, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_AS4, NOTE_AS4, NOTE_B4, NOTE_G4};
int delky5[] = {-4, -4, -4, -4, 8, -4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, -2, -4, -4, -4, -4, 8, -4, 8, 8, 8, 8, -4, -4, 8, -4, 8, -4, -4, -4, -4, -4, -4, -4, -4, 8, -4, 8, 8, 8, 8, 4, -4, 8, -4, -4, -2, 2, 2, 2, 2, -4, -4, 8, 8, 4, 4};


int* vsechnyMelodie[] = {melodie1, melodie2, melodie3, melodie4, melodie5};
int* vsechnyDelky[] = {delky1, delky2, delky3, delky4, delky5};
int delkyMelodii[] = {
  sizeof(melodie1)/sizeof(int),
  sizeof(melodie2)/sizeof(int),
  sizeof(melodie3)/sizeof(int),
  sizeof(melodie4)/sizeof(int),
  sizeof(melodie5)/sizeof(int)
};

// ---------- STAV ----------
int aktualniPisnicka = 0;
bool prehravaSe = false;
int aktualniNota = 0;
unsigned long casZacatkuNoty = 0;

bool posledniPrehrat = HIGH;
bool posledniDalsi = HIGH;
bool posledniPredchozi = HIGH;

int tempo = 120;

// ---------- FUNKCE ----------
int delkaNoty(int hodnota){
  int celaNota = (60000 * 4) / tempo;
  if (hodnota > 0) return celaNota / hodnota;
  else return celaNota / abs(hodnota) * 1.5;
}

void nastavitLEDky(){
  for(int i = 0; i < 5; i++){
    digitalWrite(ledky[i], i == aktualniPisnicka ? HIGH : LOW);
  }
}

void prehratNotu(){
  int* melodie = vsechnyMelodie[aktualniPisnicka];
  int* delky = vsechnyDelky[aktualniPisnicka];
  int delka = delkyMelodii[aktualniPisnicka];

  if(aktualniNota >= delka) aktualniNota = 0;

  unsigned long ted = millis();
  int trvani = delkaNoty(delky[aktualniNota]);

  if(ted - casZacatkuNoty >= trvani){
    aktualniNota++;
    casZacatkuNoty = ted;
    if(aktualniNota < delka){
      if(melodie[aktualniNota] == PAUZA) noTone(bzučák);
      else tone(bzučák, melodie[aktualniNota]);
    }
  }
}

void setup() {
  pinMode(bzučák, OUTPUT);
  pinMode(tlacitkoDalsi, INPUT_PULLUP);
  pinMode(tlacitkoPredchozi, INPUT_PULLUP);
  pinMode(tlacitkoPrehrat, INPUT_PULLUP);
  for(int i = 0; i < 5; i++) pinMode(ledky[i], OUTPUT);
  nastavitLEDky();
}

void loop() {
  bool prehratNow = digitalRead(tlacitkoPrehrat);
  bool dalsiNow = digitalRead(tlacitkoDalsi);
  bool predchoziNow = digitalRead(tlacitkoPredchozi);

  if(posledniPrehrat == HIGH && prehratNow == LOW) prehravaSe = !prehravaSe;
  posledniPrehrat = prehratNow;

  if(posledniDalsi == HIGH && dalsiNow == LOW){
    aktualniPisnicka = (aktualniPisnicka + 1) % 5;
    aktualniNota = 0;
    nastavitLEDky();
  }
  posledniDalsi = dalsiNow;

  if(posledniPredchozi == HIGH && predchoziNow == LOW){
    aktualniPisnicka = (aktualniPisnicka == 0) ? 4 : aktualniPisnicka - 1;
    aktualniNota = 0;
    nastavitLEDky();
  }
  posledniPredchozi = predchoziNow;

  if(prehravaSe) prehratNotu();
  else noTone(bzučák);
}
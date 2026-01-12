#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

String webpage = R"=====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto;
    text-align: center;
    background: #f5f5f7;
    margin: 0;
    padding: 20px;
}
.button {
    padding: 18px 30px;
    margin: 15px;
    border-radius: 14px;
    font-size: 20px;
    border: none;
    box-shadow: 0 6px 18px rgba(0,0,0,0.1);
    cursor: pointer;
}
.blue { background:#007aff; color:white; }
.green { background:#34c759; color:white; }
.red { background:#ff3b30; color:white; }
.circle {
    width: 60px; height: 60px;
    border-radius: 50%;
    display:flex;
    align-items:center;
    justify-content:center;
    font-size:32px;
    background:#d1d1d6;
    margin: 10px;
    cursor:pointer;
}
.string-text {
    font-size: 48px;
    margin: 20px;
}
.data {
    background:white;
    padding:20px;
    border-radius:16px;
    margin-top:20px;
    font-family: monospace;
}
.strings-manual {
    display: flex;
    justify-content: space-around;
    margin-top: 30px;
}
.col {
    display: flex;
    flex-direction: column;
    align-items: center;
}
.stop {
    margin-top: 20px;
    background: #ff3b30;
    color: white;
    padding: 15px;
    font-size: 24px;
    border-radius: 20px;
    cursor: pointer;
}
</style>
</head>
<body>

<h2>Auto Ukulele Tuner</h2>

<!-- Původní tlačítka -->
<button class="button blue" onclick="sendCmd('K')">Calibration</button><br>
<button class="button green" onclick="sendCmd('S')">Start Tuning</button><br>

<!-- Přejmenovaný červený STOP na Stop Tuning -->
<button class="button red" onclick="sendCmd('X')">Stop Tuning</button>

<!-- NOVÁ TLAČÍTKA PRO MANUÁLNÍ KROKOVÉ MOTORY -->
<h2>Manual Stepper Control</h2>
<div class="strings-manual">
  <div class="col">
    <div class="circle" onclick="sendManual('g','+')">+</div>
    <div class="string-text">G</div>
    <div class="circle" onclick="sendManual('g','-')">-</div>
  </div>
  <div class="col">
    <div class="circle" onclick="sendManual('c','+')">+</div>
    <div class="string-text">C</div>
    <div class="circle" onclick="sendManual('c','-')">-</div>
  </div>
  <div class="col">
    <div class="circle" onclick="sendManual('e','+')">+</div>
    <div class="string-text">E</div>
    <div class="circle" onclick="sendManual('e','-')">-</div>
  </div>
  <div class="col">
    <div class="circle" onclick="sendManual('a','+')">+</div>
    <div class="string-text">A</div>
    <div class="circle" onclick="sendManual('a','-')">-</div>
  </div>
</div>

<!-- STOP tlačítko pro manuální krokové motory -->
<div class="stop" onclick="sendStopper()">STOP</div>

<div id="data" class="data">No data yet…</div>

<script>
function sendCmd(cmd){
    fetch("/cmd?c=" + cmd);
}

// Odeslání manuálního kroku do Arduina
function sendManual(s, d){
    fetch("/cmd?s=" + s + "&d=" + d);
}

// STOP tlačítko pro manuální krokové motory
function sendStopper(){
    fetch("/cmd?x=1");
}

setInterval(()=>{
  fetch("/log").then(r=>r.text())
  .then(t=> document.getElementById("data").innerText = t);
}, 300);
</script>

</body>
</html>
)=====";

String lastLog = "Ready";

void setup() {
  Serial.begin(9600);

  WiFi.softAP("Ukulele_Tuner", "12345678");

  server.on("/", [](){
    server.send(200, "text/html", webpage);
  });

  server.on("/cmd", [](){
    if (server.hasArg("x")) {        // STOP manuální
      Serial.write('X');
      lastLog = "STOP";
    }
    else if (server.hasArg("s") && server.hasArg("d")) { // manuální krok
      char s = server.arg("s")[0]; // g c e a
      char d = server.arg("d")[0]; // + -
      Serial.write(s);
      Serial.write(d);
      lastLog = String("Sent: ") + s + d;
    }
    else if (server.hasArg("c")) {  // původní tlačítka
      char c = server.arg("c")[0];
      Serial.write(c);
      lastLog = String("Sent: ") + c;
    }
    server.send(200, "text/plain", "OK");
  });

  server.on("/log", [](){
    server.send(200, "text/plain", lastLog);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}

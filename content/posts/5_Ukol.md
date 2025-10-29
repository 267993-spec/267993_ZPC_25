+++
date = '2025-09-22T20:24:11+02:00'
draft = false
title = '5. Úkol'
tags = [
    "Arduino",
    "Elektro",
]
+++

<div style="max-width: 900px; margin: 0 auto; text-align: justify;">

  <h2 style="font-size: 2rem; font-weight: 700; margin-bottom: 1.5rem; color: #ffffff;">Elektronický obvod s mikrokontrolérem</h2>
  
  <p>
  V rámci miniprojektu z elektrotechniky jsem vytvořil jednoduchý <strong>MP3 přehrávač s Arduinem Uno</strong> a bzučákem. Projekt přehrává pět známých melodií: 
   <em>The Godfather</em>, <em>Star Wars</em>, <em>Tetris</em>, <em>Cantina Band</em> a <em>Harry Potter</em>. 
  Vše je zapojeno přes <strong>breadboard</strong>, který propojuje tři tlačítka a pět LED diod pro signalizaci.
  </p>

  <h2>Ovládání</h2>
  <ul>
    <li><strong>Tlačítko 1</strong> – přehrát / pozastavit aktuální písničku,</li>
    <li><strong>Tlačítko 2</strong> – přepnout na další skladbu,</li>
    <li><strong>Tlačítko 3</strong> – přepnout na předchozí skladbu.</li>
  </ul>

  <p>
  K Arduino Unu je připojeno <strong>pět modrých LED diod</strong> (piny 5–9) s odpory o hodnotě <strong>510 Ω</strong> (<em>zelená, hnědá, červená, zlatá</em>), 
  které ukazují, která písnička je právě zvolena.
  </p>

  <h2>Popis programu</h2>

  <p>
  Kód byl napsán v prostředí <strong>Arduino IDE</strong> v jazyce C++. Program využívá pole, ve kterých jsou uloženy jednotlivé melodie a jejich délky. 
  Pomocí funkce <code>tone()</code> se na bzučáku (v mém případě pin 11) generují tóny o různé frekvenci. 
  Každá melodie je přehrávána v cyklu a uživatel může pomocí tlačítek přepínat mezi skladbami nebo přehrávání pozastavit.
  </p>

  <p>
  Program využívá princip neblokujícího přehrávání – každá nota má svůj čas trvání a Arduino během toho stále reaguje na stisk tlačítek. 
  LEDky se rozsvítí podle vybrané písničky a funkce <code>nastavitLEDky()</code> zajistí, že vždy svítí pouze ta správná.
  </p>

  <h2>Popis logických funkcí a podmínek v Arduino kódu</h2>

  <p>
  Tento program ovládá jednoduchý MP3 přehrávač založený na Arduinu. Pomocí tří tlačítek, pěti LED diod a bzučáku umožňuje přehrávat různé melodie. 
  Kód je napsán tak, aby běžel neblokujícím způsobem – používá časovač <code>millis()</code> místo <code>delay()</code>, takže může reagovat na stisk tlačítek i během přehrávání.
  </p>

  <h3>Hlavní proměnné</h3>

  <pre><code>const int bzučák = 11;
const int tlacitkoDalsi = 3;
const int tlacitkoPredchozi = 4;
const int tlacitkoPrehrat = 2;
const int ledky[5] = {5, 6, 7, 8, 9};</code></pre>

  <p>
  Piny jsou nastaveny tak, aby tlačítka fungovala s interním pull-up rezistorem (<code>INPUT_PULLUP</code>), 
  takže logická nula (LOW) znamená stisk.
  </p>

  <h3>Funkce <code>delkaNoty()</code></h3>

  <pre><code>if (hodnota > 0) return celaNota / hodnota;
else return celaNota / abs(hodnota) * 1.5;</code></pre>

  <ul>
    <li>Pokud je hodnota kladná, jde o běžnou notu.</li>
    <li>Pokud je záporná, jedná se o tečkovanou notu (prodlouženou o polovinu).</li>
  </ul>

  <h3>Funkce <code>nastavitLEDky()</code></h3>

  <pre><code>for (int i = 0; i < 5; i++) {
  digitalWrite(ledky[i], i == aktualniPisnicka ? HIGH : LOW);
}</code></pre>

  <p>Ternární operátor <code>? :</code> zajišťuje, že svítí právě ta LED, která odpovídá aktuální skladbě.</p>

  <h3>Funkce <code>prehratNotu()</code></h3>

  <pre><code>if (aktualniNota >= delka) aktualniNota = 0;
if (ted - casZacatkuNoty >= trvani) {
  aktualniNota++;
  casZacatkuNoty = ted;
  if (melodie[aktualniNota] == PAUZA) noTone(bzučák);
  else tone(bzučák, melodie[aktualniNota]);
}</code></pre>

  <ul>
    <li>První <code>if</code> zajišťuje návrat na začátek po konci melodie.</li>
    <li>Druhý sleduje, zda uplynul čas noty – pokud ano, posune se na další.</li>
    <li>Vnořený <code>if</code> vypne tón při pauze nebo přehraje další frekvenci.</li>
  </ul>

  <h3>Reakce na tlačítka</h3>

  <h4>Play / Pause</h4>
  <pre><code>if (posledniPrehrat == HIGH && prehratNow == LOW)
  prehravaSe = !prehravaSe;</code></pre>

  <h4>Další písnička</h4>
  <pre><code>if (posledniDalsi == HIGH && dalsiNow == LOW) {
  aktualniPisnicka = (aktualniPisnicka + 1) % 5;
  aktualniNota = 0;
  nastavitLEDky();
}</code></pre>

  <h4>Předchozí písnička</h4>
  <pre><code>if (posledniPredchozi == HIGH && predchoziNow == LOW) {
  aktualniPisnicka = (aktualniPisnicka == 0) ? 4 : aktualniPisnicka - 1;
  aktualniNota = 0;
  nastavitLEDky();
}</code></pre>

  <h4>Přehrávání / Pauza</h4>
  <pre><code>if (prehravaSe) prehratNotu();
else noTone(bzučák);</code></pre>

  <h3>Souhrn logických funkcí</h3>

  <table style="width:100%; border-collapse:collapse; text-align:left;" border="1" cellpadding="5">
    <tr><th>Podmínka / Funkce</th><th>Účel</th><th>Popis logiky</th></tr>
    <tr><td><code>if (hodnota > 0)</code></td><td>Délka noty</td><td>Rozlišuje běžnou a tečkovanou notu</td></tr>
    <tr><td><code>if (aktualniNota >= delka)</code></td><td>Přehrávání</td><td>Vrací se na začátek melodie</td></tr>
    <tr><td><code>if (ted - casZacatkuNoty >= trvani)</code></td><td>Časování not</td><td>Určuje, kdy přejít na další tón</td></tr>
    <tr><td><code>if (melodie[aktualniNota] == PAUZA)</code></td><td>Zvuk</td><td>Přehraje ticho místo tónu</td></tr>
    <tr><td><code>if (posledniPrehrat == HIGH && prehratNow == LOW)</code></td><td>Tlačítko PLAY</td><td>Přepínání přehrávání / pauzy</td></tr>
    <tr><td><code>if (posledniDalsi == HIGH && dalsiNow == LOW)</code></td><td>Tlačítko NEXT</td><td>Přechod na další skladbu</td></tr>
    <tr><td><code>if (posledniPredchozi == HIGH && predchoziNow == LOW)</code></td><td>Tlačítko BACK</td><td>Přechod na předchozí skladbu</td></tr>
    <tr><td><code>if (prehravaSe)</code></td><td>Hlavní stav</td><td>Rozhoduje, zda se přehrává, nebo ne</td></tr>
  </table>

  <div style="text-align: center; margin-top: 2rem;">
    <div style="display: inline-block; margin: 10px;">
      <img src="/267993_ZPC_25/images/Obvod1.jpg" alt="Náhled obvodu" style="width: 100%; max-width: 600px; border-radius: 10px;">
      <p style="transform: skewX(-10deg);">Obr. 1 Sestava MP3 obvodu z vrchu</p>
    </div>

<div style="display: inline-block; margin: 10px;">
      <img src="/267993_ZPC_25/images/Obvod2.jpg" alt="Pohled zepředu" style="width: 100%; max-width: 600px; border-radius: 10px;">
      <p style="transform: skewX(-10deg);">Obr. 2 MP3 obvod zepředu</p>
    </div>

<div style="display: inline-block; margin: 10px;">
      <video controls muted style="width: 100%; max-width: 600px; border-radius: 10px;">
        <source src="/267993_ZPC_25/videos/VideoObvodu.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
      </video>
      <p style="transform: skewX(-10deg);">Video 1 Ukázka funkčnosti MP3 obvodu</p>
    </div>
  </div>
</div>

<div style="max-width: 800px; margin: 2rem auto; text-align:left;">
  {{< codewindow file="assets/code/Miniprojekt.ino" >}}
</div>

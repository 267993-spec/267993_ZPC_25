+++
date = '2025-09-22T20:24:11+02:00'
draft = false
title = '4. Úkol'
tags = [
    "Skener",
    "Reversengineering",
]
+++
# 4. Úkol
<div style="flex: 1 1 50%; min-width: 260px; text-align: justify;">
  <h2>Skenerování 3D vytištěné židle</h2>

  <p style="text-align: justify;">
    Pro tento experiment jsem použil laserový skener <em>Simscam</em> k digitalizaci 3D vytištěné židle. Povrch před skenováním jsem nepřipravil, protože nebyl příliš lesklý a sken probíhal spolehlivě i bez matování.
  </p>

  <p style="text-align: justify;">
    Pro zajištění přesného zarovnání a registrování skenů jsem na židli přilepil lokalizační body (tečky) a kolem objektu rozložil kontrolní kostičky (reference). Následně jsem v softwaru skeneru nastavil rozlišení a expoziční čas: <strong>rozlišení: 1 mm</strong> a <strong>expoziční čas: 1 ms</strong>. Tyto dvě hodnoty byly klíčové pro dosažení vyvážené kvality záznamu a rychlosti snímání.
  </p>

  <p style="text-align: justify;">
    Po dokončení skenování jsem data exportoval ve formátu <code>.stl</code> a otevřel je v programu <em>GOM Inspect</em> pro další zpracování. V GOM jsem:
    <ul>
      <li>odstranil díry způsobené nalepenými tečkami,</li>
      <li>upravil a vyčistil mesh (redukoval šum, doplnil chybějící plochy),</li>
      <li>provedl kontrolu integrity sítě a optimalizaci trojúhelníků pro přesné měření.</li>
    </ul>
  </p>

  <p style="text-align: justify;">
    Nakonec jsem v GOM Inspect změřil několik klíčových parametrů: <strong>největší rozměr</strong> modelu, <strong>libovolný zvolený rozměr</strong> (pro kontrolu přesnosti tisku) a <strong>obsah povrchu</strong>. Tato měření potvrdila věrohodnost digitalizace a umožnila porovnat výsledný STL soubor s původním CAD modelem a skutečným tiskem.
  </p>
    </div>
<div style="text-align: center;">
    <div style="display: inline-block; margin: 10px;">
        <img src="/267993_ZPC_25/images/Zidlepriprava.jpg" alt="Nacrt" style="width: 100%; max-width: 600px; display: block; margin: 0 auto;">
        <p style="transform: skewX(-10deg);">Obr. 1 Židle připravená na skenování</p>
    <div style="display: inline-block; margin: 10px;">
        <img src="/267993_ZPC_25/images/Rozliseni.jpg" alt="Samolepka" style="width: 100%; max-width: 600px; display: block; margin: 0 auto;">
        <p style="transform: skewX(-10deg);">Obr. 2 Rozlišení a expozice</p>
    <div style="display: inline-block; margin: 10px;">
        <img src="/267993_ZPC_25/images/Neupraveny.png" alt="Samolepka" style="width: 100%; max-width: 600px; display: block; margin: 0 auto;">
        <p style="transform: skewX(-10deg);">Obr. 3 Neupravený díl</p>
    <div style="display: inline-block; margin: 10px;">
        <img src="/267993_ZPC_25/images/Upraveny.png" alt="Samolepka" style="width: 100%; max-width: 600px; display: block; margin: 0 auto;">
        <p style="transform: skewX(-10deg);">Obr. 4 Upravený díl</p>
    <div style="display: inline-block; margin: 10px;">
        <img src="/267993_ZPC_25/images/Rozmery.png" alt="Samolepka" style="width: 100%; max-width: 600px; display: block; margin: 0 auto;">
        <p style="transform: skewX(-10deg);">Obr. 5 Rozměry a povrch</p>
<div style="display: inline-block; margin: 10px;">

</div>
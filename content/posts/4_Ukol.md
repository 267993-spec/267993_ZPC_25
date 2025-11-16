+++
date = '2025-09-22T20:24:11+02:00'
draft = false
title = '4. Úkol'
tags = [
    "Skener",
    "Reversengineering",
]
+++

<div style="max-width: 900px; margin: 0 auto; text-align: justify; line-height: 1.7;">

<h2 style="font-size: 2rem; font-weight: 700; margin-bottom: 1.5rem; color: #ffffff;">
  Skenerování 3D vytištěné židle
</h2>

<p>
Pro tento úkol jsem použil laserový skener <em>Simscam</em> k digitalizaci 3D vytištěné židle. 
Povrch před skenováním jsem nepřipravil, protože nebyl příliš lesklý a sken probíhal spolehlivě i bez matování.
</p>

<p>
Pro zajištění přesného zarovnání a registrování skenů jsem na židli přilepil lokalizační body (tečky) a kolem objektu rozložil kontrolní kostičky (reference). 
Následně jsem v softwaru skeneru nastavil rozlišení a expoziční čas: 
<strong>rozlišení 1 mm</strong> a <strong>expoziční čas 1 ms</strong>. 
Tyto dvě hodnoty byly klíčové pro dosažení vyvážené kvality záznamu a rychlosti snímání.
</p>

<p>
Po dokončení skenování jsem data exportoval ve formátu <code>.stl</code> a otevřel je v programu <em>GOM Inspect</em> pro další zpracování. 
V GOM jsem provedl následující kroky:
</p>

<ul style="margin-left: 20px;">
  <li>odstranil díry způsobené nalepenými tečkami,</li>
  <li>upravil a vyčistil mesh (redukoval šum, doplnil chybějící plochy),</li>
  <li>provedl kontrolu integrity sítě a optimalizaci trojúhelníků pro přesné měření.</li>
</ul>

<p>
Nakonec jsem v GOM Inspect změřil několik klíčových parametrů: 
<strong>největší rozměr</strong> modelu, <strong>libovolný zvolený rozměr</strong> (pro kontrolu přesnosti tisku) 
a <strong>obsah povrchu</strong>. Tato měření potvrdila věrohodnost digitalizace 
a umožnila porovnat výsledný STL soubor s původním CAD modelem a skutečným tiskem.
</p>

<div style="text-align: center; margin-top: 2rem;">

  <div style="display: inline-block; margin: 15px;">
    <img src="/267993_ZPC_25/images/Zidlepriprava.jpg" alt="Židle připravená na skenování" style="width: 100%; max-width: 600px; border-radius: 10px; display: block; margin: 0 auto;">
    <p style="transform: skewX(-10deg);">Obr. 1 – Židle připravená na skenování</p>
  </div>

  <div style="display: inline-block; margin: 15px;">
    <img src="/267993_ZPC_25/images/Rozliseni.jpg" alt="Rozlišení a expozice" style="width: 100%; max-width: 600px; border-radius: 10px; display: block; margin: 0 auto;">
    <p style="transform: skewX(-10deg);">Obr. 2 – Rozlišení a expozice</p>
  </div>

  <div style="display: inline-block; margin: 15px;">
    <img src="/267993_ZPC_25/images/Neupraveny.png" alt="Neupravený model po skenování" style="width: 100%; max-width: 600px; border-radius: 10px; display: block; margin: 0 auto;">
    <p style="transform: skewX(-10deg);">Obr. 3 – Neupravený model po skenování</p>
  </div>

  <div style="display: inline-block; margin: 15px;">
    <img src="/267993_ZPC_25/images/Upraveny.png" alt="Upravený model" style="width: 100%; max-width: 600px; border-radius: 10px; display: block; margin: 0 auto;">
    <p style="transform: skewX(-10deg);">Obr. 4 – Upravený model po čištění</p>
  </div>

  <div style="display: inline-block; margin: 15px;">
    <img src="/267993_ZPC_25/images/Rozmery.png" alt="Rozměry a povrch" style="width: 100%; max-width: 600px; border-radius: 10px; display: block; margin: 0 auto;">
    <p style="transform: skewX(-10deg);">Obr. 5 – Analýza rozměrů a povrchu</p>
  </div>

</div>

<p>
Celý proces skenování a následné úpravy mi umožnil pochopit principy <em>reverzního inženýrství</em> 
a význam přesného 3D snímání pro porovnávání fyzických objektů s digitálními modely. 
Tento úkol mi ukázal, jak lze kombinovat 3D tisk a skenování pro efektivní kontrolu kvality a zpětné modelování.
</p>

</div>

+++
date = '2025-09-22T20:24:11+02:00'
draft = false
title = 'Individální projekt'
menu="main"
weight = 25
tags = [
    "Ukulele",
    "Konstrukting",
]
+++
# Samoladící ukulele

<div style="text-align: justify;">

<p style="text-align: justify;">
Cílem projektu je vyrobit prototyp samoladícího elektrického ukulele. Jak je patrné z náčrtu níže, plánem je přesunout celý ladicí mechanismus do těla nástroje a tím zároveň skrýt celý systém samoladění, který bude zakrytý deskami vyřezanými na plotru. Do těla chci také umístit mechanismus pro automatizaci ladění. 

Ten bude tvořit hrot ovládaný krokovým motorem, jehož pohyb bude přenášen přes převod na ozubený hřeben. Hrot přejede přes strunu a tím na ni brnkne. Piezo senzor umístěný v kobylce zaznamená vzniklou frekvenci, signál projde přes buffer do Arduina, které jej vyhodnotí a následně vyšle pokyn příslušnému krokovému motoru. Ten pak otočí ladicím mechanismem a napne konkrétní strunu tak, aby byla správně naladěná. Součástí projektu bude také výstup z Arduina na jack konektor.
</p>
<div style="text-align: center;">
    <img src="/267993_ZPC_25/images/Ukulele_nacrt.png" alt="Nacrt">
    <p style="transform: skewX(-10deg); display:inline-block;">  
    Obr.1 První náčrt prototypu
    </p>
    
</div>
Pokrok ve vývoji – od elektroniky po první prototyp

Po úvodním návrhu a popisu principu samoladícího ukulele jsem se pustil do realizace samotné elektroniky. Základem systému je Arduino, které řídí krokové motory a vyhodnocuje signál z piezo senzoru. Po úspěšném zapojení všech komponent jsem vytvořil první funkční verzi elektroniky – ta dokáže detekovat tón a reagovat na odchylku od správného ladění.

Aby byl nástroj co nejvíce „clean“ a bez zbytečných ovládacích prvků, rozhodl jsem se projekt rozšířit o Wi-Fi modul. Díky tomu lze celé ladění ovládat bezdrátově – například přes webové rozhraní nebo mobilní aplikaci. Tím jsem se vyhnul nutnosti používat fyzická tlačítka a displeje, které by rušily vzhled nástroje.

Dalším krokem bylo navrhnout mechanickou část ukulele. Ve 3D CADu jsem vymodeloval první prototyp těla i krku, abych otestoval vůle, usazení motorů, převodů a senzorů. Model jsem vytiskl na 3D tiskárně a všechny díly zkušebně sestavil. Test potvrdil, že většina rozměrů i uložení dílů sedí, takže jsem mohl pokračovat k prvnímu kompletnímu prototypu.

V další fázi mě čeká testování funkčnosti – konkrétně napínání strun, funkce brnkacího mechanismu a také odolnost a tuhost konstrukce. Tyto testy rozhodnou o tom, jak bude vypadat finální verze a jaké úpravy bude potřeba provést před výrobou estetické verze ukulele.
</div>
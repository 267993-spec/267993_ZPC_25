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
<p style="text-align: justify;">
Cílem projektu je vyrobit prototyp samoladícího elektrického ukulele. Jak je patrné z náčrtu níže, plánem je přesunout celý ladicí mechanismus do těla nástroje a tím zároveň skrýt celý systém samoladění, který bude zakrytý deskami vyřezanými na plotru. Do těla chci také umístit mechanismus pro automatizaci ladění. 

Ten bude tvořit hrot ovládaný krokovým motorem, jehož pohyb bude přenášen přes převod na ozubený hřeben. Hrot přejede přes strunu a tím na ni brnkne. Piezo senzor umístěný v kobylce zaznamená vzniklou frekvenci, signál projde přes buffer do Arduina, které jej vyhodnotí a následně vyšle pokyn příslušnému krokovému motoru. Ten pak otočí ladicím mechanizmem a napne konkrétní strunu tak, aby byla správně naladěná. Součástí projektu bude také výstup z Arduina na jack konektor.
</p>
<div style="text-align: center;">
    <img src="/267993_ZPC_25/images/Ukulele_nacrt.png" alt="Nacrt">
    <p style="transform: skewX(-10deg); display:inline-block;">  
    Obr.1 První náčrt prototypu
    </p>
    
</div>
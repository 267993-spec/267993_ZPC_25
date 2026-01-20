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

<script type="module" src="https://cdn.jsdelivr.net/npm/@google/model-viewer/dist/model-viewer.min.js"></script>



<style>
    /* VĚDECKÝ STYL TEXTU */
    .scientific-paper {
        font-family: "Georgia", "Times New Roman", serif;
        line-height: 1.8;
        color: #1a1a1a;
        text-align: justify;
    }

    /* STYL OBRÁZKU - NÁHLED */
    .img-preview {
        width: 300px;              /* Velikost náhledu */
        border-radius: 12px;       /* ZAOBLENÉ ROHY */
        cursor: pointer;
        transition: 0.3s ease;
        border: 1px solid #ddd;
        display: block;
        margin: 10px auto;
    }
    .img-preview:hover {
        transform: scale(1.03);
        box-shadow: 0 5px 15px rgba(0,0,0,0.2);
    }
    .img-previewl {
        width: 600px;              /* Velikost náhledu */
        border-radius: 12px;       /* ZAOBLENÉ ROHY */
        cursor: pointer;
        transition: 0.3s ease;
        border: 1px solid #ddd;
        display: block;
        margin: 10px auto;
    }
    .img-previewl:hover {
        transform: scale(1.03);
        box-shadow: 0 5px 15px rgba(0,0,0,0.2);
    }

        .img-previewm {
        width: 200px;              /* Velikost náhledu */
        border-radius: 12px;       /* ZAOBLENÉ ROHY */
        cursor: pointer;
        transition: 0.3s ease;
        border: 1px solid #ddd;
        display: block;
        margin: 10px auto;
    }
    .img-previewm:hover {
        transform: scale(1.03);
        box-shadow: 0 5px 15px rgba(0,0,0,0.2);
    }

    /* POP-UP OKNO (MODAL) */
    .modal-overlay {
        display: none;
        position: fixed;
        top: 0; left: 0; width: 100%; height: 100%;
        background: rgba(0,0,0,0.9);
        z-index: 9999;
        align-items: center; justify-content: center;
    }

    .modal-content {
        max-width: 90%;
        max-height: 90%;
        border-radius: 15px;       /* ZAOBLENÉ ROHY VELKÉHO OBRÁZKU */
        border: 2px solid white;
    }

    .img-preview-large {
    max-width: 600px;   /* VĚTŠÍ náhledy jen tady */
}

    .close-x {
        position: absolute;
        top: 20px; right: 30px;
        color: white;
        font-size: 50px;
        font-weight: bold;
        cursor: pointer;
        text-decoration: none;
    }

    .img-row {
    display: flex;
    align-items: center;
    justify-content: center;
    gap: 1.5rem;
}

.arrow {
    font-size: 2.5rem;
    font-weight: bold;
}
</style>


<div style="text-align: justify;">

## 1 Koncept

<p style="text-align: justify;">
Cílem projektu je vyrobit prototyp samoladícího elektrického ukulele. Jak je patrné z náčrtu níže, plánem je přesunout celý ladicí mechanismus do těla nástroje a tím zároveň skrýt celý systém samoladění, který bude zakrytý deskami vyřezanými na plotru. Do těla chci také umístit mechanismus pro automatizaci ladění. 

Ten bude tvořit hrot ovládaný krokovým motorem, jehož pohyb bude přenášen přes převod na ozubený hřeben. Hrot přejede přes strunu a tím na ni brnkne. Piezo senzor umístěný v kobylce zaznamená vzniklou frekvenci, signál projde přes buffer do Arduina, které jej vyhodnotí a následně vyšle pokyn příslušnému krokovému motoru. Ten pak otočí ladicím mechanismem a napne konkrétní strunu tak, aby byla správně naladěná. Součástí projektu bude také výstup z Arduina na jack konektor.
</p>

<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/Ukulele_nacrt.png" 
         class="img-preview" 
         onclick="document.getElementById('popup1').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 1: Náčrt prototypu</p>

  <div id="popup1" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/Ukulele_nacrt.png" class="modal-content">
    </div>
</div>

## 2 Vývoj 

<em>"I cesta dlouhá tisíc mil začíná prvním krokem." </em>

ČÍNSKÉ PŘÍSLOVÍ

<div style="text-align: justify;">

### 2.1 Elektronika a první výzvy

Po úvodním návrhu a popisu principu samoladicího ukulele jsem se pustil do rešerše elektronických komponent a jejich objednání. Primárním cílem nultého prototypu bylo zapojení všech elektronických komponent a jejich vzájemná komunikace s Arduinem. Tuto část projektu jsem chtěl vyřešit co nejdříve, neboť jsem nikdy dříve s Arduinem ani elektronikou nepracoval, a jednalo se tedy o mou největší výzvu.

Hned na počátku jsem narazil na problém s nedostatečným počtem digitálních pinů Arduina pro ovládání čtyř krokových motorů. Tento problém jsem vyřešil použitím dvou rozšiřujících PCF modulů, které jsou ovládány pomocí dvou analogových pinů a poskytují celkem 16 digitálních výstupů, což přesně odpovídalo mým potřebám. Obvod jsem sestavil a použil jsem pouze zkušební kód pro odečítání frekvence z koupeného ukulele. Pomocí tohoto kódu jsem testoval reakci serva a krokových motorů při přechodu ze struny na strunu.

<div style="text-align: center; margin: 15px 0;">
    <video controls muted playsinline preload="metadata" 
           style="width:100%; max-width:400px; height:auto; border-radius:10px; display:block; margin:0 auto;">
        <source src="/267993_ZPC_25/videos/ELETEST.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
    </video>
    <p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 1 – Funkčnost prvního prototypu elektroniky
    </p>
</div>



---

### 2.2 Měření frekvence a volba senzorů

Další problém spočíval v měření frekvence struny. Zvažoval jsem dvě možnosti – odečítání frekvence z piezo senzoru nebo použití mikrofonu. První varianta byla technicky náročnější a přesnější, ale zároveň výrazně dražší, jelikož by vyžadovala kvalitnější senzor. Rozhodl jsem se proto pro řešení pomocí mikrofonu a výstup pro zapojení do zesilovače jsem ponechal zcela nezávislý na obvodu s Arduinem. Zároveň to také přidalo uživateli nezávislost na zesilovači a tak mohlo být ukulele využito také pouze jako akustické. Piezo senzor jsem následně koupil z nižší cenové kategorie, abych rozšířil funkce produktu a zároveň nezvyšoval výrobní náklady.

<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/ELEZAPOJENI.jpg" 
         class="img-preview" 
         onclick="document.getElementById('popup2').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 2: Zapojení piezosenzoru</p>

  <div id="popup2" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/ELEZAPOJENI.jpg" class="modal-content">
    </div>
</div>

---

### 2.3 Bezdrátové ovládání a design elektroniky

Aby byl nástroj co nejvíce čistý („clean“) a bez zbytečných ovládacích prvků, rozhodl jsem se projekt rozšířit o Wi-Fi modul jako možné rozšíření. Díky tomu lze ladění ovládat bezdrátově, například prostřednictvím webového rozhraní nebo mobilní aplikace. Tím jsem se vyhnul nutnosti použití fyzických tlačítek a displejů, které by narušovaly vzhled nástroje. Zároveň jsem se rozhodl propojit pouze komunikaci z wifi modulu do arduina, jelikož jsem odezvu nástroje nepotřeboval.

Níže vidíme nákres celého projektu navržený v prostředí KiCad. Srdcem systému je kombinace mikrokontrolerů Arduino UNO a Wemos D1 mini, což umožňuje propojení klasického řízení s Wi-Fi konektivitou. K efektivnímu využití pinů jsou použity dva I/O expandéry PCF8574AP na I2C sběrnici , které skrze čtveřici řídících jednotek ULN2003 ovládají čtyři krokové motory a jeden servo motor. Součástí schématu je také mikrofon MAX4466 a integrovaný napájecí management s regulátorem LM2596 , který zajišťuje stabilních 5V ze vstupního 12V zdroje.


<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <!-- Náhled SVG na stránce -->
    <div style="display: inline-block; background-color: white; padding: 1rem; border-radius: 15px; box-shadow: 0 8px 20px rgba(0,0,0,0.2); cursor: pointer;" 
         onclick="document.getElementById('svg-popup').style.display='flex'">
        <img src="/267993_ZPC_25/images/SCHEME.svg" 
             style="max-width: 600px; width: 100%; height: auto; display: block; margin: auto;">
    </div>
    <p class="white-text" style="font-style: italic; font-size: 0.9rem; margin-top: 0.5rem;">
    Obr. 3: Schéma zapojení elektrického obvodu
    </p>

  <!-- Modal pro zvětšení -->
  <div id="svg-popup" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <div class="modal-content white-bg">
            <img src="/267993_ZPC_25/images/SCHEME.svg" style="max-width: 90vw; max-height: 90vh; width: auto; height: auto; display: block; margin: auto;">
        </div>
    </div>
</div>

<style>
.modal-overlay {
    display: none;
    position: fixed;
    top: 0; left: 0; width: 100%; height: 100%;
    background: rgba(0,0,0,0.8);
    z-index: 9999;
    align-items: center; 
    justify-content: center;
}

.close-x {
    position: absolute;
    top: 20px; right: 30px;
    color: white;
    font-size: 50px;
    font-weight: bold;
    cursor: pointer;
    text-decoration: none;
}

.modal-content.white-bg {
    background-color: white;
    border-radius: 15px;
    box-shadow: 0 8px 25px rgba(0,0,0,0.3);
    padding: 1rem;
    display: flex;
    justify-content: center;
    align-items: center;
}
</style>
>


<style>
    /* Bílé pozadí pro modal */
    .white-bg {
        background-color: white;
        border-radius: 15px;
        box-shadow: 0 8px 25px rgba(0,0,0,0.3);
        max-width: 90%;
        max-height: 90%;
        padding: 1rem;
        display: flex;
        justify-content: center;
        align-items: center;
    }

    /* Scrollovatelné SVG */
    .svg-scroll {
        max-height: 80vh; /* maximální výška v viewportu */
        overflow-y: auto; /* scroll, pokud je vyšší než viewport */
        width: 100%;
    }
</style>


---

### 2.4 Mechanická konstrukce a první prototyp

Dalším krokem byl návrh mechanické části ukulele. Ve 3D CADu jsem vymodeloval první prototyp těla i krku, abych otestoval vůle, usazení motorů, převodů a senzorů. Model jsem vytiskl na 3D tiskárně a všechny díly zkušebně sestavil. Test potvrdil, že většina rozměrů i uložení dílů je správná, což mi umožnilo pokračovat k prvnímu kompletnímu prototypu.

Problém však nastal u krku, který nebyl ve vodorovné poloze. Přešel jsem proto k druhé iteraci, ve které jsem přemodeloval celé tělo. Změnil jsem úhel napojení krku o 15° vůči horní ploše těla, čímž se podařilo tento problém eliminovat. Další úpravou byla výměna piezo senzorů přilepených pod deskou těla za piezo senzor umístěný přímo pod kobylkou, což výrazně ušetřilo místo.

<model-viewer 
    src="/267993_ZPC_25/images/Ukulele.glb"
    alt="3D model sestavy"
    auto-rotate
    camera-controls
    ar
    style="
        width:100%;
        max-width:700px;
        height:420px;
        margin: 2rem auto;
        display: block;
        background-color: #355f8f;
        border-radius: 20px;
        box-shadow: 0 10px 30px rgba(0,0,0,0.3);
        overflow: hidden;
      ">
</model-viewer>


<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/Ukulelecele.png" 
         class="img-previewl" 
         onclick="document.getElementById('popup3').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 4: Model ELEUKO v Inventoru</p>

  <div id="popup3" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/Ukulelecele.png" class="modal-content">
    </div>
</div>

<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/Ukulelemech.png" 
         class="img-previewl" 
         onclick="document.getElementById('popup4').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 5: Řez mechanismem brnkání</p>

  <div id="popup4" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/Ukulelemech.png" class="modal-content">
    </div>
</div>

<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/Ukuleleout.png" 
         class="img-previewl" 
         onclick="document.getElementById('popup5').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 6: Řez tělem ELEUKA</p>

  <div id="popup5" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/Ukuleleout.png" class="modal-content">
    </div>
</div>


---

### 2.5 Iterace konstrukce a testování hry

Do stavu funkčního prototypu z hlediska samotného hraní jsem se dostal po dalších dvou iteracích, přičemž třetí verze již umožňovala testování hry i mechanismů ladění. Do těla jsem nainstaloval ladicí kolíky, které jsem zaaretoval šrouby. Ty sloužily jak k upevnění ozubených kol na ladicí kolíky, tak k vyvození tření předepnutím, aby nedocházelo k samovolnému povolování strun.

Ukulele jsem ručně naladil a otestoval jeho základní funkčnost. Jak je vidět i slyšet na videu níže, nástroj hraje poměrně čistě a překvapivě se mi na něj hrálo velmi dobře. Je však patrné, že ukulele je poměrně tiché, což jsem předpokládal, a proto jsem přidal piezo senzor pod kobylku.

<div style="text-align: center; margin: 15px 0;">
    <video controls muted playsinline preload="metadata" 
           style="width:100%; max-width:600px; height:auto; border-radius:10px; display:block; margin:0 auto;">
        <source src="/267993_ZPC_25/videos/HRANI.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
    </video>
    <p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 2 – První test akustickým hraním
    </p>
</div>

---

### 2.6 Napínání strun a ladicí mechanismus

Další testování se zaměřilo na samotné napínání strun. Ukázalo se, že pro dosažení správné frekvence je zapotřebí poměrně velký utahovací moment. Původně jsem používal motory typu BYJ-48 5V, které jsem dále převodoval ozubenými koly v poměru 2:1. Tato konfigurace však nebyla dostatečná ani pro napnutí struny A, natož struny E, která je z hlediska potřebného momentu nejnáročnější.

Postupně jsem proto iteroval převodový poměr a zakoupil silnější motory BYJ-48 s napětím 12V. Po pěti dalších iteracích se mi podařilo dosáhnout dostatečného momentu i pro strunu E. Finální konfigurace tedy byla motor BYJ-48 12V s převodem 6:1.

<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/KOLECKA.jpg" 
         class="img-previewl" 
         onclick="document.getElementById('popup6').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 7: Původní iterace převodů</p>

  <div id="popup6" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/KOLECKA.jpg" class="modal-content">
    </div>
</div>

---

### 2.7 Brnkací mechanismus

Testování brnkacího mechanismu přineslo další výzvy. Původně jsem plánoval použití klasického serva s rozsahem 180°, avšak tento rozsah nebyl dostatečný. Kvůli převodu z pastorku na hřeben jsem potřeboval lineární rozsah přibližně 60 mm, což by vyžadovalo příliš velký pastorek. Z tohoto důvodu jsem zvolil kontinuální servo, které bylo nutné ovládat odlišným způsobem.

Samotný brnkací mechanismus vyžadoval další čtyři iterace, během nichž jsem ladil parametry trsátka, aby bylo dosaženo dostatečně hlasitého zvuku. Dalším problémem byla změna vzdálenosti strun od těla při jejich napínání. Tento problém jsem vyřešil seřízením krku pomocí šroubu před samotným laděním a přidáním funkce kalibrace.

<div style="text-align: center; margin: 15px 0;">
    <video controls muted playsinline preload="metadata" 
           style="width:100%; max-width:600px; height:auto; border-radius:10px; display:block; margin:0 auto;">
        <source src="/267993_ZPC_25/videos/BRNKANI.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
    </video>
    <p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 3 – Test brnkání utahování struny 
    </p>
</div>

---

### 2.8 Software a algoritmus ladění

Po úspěšném otestování mechaniky následovalo propojení hardwaru se softwarem. Největší výzvou bylo spolehlivé rozpoznání frekvence struny. Kvůli omezené dynamické paměti Arduina bylo obtížné získat korektní výsledky. Použil jsem mikrofon MAX4466 umístěný v blízkosti brnkacího mechanismu. Signál byl zpracováván pomocí rychlé Fourierovy transformace (FFT), ze které byla určena frekvence.

Poté, co mi začaly vycházet rozumné výsledky, jsem přešel na zpracování dat. Mikrofon byl naprogramován tak, aby měřil pouze po omezený čas. Z tohoto měřicího okna jsem získal stovky výsledků, ze kterých jsem odfiltroval hodnoty nad 700 Hz a pod 150 Hz, jelikož se jednalo o šum ze serva nebo okolního prostředí.

Dále jsem z tohoto datového souboru vybral hodnoty, které si byly blízké jak v čase, tak v hodnotě, konkrétně v toleranci ±1 Hz. Aby bylo měření považováno za platné, muselo se takových hodnot vyskytovat alespoň pět. Tyto platné hodnoty jsem následně zprůměroval a Arduino tak za jedno měřicí okno vyhodnotilo jeden výsledný údaj frekvence. Ten byl porovnán s požadovanou hodnotou a jejich rozdíl byl přepočítán na absolutní hodnotu, která sloužila k výpočtu času dotahování struny. Všechny ostatní případy systém vyhodnotil jako nulové.

<div style="text-align: center; margin: 15px 0;">
    <video controls muted playsinline preload="metadata" 
           style="width:100%; max-width:600px; height:auto; border-radius:10px; display:block; margin:0 auto;">
        <source src="/267993_ZPC_25/videos/MIKROFON.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
    </video>
    <p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 4 – Test brnkání a odečítání frekvence
    </p>
</div>


---

### 2.9 Automatizované ladění a finální testy

Následovalo přizpůsobení logiky pro automatizované ladění. Jelikož jsem pro brnkání používal kontinuální servo bez enkodéru, bylo nutné tomu uzpůsobit algoritmus. Servo z výchozí polohy Home krokovalo doprava. Jeden krok spočíval v otočení serva po dobu 300 ms, přičemž měřicí okno pro zaznamenávání frekvence se spustilo po 50 ms a trvalo 2 s od počátku otáčení serva. Tento časový posun sloužil k lepšímu potlačení šumu, který servo během pohybu emitovalo.

Pokud se během měřicího okna nezaznamenala nenulová frekvence, servo pokračovalo dalším krokem stejným směrem. V opačném případě se otočil krokový motor příslušné struny, určené podle počítadla strun. Struna se tímto krokem částečně naladila, avšak nebylo známo, do jaké míry. Krokování pro doladění stejné struny proto muselo pokračovat. Krok následující po pohybu krokového motoru byl vždy proveden opačným směrem. Tento algoritmus se opakoval, dokud nebyla naměřena frekvence v toleranci ±0.5 Hz od požadované hodnoty.

Jakmile došlo k naměření správné frekvence, následoval přesun na další strunu. Zde mohly nastat dvě situace. Pokud byl poslední krok proveden doprava, krokování pokračovalo stejným směrem, dokud nezazněla další struna. Pokud byl poslední krok proveden doleva, změnil se směr krokování a jedno nenulové měřicí okno bylo ignorováno.

V momentě, kdy se počítadlo dostalo až na strunu A, přejelo servo třikrát z krajní do krajní polohy. Tím zazněly všechny struny a uživatel byl informován o ukončení ladicí sekvence. Poté se algoritmus přerušil a brnkací mechanismus setrval v poloze Home, tedy vlevo od struny G.

Díky těmto úpravám se mi podařilo provést první úspěšný test, při kterém celý algoritmus proběhl bez chyby a zvládl naladit všechny struny. Celý proces, od rozladěného ukulele po kompletní doladění, trval přibližně dvě minuty. Objevovaly se však i chyby vedoucí k nenaměření frekvence. Tyto chyby se sice vyskytovaly poměrně zřídka, avšak v případě jejich výskytu narušily celý průběh algoritmu a bylo nutné jej restartovat. Jednalo se přesto o velmi důležitý test, který potvrdil funkčnost celého konceptu a umožnil jeho další rozvoj.

<div style="text-align: center; margin: 15px 0;">
    <video controls muted playsinline preload="metadata" 
           style="width:100%; max-width:600px; height:auto; border-radius:10px; display:block; margin:0 auto;">
        <source src="/267993_ZPC_25/videos/1_FUNKCNI.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
    </video>
    <p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 5 – První úspěšný test automatizovaného ladění
    </p>
</div>


---

### 2.10 Tělo a wifi modul

Pro zakrytování těla jsem se rozhodl vymodelovat typický tvar ukulele, rozměrově přizpůsobený tak, aby se do něj vešla elektronika i nosná část. Jako vrchní desku jsem zvolil plexisklo, do kterého jsem vygravíroval technické symboly a značení, jež slouží jako designérské prvky. Pro jejich zvýraznění jsem spáry vzniklé gravírováním vybarvil temperovou barvou. 

<div class="img-container" style="text-align: center; margin: 2rem 0;">

  <div class="img-row">
    <img src="/267993_ZPC_25/images/DESKA0.jpg"
         class="img-preview"
         onclick="document.getElementById('popup6a').style.display='flex'">

<span class="arrow">→</span>

<img src="/267993_ZPC_25/images/DESKA1.jpg"
         class="img-preview"
         onclick="document.getElementById('popup6b').style.display='flex'">
  </div>

  <p style="font-style: italic; font-size: 0.9rem;">
    Obr. 8: Úprava desky těla
  </p>

  <!-- Popup levý obrázek -->
  <div id="popup6a" class="modal-overlay" onclick="this.style.display='none'">
    <span class="close-x">&times;</span>
    <img src="/267993_ZPC_25/images/DESKA0.jpg" class="modal-content">
  </div>

  <!-- Popup pravý obrázek -->
  <div id="popup6b" class="modal-overlay" onclick="this.style.display='none'">
    <span class="close-x">&times;</span>
    <img src="/267993_ZPC_25/images/DESKA1.jpg" class="modal-content">
  </div>

</div>

Uživatelské rozhraní jsem navrhl tak, aby bylo co nejjednodušší a nejintuitivnější. Přidal jsem tři tlačítka pro ovládání automatizovaného ladění. Kalibrační tlačítko pouze projede brnkacím mechanismem z krajní do krajní polohy, aby bylo zajištěno, že jsou struny dostatečně napnuté pro automatické ladění. Druhé tlačítko spouští ladicí algoritmus po jednosekundové prodlevě a třetí jej zastavuje.

Dále jsem přidal funkce pro manuální utahování a povolování krokových motorů. Proces připojení k modulu spočívá pouze v zadání hesla v nastavení Wi-Fi telefonu a následném zadání IP adresy modulu do webového prohlížeče. Tento postup je tak funkční na všech zařízeních, která jsou schopna se připojit k internetu.

<div class="img-container" style="text-align: center; margin: 2rem 0;">
    <img src="/267993_ZPC_25/images/APP.png" 
         class="img-previewm" 
         onclick="document.getElementById('popup7').style.display='flex'">
    
  <p style="font-style: italic; font-size: 0.9rem;">Obr. 9: UI aplikace pro ovládání ELEUKO</p>

  <div id="popup7" class="modal-overlay" onclick="this.style.display='none'">
        <span class="close-x">&times;</span>
        <img src="/267993_ZPC_25/images/APP.png" class="modal-content">
    </div>
</div>

Po zabudování funkční části do krytu těla bylo nutné provést finální testování všech funkcí a doladit parametry s ohledem na změněné rezonanční frekvence, které vznikly úpravou celé konstrukce. Kód byl upraven s ohledem na horší detekci struny G, u níž docházelo přibližně v jednom z deseti případů k chybnému měření, což bylo pro ladicí algoritmus považováno za poměrně uspokojivý výsledek.

<div style="text-align: center; margin: 15px 0;">
    <video controls muted playsinline preload="metadata" 
           style="width:100%; max-width:600px; height:auto; border-radius:10px; display:block; margin:0 auto;">
        <source src="/267993_ZPC_25/videos/CELEK.mp4" type="video/mp4">
        Váš prohlížeč nepodporuje přehrávání videa.
    </video>
    <p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 6 – Ukázka funkcionalit jednotlivých funkcí
    </p>
</div>

<div style="text-align: center; margin: 15px 0;">
    <div style="
        width:100%;
        max-width:600px;
        aspect-ratio: 3 / 2;
        overflow: hidden;
        border-radius:10px;
        margin: 0 auto;
    ">
        <video controls muted playsinline preload="metadata"
               style="
                   width:100%;
                   height:100%;
                   object-fit: cover;
               ">
            <source src="/267993_ZPC_25/videos/ELEHRANI.mp4" type="video/mp4">
            Váš prohlížeč nepodporuje přehrávání videa.
        </video>
    </div>

<p style="transform: skewX(-10deg); display: inline-block; margin-top: 5px;">
        Video 7 – Ukázka funkcionalit jednotlivých funkcí
    </p>
</div>


## 3 Možná vylepšení

Po dokončení projektu následovala sebereflexe. Největším nedostatkem projektu byl omezený prostor a výpočetní limity použitého řešení. Pro stabilnější chod a lepší výsledky bych ve druhé verzi prototypu použil modul ESP32, který nabízí vyšší výpočetní výkon a zároveň úsporu místa, jelikož je menší a eliminuje potřebu samostatného Wi-Fi modulu. Dále by bylo vhodné lépe vyztužit spojení vnitřního těla s krkem nástroje, zlepšit jeho akustické vlastnosti a současně upravit ergonomii pro pohodlnější držení krku.

Další možnou tendencí projektu z mé strany je jeho komercializace. Před jejím zahájením by bylo nutné stanovit investiční plán a vstoupit na některou z internetových investičních platforem určených pro startupy za účelem získání počátečního kapitálu. Nezbytná by byla také úprava konstrukce pro výrobu na vstřikovacím lisu a vývoj vlastní programovatelné desky. Značka startupu by se měla orientovat na prémiové samoladicí nástroje, které by byly vyráběny s důrazem na design a ergonomii přizpůsobené každému uživateli.

## 4 Přílohy

###  Kód Arduina
<div style="max-width: 800px; margin: 2rem auto; text-align:left;">
  {{< codewindow file="assets/code/ARDUINO.ino" >}}
</div>

###  Kód Wifi modulu
<div style="max-width: 800px; margin: 2rem auto; text-align:left;">
  {{< codewindow file="assets/code/WIFI.ino" >}}
</div>

</div>



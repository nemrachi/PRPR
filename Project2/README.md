## Project2

Druhý projekt z predmetu Procedurálne programovanie

Znenie zadania:

Projekt č. 2 – Spájaný zoznam štruktúr

Napíšte program, ktorý bude pracovať so záznamami v dynamickom spájanom zozname.
Záznamy uložené v súbore auta.txt budú predstavovať ponuku autobazárov
v internetovom obchode. Pred každým záznamom v súbore bude jeden riadok obsahujúci
znak $, ktorý záznamy viditeľne oddelí. Jednotlivé položky záznamu budú v súbore
umiestnené vždy v samostatnom riadku. 

Význam položiek záznamu bude nasledujúci: 

 kategoria (maximálne 50 znakov)
 znacka (maximálne 50 znakov)
 predajca (maximálne 100 znakov)
 cena (celé číslo)
 rok_vyroby (celé číslo)
 stav_vozidla (maximálne 200 znakov)

Ukážka obsahu súboru auta.txt (znak  označuje prechod na nový riadok):
```
$
osobny automobil
Ferrari
Autobazar Pestovatelska 4 Bratislava
68957
2012
udrziavane cervene dvojdverove
$
kamion
Renault magnum
AUTO Modranska 5 Senec
28000
2016
po havarii opraveny v dobrom stave
```

Program bude vykonávať príkazy načítané zo štandardného vstupu. Každý príkaz bude
predstavovať malé písmeno nasledované znakom konca riadku.

 n – je príkaz na načítanie záznamov o autách zo súboru auta.txt do spájaného
zoznamu štruktúr.

Ak zoznam predtým existoval, je potrebné uvoľniť pamäť. Ak nie je možné súbor
otvoriť, program vypíše správu Zaznamy neboli nacitane ukončenú znakom
konca riadku. Ak sa podarilo záznamy načítať, vypíše správu Nacitalo sa n
zaznamov ukončenú znakom konca riadku, pričom n znamená počet načítaných
záznamov.

 v – je príkaz na výpis celého spájaného zoznamu záznamov.

Formát výpisu je nasledujúci. Pred každým záznamom je uvedené číslo záznamu
(poradie od začiatku zoznamu, začínajúce číslom 1) nasledované bodkou a znakom
konca riadku. Potom nasleduje výpis záznamu, pričom názov položky (bez diakritiky)
je nasledovaný dvojbodkou, medzerou, hodnotou položky a znakom konca riadku. Ak
zoznam neobsahuje záznamy, pri tejto voľbe program negeneruje žiaden výstup.
Ukážka výstupu pre dva vyššie uvedené záznamy:
```
1.
kategoria: osobny automobil
znacka: Ferrari
predajca: Autobazar Pestovatelska 4 Bratislava
cena: 68957
rok_vyroby: 2012
stav_vozidla: udrziavane cervene dvojdverove
2.
kategoria: kamion
znacka: Renault magnum
predajca: AUTO Modranska 5 Senec
cena: 28000
rok_vyroby: 2016
stav_vozidla: po havarii opraveny v dobrom stave
```

 p – je príkaz na pridanie záznamu do dynamického zoznamu.

Príkaz je v ďalšom riadku nasledovaný celým číslom n > 0 vyjadrujúcim pozíciu
(počítanú od 1), na ktorú sa má záznam pridať (záznam z pozície n sa posunie na
pozíciu n+1). Potom nasleduje načítanie ďalších 6 riadkov (nové položky
pridávaného záznamu). Každý riadok je ukončený znakom konca riadku a pridávané
položky záznamu sú v rovnakom poradí v akom sú aj v súbore auta.txt. Ak
pozícia n v zozname neexistuje, záznam sa pridá na koniec zoznamu. Pri tejto voľbe
program negeneruje žiaden výstup.

 z – je príkaz na zmazanie záznamov o autách podľa značky auta.

Riadok s príkazom z je nasledovaný riadkom obsahujúcim značku auta a ukončený
znakom konca riadku. Program vymaže všetky záznamy obsahujúce zadaný názov
auta ako podreťazec, pričom ignoruje rozdiely vo veľkých a malých písmenách. Ak
napríklad používateľ zadá značku auta napr. nDa a zoznam obsahuje záznamy
so značkou Honda alebo HYUNDAI, tento príkaz uvedené záznamy vymaže. Pri tomto
príkaze program vypíše správu Vymazalo sa n zaznamov, kde n je počet
vymazaných záznamov. Správa je ukončená znakom konca riadku. 

 h - umožní používateľovi vyhľadať a vypísať všetky položky záznamu podľa
ceny ponuky.

Riadok s príkazom h je v ďalšom riadku nasledovaný celým číslom c vyjadrujúcim
cenu ponuky. Po zadaní tohto príkazu program vypíše všetky ponuky, ktorých cena je
menšia alebo rovná zadanej hodnote c. Formát výpisu je rovnaký ako pri príkaze v aj
s číslami záznamov, pričom vypísané záznamy sú číslované od 1 po n, kde n je počet
vypísaných záznamov. Záznamy sú vypísané v poradí v akom sa vyskytujú
v spájanom zozname. Ak záznam s ponukou, ktorej cena je menšia, alebo rovná c
neexistuje, program vypíše správu V ponuke su len auta s vyssou cenou
Správa je ukončená znakom konca riadku.

 a – je príkaz na aktualizáciu (zmenu) záznamu podľa značky a ceny auta.

Riadok s príkazom a je nasledovaný riadkom obsahujúcim značku auta ukončený
znakom konca riadku a ďalším riadkom obsahujúcim cenu auta tiež ukončený
znakom konca riadku. Potom nasleduje 6 riadkov obsahujúcich aktualizované
hodnoty záznamu, každý ukončený znakom konca riadku. Vždy je potrebné zadať
všetky položky záznamu. Program aktualizuje všetky záznamy obsahujúce zadanú
značku a cenu auta (presne). Pri tomto príkaze program vypíše správu
Aktualizovalo sa n zaznamov, kde n je počet zmenených záznamov. Správa je
ukončená znakom konca riadku.

 k – je príkaz na ukončenie programu.

Ak spájaný zoznam existoval, treba uvoľniť pamäť. Pri tejto voľbe program
negeneruje žiaden výstup.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct car{
    char category[51];
    char brand[51];
    char shop[101];
    int price;
    int year;
    char state[201];
    struct car * next;
} CAR; //vytvorena strucktura pre zaznamy

int countCars(FILE *fp) { //funkcia pre pocitanie zaznamov
    int _char;
    int countCar = 0; //pocitadlo pre zaznamy
    while ((_char = getc(fp)) != EOF) { //zbieha znak po znaku po koniec suboru
        if (_char == '$') { //zvysi hodnotu pocitadla, ak precita znak $
            countCar++;
        }
    }
    return  countCar; //vrati pocet zaznamov
}

CAR * makeList(FILE *fp, CAR * carsOffer) {
    //funkcia na otvorenie suboru a nacitanie zaznamov zo suboru do spajaneho zoznamu struktur
    int numCars=0;
    if ((fp = fopen("C:\\Users\\emari\\CLionProjects\\Project2\\auta.txt", "r")) == NULL) {
        printf("Zaznamy neboli nacitane\n"); //chybova hlaska, ak sa subor neotvori
    }

    numCars = countCars(fp); //z funkcie countCars sa ulozi pocet zaznamov

    fseek(fp, 0, 0);
    //program je uz raz zbehnuty po koniec, musi ho vratit na zaciatok, kvoli nacitaniu jednotlivych riadkov

    CAR * carInfo = NULL; //list pre nacitanie kazdeho riadku v zazname jednotliveho auta
    CAR * prevCar = NULL; //list, kde sa bude ukladat predchadzajuci zaznam

    if (carsOffer != NULL) { //ak zoznam uz bol naplneny...
        free(carsOffer); //... uvolni pamat
        carsOffer = NULL;
    }

    char line[201];
    char *token;

    while(fgets(line, 51, fp)) { //bude nacitavat riadky po koniec suboru
        carInfo = malloc(sizeof(CAR)); //ked prejde jednotlivy zaznam, alokuje znova pamat pre dalsi zaznam

        fgets(line, 51, fp); //nacita prvy riadok
        token = strtok(line, "\n"); //ulozi nacitany string bez znaku konca riadku
        strcpy(carInfo->category, token); //ulozi string do listu

        fgets(line, 51, fp);
        token = strtok(line, "\n");
        strcpy(carInfo->brand, token);

        fgets(line, 101, fp);
        token = strtok(line, "\n");
        strcpy(carInfo->shop, token);

        fgets(line, 51, fp); //nacita stvrty riadok
        token = strtok(line, "\n"); //ulozi nacitany string bez znaku konca riadku
        carInfo->price = atoi(token); //string pretransformuje na cele cislo, ktore ulozi do listu

        fgets(line, 51, fp);
        token = strtok(line, "\n");
        carInfo->year = atoi(token);

        fgets(line, 201, fp);
        token = strtok(line, "\n");
        strcpy(carInfo->state, token);

        carInfo->next = NULL; //dalsiemu zaznamu priradi zatial hodnotu NULL

        if (carsOffer == NULL) { //ak sa zapisuje prvy zaznam...
            carsOffer = carInfo; //...prvy smernik nasmerujeme na prvy zaznam
        } else { //ak su nejake zaznamy zapisane
            prevCar = carsOffer; //ulozi predtym nacitane zaznamy do inej premennej
            while (prevCar->next != NULL) { //dostane sa na koniec zaznamu
                prevCar = prevCar->next;
            }
            prevCar->next = carInfo; //na posledny list zoznamu zapise posledny nacitany zaznam
        }
    }

    fclose(fp); //zatvori subor
    printf("Nacitalo sa %d zaznamov\n", numCars);
    //vypise pocet nacitanych zaznamov
    return carsOffer; //vrati nacitany zoznam
}

void printCars(CAR * carsOffer) { //funkcia na vypis celeho zoznamu
    if (carsOffer != NULL) { //ak obsah obsahuje zaznamy, vypise ich, inak negeneruje vstup
        CAR *carInfo = carsOffer;
        int index = 1;

        while (carInfo != NULL) {
            printf("%d.\n", index);
            printf("kategoria: %s\n", carInfo->category);
            printf("znacka: %s\n", carInfo->brand);
            printf("predajca: %s\n", carInfo->shop);
            printf("cena: %d\n", carInfo->price);
            printf("rok_vyroby: %d\n", carInfo->year);
            printf("stav_vozidla: %s\n", carInfo->state);
            index++;
            carInfo = carInfo->next;
        }
    }
}

CAR * createNewCar() { //vytvaranie noveho zaznamu auta
    CAR * newCar = malloc(sizeof(CAR)); //alokuje pamat pre novy zaznam
    char line[201];
    char *token;

    fgets(line, 51, stdin); //ulozi do premennej line vstup z klavesnice (stdin)
    token = strtok(line, "\n");
    strcpy(newCar->category, token);

    fgets(line, 51, stdin);
    token = strtok(line, "\n");
    strcpy(newCar->brand, token);

    fgets(line, 101, stdin);
    token = strtok(line, "\n");
    strcpy(newCar->shop, token);

    fgets(line, 51, stdin);
    token = strtok(line, "\n");
    newCar->price = atoi(token);

    fgets(line, 51, stdin);
    token = strtok(line, "\n");
    newCar->year = atoi(token);

    fgets(line, 201, stdin);
    token = strtok(line, "\n");
    strcpy(newCar->state, token);

    newCar->next = NULL;

    return newCar; //vrati novy zaznam auta
}

CAR * insertCar(CAR *carsOffer) { //prida nove auto na urcitu poziciu do zozanmu
    int position;
    scanf("%d\n", &position); //zadame poziciu, kde chceme pridat novy zaznam

    CAR * newCar = createNewCar(); //funkcia, na vytvorenie noveho zaznamu

    if (carsOffer == NULL) {
        //ak este nebol vytvoreny zoznam a chce pridat auto
        newCar->next = carsOffer;
        return newCar;
    }

    if (position == 1) { //ak je zadana prva pozicia
        newCar->next = carsOffer; //na nasledujuci smernik namseruje cely existujuci zoznam
        return newCar; //vrati novy zoznam
    }

    CAR * firstOffer = carsOffer; //ulozi si smernik na prvy list zoznamu

    int index = 0;

    while (index < position-2 && carsOffer->next != NULL) { //pokracuje na dalsie zaznamy
        carsOffer = carsOffer->next;
        index++;
    }

    CAR * carNext = carsOffer->next; //ulozi si nadchadzajuci zaznam

    carsOffer->next = newCar; //na miesto normalne sa nadchadzajucemu sa zaznamu ulozi novy zaznam
    newCar->next = carNext;
    //na nasledujuci zaznam po novom aute nasmeruje predtym ulozeny nasledujuci zaznam

    return firstOffer; //vrati novy zoznam
}

int strInStrCase (const char * tempBrand, const char * wantedBrand) {
    //funkcia, ktora najde string v stringu bez ohladu na velkost pismen
    int index;
    unsigned int l = strlen(wantedBrand); //zisti velkost hladaneho stringu

    for (index = 0; tempBrand[index] != 0; index++) {
        if (strncasecmp(&tempBrand[index], wantedBrand, l) == 0) {
            /*funkcia strncasecmp, obsiahnuta v kniznici <strings.h>, porovnava
             * len urcity pocet (l) pismen bez ohladu na velkost */
            return 0;
        }
    }

    return 1;
}

void deleteOffers(CAR ** carsOffer) {
    //funkcia vymaze zaznamy zo zoznamu
    if (*carsOffer != NULL) {
        //ak pole je naplnene, vykonaju sa dalsie prikazy
        CAR * tempCar = *carsOffer; //premenna pre terajsi zaznam
        CAR * prevCar = NULL; //premenna pre predosli zaznam
        char  wantedBrand[51];
        int deleted = 0;

        scanf("%s", wantedBrand);

        while (tempCar != NULL) {
            //pokial sa zoznam nedostane na koniec, vykonava prikazy
            if (strInStrCase(tempCar->brand, wantedBrand) == 0) {
                //ak najde string v stringu...
                if (prevCar != NULL) {
                    //...tak ak uz prevCar bolo naplnene, tak bude smerovat az na dalsi zaznam
                    prevCar->next = tempCar->next;
                } else {
                    //...a ak to je prvy zaznam na vymazanie, hlavickovy smernik nasmeruje na dalsi zaznam
                    *carsOffer = tempCar->next;
                }
                free(tempCar); //uvolni terajsi zaznam
                deleted++; //napocita dalsi vymazany zaznam
            } else {
                //ak nenajde string v stringu
                prevCar = tempCar; //na predosli list ulozi terajsi
            }
            tempCar = tempCar->next; //posunie sa na dalsi list
        }

    printf("Vymazalo sa %d zaznamov\n", deleted); //vypise pocet vymazanych zaznamov
    }
}

void chooseCarPrice(CAR * carsOffer) {
    //funkcia vyhlada vsetky zaznamy podla znacky auta a ceny ponuky
    char wantedBrand[51];
    int wantedPrice;

    fgets(wantedBrand, 51, stdin);
    //prvy fgets nacitava prazdny riadok z nejakeho neznameho dovodu
    fgets(wantedBrand, 51, stdin);
    //az druhy nacita napisany text
    strtok(wantedBrand, "\n");
    //zo stringu vymaze znak dalsieho riadku
    scanf("%d", &wantedPrice);
    //nacita cenu

    int index = 0;
    //pocita poziciu kazdeho zaznamu
    int countPrints = 0; //pocita vypisane zaznamy

    while(carsOffer != NULL) {
        if(strcasecmp(carsOffer->brand, wantedBrand) == 0 && carsOffer->price <= wantedPrice) {
            /*funkcia strcasecmp je obsiahnuta v kniznici <strings.h> a dana funkcia
             *porovnava 2 stringy a vrati hodnotu 0, ak sa stringy rovnaju bez ohladu
             *na velkost pismen */
            index++;
            printf("%d.\n", index);
            printf("kategoria: %s\n", carsOffer->category);
            printf("znacka: %s\n", carsOffer->brand);
            printf("predajca: %s\n", carsOffer->shop);
            printf("cena: %d\n", carsOffer->price);
            printf("rok_vyroby: %d\n", carsOffer->year);
            printf("stav_vozidla: %s\n", carsOffer->state);
            countPrints++;
        }
        carsOffer = carsOffer->next;
    }
    if (countPrints == 0) {
        printf("V ponuke nie su pozadovane auta.\n");
    }
}

void newPrice(CAR * carsOffer) { //aktualizacia ceny v zazname
    char wantedBrand[51];
    int wantedYear;
    int updated = 0;

    fgets(wantedBrand, 51, stdin);
    //prvy fgets nacitava prazdny riadok z nejakeho neznameho dovodu
    fgets(wantedBrand, 51, stdin);
    //az druhy nacita napisany text
    strtok(wantedBrand, "\n");
    //zo stringu vymaze znak dalsieho riadku
    scanf("%d", &wantedYear);
    //nacita rok vyroby

    while(carsOffer != NULL) { //prechadzame cez vsetky zaznamy
        if (strcasecmp(carsOffer->brand, wantedBrand) == 0 && carsOffer->year == wantedYear) {
            carsOffer->price -= 100;
            //ak znacka a rok budu sediet, jeho cenu znizi o 100
            if (carsOffer->price < 0) {
                carsOffer->price = 0;
                //ak po znizeni cena bude vychadzat zaporna, upravi ju na hodnotu 0
            }
            updated++; //nacitava pocet aktualizovanych zaznamov
        }
        carsOffer = carsOffer->next;
    }
    printf("Aktualizovalo sa %d zaznamov\n", updated);
    //vypise pocet aktualizovanych zaznamov
}

void freeList(CAR * carsOffer) { //funkcia na uvolnenie listu
    CAR * tempCar; //premenna na ulozenie aktualneho zaznamu

    while (carsOffer != NULL) {
        //uvolnuje list postupne zaznam po zazname
        tempCar = carsOffer;
        carsOffer = carsOffer->next;
        free(tempCar);
    }
}

int main() {
    char command; //premenna pre prikaz
    FILE *fp = NULL; //smernik na subor
    CAR * carsOffer = NULL; //spajany zoznam pre zaznamy o autach

    while ((command = getchar()) != 'k') {
        //pokial nezadame pismeno 'k', vykonava prikaz switch
        switch (command) {
            case 'n':
                carsOffer = makeList(fp, carsOffer);
                //otvori subor a vytvori spajany zoznam
                break;

            case 'v':
                printCars(carsOffer);
                //vytlaci spajany zoznam
                break;

            case 'p':
                carsOffer = insertCar(carsOffer);
                //prida nove auto
                break;

            case 'z':
                deleteOffers(&carsOffer);
                //vymaze urcity zaznam
                break;

            case 'h':
                chooseCarPrice(carsOffer);
                //vypise vsetky polozky zaznamu podla znacky auta a ceny
                break;

            case 'a':
                newPrice(carsOffer);
                //aktualizuje ceny aut, ktore vyhlada podla znacky a roku vyroby
                break;
        }
    }
    freeList(carsOffer);
    //uvolni pamat
    return 0;
}
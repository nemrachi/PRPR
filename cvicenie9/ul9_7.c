#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nazov[100];
    char vyrobca[100];
    double mnozstvo;
    double cena;
} TOVAR;

//chyba!!!
TOVAR **sortArray (TOVAR **all, int i) {
    TOVAR *temp;
    int index = i;

    while (index > 0 && (strcasecmp(all[index]->nazov, all[index-1]->nazov) < 0)) {
        temp = all[index-1];
        all[index-1] = all[index];
        all[index] = temp;
        index--;
    }
    return all;
}

int main () {
    char vloz[] = "vloz";
    char vypis[] = "vypis";
    char *prikaz = malloc(300);
    char *token;
    int i = 0;
    TOVAR *tovArr = malloc(sizeof(TOVAR));
    TOVAR **all = malloc(sizeof(TOVAR));

    while (gets(prikaz)) {
        token = strtok(prikaz, " ");
        if (!(strcasecmp(token, "\n"))) continue;

        if (!(strcmp(token, vloz))) {
            token = strtok(NULL, " ");
            strcpy(tovArr->nazov, token);

            token = strtok(NULL, " ");
            strcpy(tovArr->vyrobca, token);

            token = strtok(NULL, " ");
            tovArr->mnozstvo = atof(token);

            token = strtok(NULL, "\n");
            tovArr->cena = atof(token);

            all[i] = tovArr;

            if (i > 0) {
                all = sortArray(all, i);
            }

            tovArr = calloc(1, sizeof(TOVAR));

            ++i;
            all = realloc(all, (i + 1) * sizeof(TOVAR));
        }
        else if (!(strcmp(token, vypis))) {
            for (int j = 0; j < i; j++) {
                printf("Nazov=%s, ", all[j]->nazov);
                printf("Vyrobca=%s, ", all[j]->vyrobca);
                printf("Mnozstvo=%.6f ", all[j]->mnozstvo);
                printf("JednotkovaCena=%.6f\n", all[j]->cena);
            }

        }
    }
    return 0;
}
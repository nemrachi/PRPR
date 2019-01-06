#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int *makeArray(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 99;
    }
    return a;
}

int druhe_najvacsie(int *a, int size) {
    /*int position = 0;
    int max = a[0];

    for (int i = 0; i < size; ++i) {
        if (a[i] >= max) {
            max = a[i];
            position = i;
        }
    }

    int temp = a[size-1];
    a[size-1] = a[position];
    a[position] = temp;
    --size;
    max = a[0];

    for (int j = 0; j < size; ++j) {
        if (a[j] >= max) {
            max = a[j];
            position = j;
        }
    }
    return position;
     //funkcne, len dlhe
     */

    int i, max = 0, max2 = 0;

    for (i = 1; i < size; i++) {
        if (a[max] < a[i]) {
            max2 = max;
            max = i;

        } else if (a[i] > a[max2] && a[i] != a[max]) {
            max2 = i;
        }
    }
    return max2; //niekedy to hadze chybne cisla

}

int main() {
    int n;
    int *a = NULL;
    srand(time(NULL));
    int index = 0;

    while (1) {
        printf("Pocet:\n");
        scanf("%d", &n);
        if (n == 0 || n == 1) {
            break;
        }

        if (a == NULL) {
            a = malloc(n * sizeof(int));
        } else {
            free(a);
            a = malloc(n * sizeof(int));
        }

        a = makeArray(a,n);
        printArray(a, n);
        index = druhe_najvacsie(a, n);
        printf("Druhe najvacsie cislo v poli je %d\n", a[index]);
    }
    return 0;
}
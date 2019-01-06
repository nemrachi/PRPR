#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *makeArray(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 99;
    }
    return a;
}

void printArray(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maxNum (int *arr, int size) {
    int max = arr[0];

    for (int i = 0; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    if(max < 0) {
        return -1;
    }

    return max;
}

int najvyskytovanejsieCislo(int *arr, int size, int *najCount) {
    int naj = 0;
    int count = 0;
    *najCount = 0;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                ++count;
            }
        }
        if (count > *najCount) {
            *najCount = count;
            naj = arr[i];
            count = 0;
        } else {
            count = 0;
        }

    }
    return naj;
}

int *vloz(int *arr, int *size) {
    int newNum, position, index = *size;

    printf("Cislo:\n");
    scanf("%d", &newNum);
    printf("Pozicia:\n");
    scanf("%d", &position);
    ++(*size);
    --position;

    arr = (int*)realloc(arr, (*size) * sizeof(int));

    while (index) {
        if (index == position) {
            arr[index] = newNum;
            break;
        }
        arr[index] = arr[index-1];
        --index;
    }
    return arr;
}

int *vymen(int *arr, int size) {
    int poz1, poz2;
    int temp;
    printf("Zadaj 2 pozicie:\n");
    scanf("%d %d", &poz1, &poz2);

    if (poz1>size-1 || poz1<0) {
        poz1 = rand() % size;
    }
    if (poz2>size-1 || poz2<0) {
        poz2 = rand() % size;
    }

    temp = arr[poz1];
    arr[poz1] = arr[poz2];
    arr[poz2] = temp;

    return arr;
}

int *otocPrvky (int *arr, int size) {
    int temp;
    int index = size-1;

    for (int i = 0; i < size/2 ; ++i) {
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        --index;
    }
    return arr;
}

int *spojPolia(int *arr, int size) {
    int *newArr;

}

int main() {
    int *arr = NULL;
    int size = 0;
    srand(time(NULL));
    char prikaz[20];
    char *token;

    printf("Pocet:\n");
    scanf("%d", &size);

    arr = malloc(size * sizeof(int));
    arr = makeArray(arr, size);
    printArray(arr, size);

    printf("Prikaz:\n");

    while (fgets(prikaz, 20, stdin)) {
        token = strtok(prikaz, " \n");

        if (!(strcasecmp(token, "help"))) {
            printf("Help:\n");
            printf("Najvacsie nezaporne cislo: \"max\"\n");
            printf("najcastejsie cislo: \"naj\"\n");
            printf("Vytvori nove pole: \"new\"\n");
            printf("Vypise pole: \"p\"\n");
            printf("Ukonci program: \"e\"\n");

        } else if (!(strcasecmp(token, "max"))) {
            int max = maxNum(arr, size);

            if (max == -1) {
                printf("Nema najvacsie cislo neyaporne.\n");

            } else {
                printf("Najvacsie nezaporne cislo je %d\n", max);
            }

        } else if (!(strcasecmp(token, "naj"))) {
            int najCount;
            int naj = najvyskytovanejsieCislo(arr, size, &najCount);
            if (najCount == 1) {
                printf("Nie je ani jedno cislo.\n");
            } else {
                printf("%d sa vyskytuje %dx.\n", naj, najCount);
            }

        } else if (!(strcasecmp(token, "vloz"))) {
            arr = vloz(arr, &size);

        } else if (!(strcasecmp(token, "vym"))) {
            arr = vymen(arr, size);

        } else if (!(strcasecmp(token, "otoc"))) {
            arr = otocPrvky(arr, size);

        } else if (!(strcasecmp(token, "e"))) {
            break;

        } else if (!(strcasecmp(token, "p"))) {
            printArray(arr, size);

        }else if (!(strcasecmp(token, "new"))) {
            printf("Pocet:\n");
            scanf("%d", &size);

            free(arr);
            arr = malloc(size * sizeof(int));
            arr = makeArray(arr, size);
            printArray(arr, size);

            printf("Prikaz:\n");

        } else if (strcasecmp(prikaz, "\n") != 0) {
        printf("Try to type: \"help\"\n");

        }
    }

    return 0;
}

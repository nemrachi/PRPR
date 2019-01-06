// uloha9-5.c -- Ema Richnáková, 13.12.2018 10:10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int suma;
    char row[200];
    int i = 0;
    char *token;
    int num;

    fgets(row, 50, stdin);
    n = atoi(row);
    //printf("%d", n);
    int *array = malloc(n * sizeof(int));

    fgets(row, 200, stdin);

    token = strtok(row, " ");

    while (token != NULL){
        num = atoi(token);
        array[i] = num;
        ++i;
        token = strtok(NULL, " ");

    }

    fgets(row, 50, stdin);
    suma = atoi(row);

    /*
    for (int k = 0; k < n; ++k) {
        printf("%d\n", array[k]);
    }
     */

    int sum = 0;
    int *newArr = malloc (1 * sizeof(int));
    int j = 0;
    int *last = malloc(1 * sizeof(int));

    for (i = 0; i < n; i++) {
        newArr[j] = array[i];

        sum += newArr[j];
        ++j;
        newArr = realloc (newArr,(j+1) * sizeof(int));

        if (sum == suma) {
            for (int k = 0; k < j; k++) {
                printf("%d ", newArr[k]);
            }
            break;
        } else if (sum > suma) {
            sum = array[i];
            j = 0;
            free(newArr);
            newArr =  malloc(1 * sizeof(int));
            newArr[j] = array[i];
            ++j;
        }
    }
    return 0;
}
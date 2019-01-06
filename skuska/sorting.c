#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

int *insertSort(int size, int *arr) {
    int temp = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i-1] > arr[i]) {
            for (int j = i-1; j >=0 ; j--) {
                if (arr[j] >  arr[j+1]) {
                    temp =arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    return arr;
}

void swap(int *p, int *q) {
    int t;

    t = *p;
    *p = *q;
    *q = t;
}

int *quickSort(int *arr, int low, int high) {
    int pivot = arr[high-1];


    printf("%d\n", pivot);
    return arr;
}


int main() {
    int size = 0;
    int *defaultArr = setArray(&size);
    int *arr = setDefault(size, defaultArr);


    char algorithm[100];
    char *token;
    printf("Choose algorithm:\n");

    while (fgets(algorithm, 100, stdin)) {
        token = strtok(algorithm, " \n");

        if (!(strcasecmp(token, "bub"))) {
            arr = bubbleSort(size, arr);
            printArray(size, arr);
            free(arr);
            arr = setDefault(size, defaultArr);

        } else if (!(strcasecmp(token, "sel"))) {
            printf("\"Max\" or \"min\" sorting?\n");
            fgets(algorithm, 4, stdin);
            token = strtok(algorithm, "\n");

            if (!(strcasecmp(token, "max"))) {
                arr = selectMAX(size, arr);
                printArray(size, arr);
                free(arr);
                arr = setDefault(size, defaultArr);

            } else {
                arr = selectMIN(size, arr);
                printArray(size, arr);
                free(arr);
                arr = setDefault(size, defaultArr);
            }

        } else if (!(strcasecmp(token, "in"))) {
            arr = insertSort(size, arr);
            printArray(size, arr);
            free(arr);
            arr = setDefault(size, defaultArr);

        } else if (!(strcasecmp(token, "q"))) {
            arr = quickSort(size, arr);
            printArray(size, arr);
            free(arr);
            arr = setDefault(size, defaultArr);

        } else if (!(strcasecmp(token, "help"))) {
            printf("Help:\nFor Bubble sort type \"bub\"\n");
            printf("For Select sort type \"sel\"\n");
            printf("For Insert sort type \"in\"\n");
            printf("For Quick sort type \"q\"\n");
            printf("For setting new array type \"new\"\n");
            printf("To print default array type \"p\"\n");
            printf("End program with \"e\"\n");

        } else if (!(strcasecmp(token, "e"))) {
            break;

        } else if (!(strcasecmp(token, "new"))) {
            free(defaultArr);
            defaultArr = setArray(&size);
            arr = setDefault(size, defaultArr);
            printf("Choose algorithm:\n");

        } else if (!(strcasecmp(token, "p"))) {
            printArray(size, defaultArr);

        } else if (strcasecmp(algorithm, "\n") != 0) {
            printf("Try to type \"help\"\n");

        }
    }

    return 0;
}

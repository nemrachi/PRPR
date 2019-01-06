#ifndef PRPR1_SORTING_H
#define PRPR1_SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *setArray(int *size) {
    printf("Size of array:\n");
    scanf("%d", size);
    srand(time(NULL));

    int *arr = malloc((*size)* sizeof(int));
    //printf("Elements of array:\n");
    for (int i = 0; i < *size ; i++) {
        //scanf("%d", &arr[i]);
        arr[i] = rand() % 99;
    }
    return arr;
}

int *setDefault(int size, int *defaultArr) {
    int *arr = malloc(size * sizeof(int));
    for (int a = 0; a < size; ++a) {
        arr[a] = defaultArr[a];
    }
    return arr;
}

void printArray (int size, int *arr) {
    for (int i = 0; i < size ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *bubbleSort(int size, int *arr) {
    int temp;
    for (int i = 1; i < size ; ++i) {
        for (int j = 0; j < size-1 ; ++j) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

int findMAX(int size, int *arr) {
    int max = arr[0];
    int position = 0;

    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
            position = i;
        }
    }
    return position;
}

int *selectMAX(int size, int *arr) {
    int temp;
    int position;
    int currSize = size;

    for (int i = 0; i < size-1; ++i) {
        position = findMAX(currSize, arr);
        --currSize;
        if (position == currSize) {
            continue;
        } else {
            temp = arr[currSize];
            arr[currSize] = arr[position];
            arr[position] = temp;
        }
    }
    return arr;
}

int findMIN (int currSize, int size, int *arr) {
    int min = arr[currSize];
    int  position = currSize;

    for (int i = currSize+1; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
            position = i;
        }
    }
    return position;
}

int *selectMIN(int size, int *arr) {
    int temp = 0;
    int position = 0;

    for (int i = 0; i < size; i++) {
        position = findMIN(i, size, arr);
        if (position == i) {
            continue;
        } else {
            temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }
    return arr;
}

#endif //PRPR1_SORTING_H

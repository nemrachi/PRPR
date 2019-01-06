#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>

int *makeArr (char *str, int *size) {
    char *token;
    int num;
    int *arr = malloc(sizeof(int));
    int i = 0;

    token = strtok(str, " ");
    while (token != NULL) {
        //printf("%d\n", token);
        num = atoi(token);
        arr[i] = num;
        ++i;
        arr = realloc(arr, (i+1) * sizeof(int));
        token = strtok(NULL, " ");
    }
    *size = i;
    return arr;
}

int main()
{
    char str[200];
    int size = 0;
    int i = 0;
    int j = 0;
    int zvysok = 0;
    int count = 0;
    int *newArr = malloc(sizeof(int));

    fgets(str, 200, stdin);

    int *arr = makeArr(str, &size);

    while (zvysok < 10) {
        //if (zvysok == 10) break;
        ++count;
        if (zvysok == (arr[i]/10)) {
            newArr[j] = arr[i];
            ++j;
            newArr = realloc(newArr, (j + 1) * sizeof(int));
            printf("%d\n", newArr[j]);
        }
            if (count == size && newArr != NULL) {
                printf("\n%d | ", zvysok);
                for (int k = 0; k <= j; ++k) {
                    printf("%d", newArr[k]);
                }
                newArr = calloc(1, sizeof(int));
                newArr = NULL;
                i = 0;
                j = 0;
                count = 0;
                ++zvysok;
            }

        ++i;
    }

    return 0;
}
// uloha9-1.c -- Ema Richnáková, 21.11.2018 09:07

#include <stdio.h>
#include <stdlib.h>

int is_magic(int **a, int n)
{
    int count = 0;
    int total = 0;
    int i = 0, j;
    for (j = 0; j < n; j++) { //sucet riadku 0
        total += a[i][j];
    }

    for (i = 1; i < n; i++) { //ostatne riadky
        for (int j = 0; j < n; j++) {
            count += a[i][j];
        }
        if (count != total) {
            return 0;
        }
        count = 0;
    }

    for (i = 0; i < n; i++) { //stlpce
        for (j = 0; j < n; j++) {
            count += a[j][i];
        }
        if (count != total) {
            return 0;
        }
        count = 0;
    }


    return 1;
}

int main()
{
    int i, j, **s, n;

    scanf("%d", &n);
    s = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        s[i] = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d ", &s[i][j]);

    if (is_magic(s, n))
        printf("Je magicky.\n");
    else
        printf("NIE JE magicky!\n");

    return 0;
}
#include <stdio.h>
#include <string.h>

int anagram(char *a1, char *a2) {
    if (strlen(a1) != strlen(a2)) {
        return 0;
    }

    int len = strlen(a1);
    int true = 1;
    int i = 0;

    while (true) {
        for (int j = 0; j < len ; ++j) {
            if (a1[i] == a2[j]) {
                a2[j] = '*';
                true = 1;
                break;
            } else {
                true = 0;
            }
        }
        ++i;
        if (i == len) break;
    }

    if (true) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char a1[100], a2[100];

    fgets(a1, 100, stdin);
    fgets(a2, 100, stdin);

    if (anagram(a1, a2) == 1) {
        printf("Je anagram.");
    } else {
        printf("Nie je anagram.");
    }
    return 0;
}
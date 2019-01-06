#include <stdio.h>
#include <string.h>
#include <ctype.h>

int podretazec(char *base, char *str) {
    int j = 0;
    for (int i = 0; i < strlen(base); ++i) {
        if (tolower(base[i]) == tolower(str[j])) {
             ++j;
             if (j == strlen(str)) return 1;
        }
    }
    return 0;
}

int main() {
    char str1[100];
    char str2[100];
    char *token1, *token2;

    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);

    token1 = strtok(str1, "\n");
    token2 = strtok(str2, "\n");

    if (podretazec(token1, token2)) {
        printf("V \"%s\" je \"%s\".\n", token1, token2);
    } else {
        printf("Ee.\n");
    }

    return 0;
}
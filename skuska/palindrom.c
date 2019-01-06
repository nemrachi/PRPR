#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome(char *str, int size) {
    char *token = malloc(size * sizeof(char));
    int k = 0, l = 0;

    while (str[k] != '\n') {
        if (str[k] != ' ') {
            token[l] = str[k];
            ++l;
        }
        ++k;
    }

    int j = l-1;

    for (int i = 0; i < l/2; ++i) {
        if(token[i] != token[j]) {
            return 0;
        }
        --j;
    }
    return 1;
}

int main() {
    char str[100];
    int count = 0;

    fgets(str, 100, stdin);

    while (str[count] != '\n') {
        ++count;
    }

    if (palindrome(str, count)) {
        printf("Je to palindrom.");
    } else {
        printf("Nie je to palindrom.");
    }

    return 0;
}
// uloha9-3.c -- Ema Richnáková, 4.12.2018 09:03

// uloha9-3.c -- Ema Richnáková, 4.12.2018 09:03

#include <stdio.h>
#include <stdlib.h>

void findStar (char *ch) {
    int i = 0;
    int *position = malloc(sizeof(int));
    int countStars = 0;

    while (ch[i] != '\n') {
        if (ch[i] == '*') {
            position[countStars] = i;
            countStars++;
            position = realloc(position, countStars+1);
        }
        i++;
    }

    i = 0;
    int j = 0;

    if (countStars) {
        printf("%s", ch);
        while(ch[i] != '\n') {
            if (i == position[j]) {
                printf("^");
                j++;
            } else {
                printf(" ");
            }
            i++;
        }
    }
}

int main()
{
    char ch[20];
    while(fgets(ch, 20, stdin)) {
        findStar(ch);
    }

    return 0;
}


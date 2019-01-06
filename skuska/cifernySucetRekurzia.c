#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int cifernySucet(int x) {
    if (x > 0) {
        return (x%10) + cifernySucet(x/10);
    } else {
        return x;
    }
}

int main() {
    char ch[20];
    int num = 0;
    char *token;
    srand(time(NULL));

    while(fgets(ch, 20, stdin)) {
        token = strtok(ch, "\n");
        if (!(strcasecmp(token, "e"))) {
            break;
        }

        num = rand();
        printf("%d\n", num);
        printf("Sucet: %d\n", cifernySucet(num));
    }

    return 0;
}

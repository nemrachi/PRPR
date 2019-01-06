#include <stdio.h>
#include <string.h>

int main () {
    char str[200];
    char *token;
    char ch[2] = "\n";
    int count = 0;
    int total = 0;
    int i = 0;

    while (fgets(str, 200, stdin)) {
        if (strcmp(str, ch)) {
            printf("%s", str);
            token = strtok(str, " ");
            while (token != NULL) {
                while (1) {
                    if (token[i] != '\0' || token[i] != '\n') {

                        ++i;
                    } else {
                        break;
                    }
                }
                printf("AHA %s %d\n", token, strlen(token));
                token = strtok(NULL, " ");
            }
        } else {
            break;
        }
    }
    return 0;
}

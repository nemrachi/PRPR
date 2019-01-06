#include <stdio.h>

int f(int a, int b, int c) {
    if ((a+b+c)>1) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    printf("a b c -> f(a,b,c)\n");
    printf("-----------------\n");

    for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
            for (int c = 0; c < 2; ++c) {
                printf("%d %d %d -> %d\n",a,b,c,f(a,b,c));
            }
        }
    }
    return 0;
}

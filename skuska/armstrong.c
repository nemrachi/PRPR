// uloha4-5.c -- Ema Richnáková, 22.10.2018 21:25

#include <stdio.h>

int armstrong(int x) {
    int j,k,sum,exponent,digit,w_x,f_x,exp_dgt;
    exponent = 0;
    w_x = x;
    f_x = x;
    sum = 0;

    while (w_x) { //exponent/cifry
        w_x /= 10;
        exponent++;
    }

    for (j = 0; j < exponent; ++j){
        digit = (f_x % 10);
        exp_dgt = digit;
        for (k = 0; k < (exponent-1); ++k) {
            exp_dgt *= digit;
        }
        sum += exp_dgt;
        f_x /= 10;
    }
    if (x == sum){
        return 1;
    }
    return 0;

}

int main()
{
    int n,i,number;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("\n%d", &number);
        armstrong(number);
        if (armstrong(number) == 1) {
            printf("%d je Armstrongove cislo\n",number);
        } else {
            printf("%d nie je Armstrongove cislo\n",number);
        }
    }
    return 0;
}
#include "s21_decimal.h"
#include <stdio.h>

int main() {
    int n = -25;
    int m = -25;
    s21_decimal kek;
    s21_decimal lol;
    s21_decimal res;
    s21_from_int_to_decimal(n, &kek);
    s21_from_int_to_decimal(m, &lol);
    s21_mul(kek, lol, &res);
    int q = 0;
    s21_from_decimal_to_int(res, &q);
    printf("%d", q);
    return 0;
}
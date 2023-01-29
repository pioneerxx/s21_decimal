#include "s21_decimal.h"
#include <stdio.h>

int main() {
    int n = 25;
    s21_decimal kek;
    s21_from_int_to_decimal(n, &kek);
    int q = 0;
    s21_from_decimal_to_int(kek, &q);
    printf("%d", q);
}
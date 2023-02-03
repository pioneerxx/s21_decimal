#include "s21_decimal.h"
#include <stdio.h>

int main() {
    float a = 1024.23567;
    s21_decimal kek;
    s21_from_float_to_decimal(a, &kek);
    print_bits(kek);
    printf("%d\n", get_exp(kek));
    return 0;
}
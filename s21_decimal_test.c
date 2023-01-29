#include "s21_decimal.h"
#include <stdio.h>

int main() {
    s21_decimal mocha1;
    s21_decimal mocha2;
    s21_decimal mocha3;
    float dst1;
    int dst2;
    printf("1 %d\n", s21_add(mocha1, mocha2, &mocha3));
    printf("2 %d\n", s21_div(mocha1, mocha2, &mocha3));  
    printf("3 %d\n", s21_floor(mocha1, &mocha2));
    printf("4 %d\n", s21_from_decimal_to_float(mocha1, &dst1));
    printf("5 %d\n", s21_from_decimal_to_int(mocha1, &dst2));
    printf("6 %d\n", s21_from_float_to_decimal(dst2, &mocha1));
    printf("7 %d\n", s21_from_int_to_decimal(dst2, &mocha1));
    printf("8 %d\n", s21_is_equal(mocha1, mocha2));
    printf("9 %d\n", s21_is_greater(mocha1, mocha2));
    printf("10 %d\n",s21_is_greater_or_equal(mocha1, mocha2));
    printf("11 %d\n",s21_is_less(mocha1, mocha2));
    printf("12 %d\n",s21_is_less_or_equal(mocha1, mocha2));
    printf("13 %d\n",s21_is_not_equal(mocha1, mocha2));
    printf("14 %d\n",s21_mod(mocha1, mocha2, &mocha3));
    printf("15 %d\n",s21_mul(mocha1, mocha2, &mocha3));
    printf("16 %d\n",s21_negate(mocha1, &mocha2));
    printf("17 %d\n",s21_round(mocha1, &mocha2));
    printf("18 %d\n",s21_sub(mocha1, mocha2, &mocha3));
    printf("19 %d\n",s21_truncate(mocha1, &mocha2));
}
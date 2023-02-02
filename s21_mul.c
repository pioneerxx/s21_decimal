#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    nullify(result);
    int res = 0;
    int neg1 = 0;
    int neg2 = 0;
    int cycle = 0;
    s21_decimal tmp;
    nullify(&tmp);
    if (is_neg(value_1)) {
        neg1 = 1;
        set_bit_to_0(&(value_1.bits[3]), 31);
    }
    if (is_neg(value_2)) {
        neg2 = 1;
        set_bit_to_0(&(value_2.bits[3]), 31);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 32; j++) {
            if (get_bit(value_1.bits[i], j)) {
                from_decimal_to_decimal(value_2, &tmp);
                for (int n = 0; n < cycle; n++) {
                    s21_add(tmp, tmp, &tmp);
                }
                s21_add(*result, tmp, result);
                nullify(&tmp);
            }
            cycle++;
        }
    }
    if ((neg1 && !neg2) || (!neg1 && neg2)) {
        set_bit_to_1(&(result->bits[3]), 31);
    }
    return res;
}
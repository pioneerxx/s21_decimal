#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int res = 0;
    long int power = 1;
    *dst = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 32; j++) {
            if (get_bit(src.bits[i], j)) {
                if (*dst + power > 32768) {
                    res = 1;
                    break;
                } 
                *dst += power;
            }
            power *= 2;
        }
    }
    if (get_bit(src.bits[3], 31)) {
        *dst *= -1;
    }
    return res;
}
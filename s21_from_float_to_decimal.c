#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));
    int start = (int)src;
    float end = src - start;
    int exp = 0;
    if (src < 0) {
        set_bit_to_1(&(dst->bits[3]), 31);
        src *= -1;
    }
    dst->bits[0] = start;
    for (int i = 0; i < 8; i++) {
        end *= 10;
        multiply(dst, 10);
        add(dst, (int)end);
        exp++;
        end -= (int)end;
    }
    set_exp(dst, exp);
    return 0;
}
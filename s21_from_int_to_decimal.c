#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    memset(&(dst->bits), 0, sizeof(dst->bits));
    if (src < 0) {
        set_bit_to_1(&(dst->bits[3]), 31);
        src *= -1;
    }
    dst->bits[0] = src;
    return 0;
}
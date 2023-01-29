#include "s21_decimal.h"

void set_bit_to_1(int *value, int bitNum) {
    *value |= (1 << bitNum);
}

void set_bit_to_0(int *value, int bitNum) {
    *value &= ~(1 << bitNum);
}
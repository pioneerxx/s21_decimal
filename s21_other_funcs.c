#include "s21_decimal.h"

void set_bit_to_1(int *value, int bitNum) {
    *value |= (1 << bitNum);
}

void set_bit_to_0(int *value, int bitNum) {
    *value &= ~(1 << bitNum);
}

void invert_bit(int *value, int bitNum) {
    *value ^= (1 << bitNum);
}

int get_bit(unsigned int value, int bitNum) {
    return value & (1 << bitNum);
}

void print_bits(s21_decimal src) {
    for (int i = 3; i > -1; i--) {
        for (int j = 31; j > -1; j--) {
            if (get_bit(src.bits[i], j)) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
    }
    printf("\n");
}
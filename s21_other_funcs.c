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

int is_neg(s21_decimal value) {
    int res = 0;
    if (get_bit(value.bits[3], 31)) {
        res = 1;
    }
    return res;
}

void print_bits(s21_decimal src) {
    for (int i = 3; i > -1; i--) {
        switch(i) {
            case 3: {
                printf("Дополнительные биты:\n");
                break;
            }
            case 2: {
                printf("Старшие биты:\n");
                break;
            }
            case 1: {
                printf("Средние биты:\n");
                break;
            }
            case 0: {
                printf("Младшие биты:\n");
                break;
            }
        }
        for (int j = 31; j > -1; j--) {
            if (get_bit(src.bits[i], j)) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int get_exp(s21_decimal src) {
    int exp = 0;
    int power = 1;
    for (int j = 15; j < 23; j++) {
        if (get_bit(src.bits[3], j)) {
            exp += power;
        }
        power *= 2;
    }
    return exp;
}

void set_exp(s21_decimal *dst, int exp) {
    int i = 0;
    for (int j = 15; j < 23; j++) {
        if (get_bit(exp, i)) {
            set_bit_to_1(&(dst->bits[3]), j);
        }
        i++;
    }
}

void multiply(s21_decimal *value1, int value2) {
    s21_decimal tmp;
    s21_from_int_to_decimal(value2, &tmp);
    s21_mul(*value1, tmp, value1);
}

void add(s21_decimal *value1, int value2) {
    s21_decimal tmp;
    s21_from_int_to_decimal(value2, &tmp);
    s21_add(*value1, tmp, value1);
}

void from_decimal_to_decimal(s21_decimal src, s21_decimal *dst) {
    nullify(dst);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            if (get_bit(src.bits[i], j)) {
                set_bit_to_1(&(dst->bits[i]), j);
            }
        }
    }
}

void nullify(s21_decimal *value) {
    memset(&(value->bits), 0, sizeof(value->bits));
}

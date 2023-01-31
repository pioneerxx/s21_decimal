#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int shift = 0;
    int tmp = 0;
    int res = 0;
    int neg1 = 0;
    int neg2 = 0;
    if (get_bit(value_1.bits[3], 31)) {
        neg1 = 1;
        set_bit_to_0(&(value_1.bits[3]), 31);
    }
    if (get_bit(value_2.bits[3], 31)) {
        neg2 = 1;
        set_bit_to_0(&(value_2.bits[3]), 31);
    }
    if (neg1 && !neg2) {
        if (s21_is_greater(value_1, value_2)) {
            res = s21_sub(value_1, value_2, result);
            set_bit_to_1(&(result->bits[3]), 31);
        } else {
            res = s21_sub(value_2, value_1, result);
        }
    } else if (!neg1 && neg2) {
        if (s21_is_greater(value_1, value_2)) {
                res = s21_sub(value_1, value_2, result);
        } else {
            res = s21_sub(value_2, value_1, result);
            set_bit_to_1(&(result->bits[3]), 31);
        }
    } else {
        memset(&(result->bits), 0, sizeof(result->bits));
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 32; j++) {
                shift = 0;
                if (get_bit(value_1.bits[i], j)) {
                    shift++;
                }
                if (get_bit(value_2.bits[i], j)) {
                    shift++;
                }
                shift += tmp;
                switch(shift) {
                    case 0: {
                        set_bit_to_0(&(result->bits[i]), j);
                        break;
                    }
                    case 1: {
                        set_bit_to_1(&(result->bits[i]), j);
                        if (tmp > 0) {
                            tmp--;
                        }
                        break;
                    }
                    case 2: {
                        set_bit_to_0(&(result->bits[i]), j);
                        tmp++;
                        break;
                    }
                    case 3: {
                        set_bit_to_1(&(result->bits[i]), j);
                        tmp++;
                        break;
                    }
                }
            }
        }
        if (neg1 && neg2) {
            set_bit_to_1(&(result->bits[3]), 31);
        }
        if (tmp) {
            res = 1;
        }
    }
    return res;
}
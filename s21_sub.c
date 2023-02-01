#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    memset(&(result->bits), 0, sizeof(result->bits));
    int tmp_i = 0;
    int tmp_j = 0;
    int res = 0;
    int neg1 = 0;
    int neg2 = 0;
    s21_decimal tmp;
    if (is_neg(value_1)) {
        neg1 = 1;
        set_bit_to_0(&(value_1.bits[3]), 31);
    }
    if (is_neg(value_2)) {
        neg2 = 1;
        set_bit_to_0(&(value_2.bits[3]), 31);
    }
    if (neg1 && neg2) {
        s21_sub(value_2, value_1, result);
        set_bit_to_0(&(result->bits[3]), 31);
    } else if (!neg1 && neg2) {
        s21_add(value_1, value_2, result);
    } else if (neg1 && !neg2) {
        s21_add(value_2, value_1, result);
        set_bit_to_1(&(result->bits[3]), 31);
    } else {
        if (s21_is_greater(value_2, value_1)) {
            from_decimal_to_decimal(value_1, &tmp);
            from_decimal_to_decimal(value_2, &value_1);
            from_decimal_to_decimal(tmp, &value_2);
            set_bit_to_1(&(result->bits[3]), 31);
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 32; j++) {
                if (get_bit(value_1.bits[i], j) && !get_bit(value_2.bits[i], j)) {
                    set_bit_to_1(&(result->bits[i]), j);
                } else if (!get_bit(value_1.bits[i], j) && get_bit(value_2.bits[i], j)) {
                    tmp_j = j + 1;
                    if (tmp_j == 32) {
                        tmp_i = i + 1;
                        tmp_j = 0;
                    }
                    while(!get_bit(value_1.bits[tmp_i], tmp_j)) {
                        set_bit_to_1(&(value_1.bits[tmp_i]), tmp_j);
                        tmp_j++;
                        if (tmp_j == 32) {
                            tmp_i++;
                            tmp_j = 0;
                        }
                    }
                    set_bit_to_0(&(value_1.bits[tmp_i]), tmp_j);
                    set_bit_to_1(&(result->bits[i]), j);
                }
            }
        }
    }
    return 0;
}
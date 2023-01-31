#include "s21_decimal.h"

int s21_is_greater(s21_decimal first, s21_decimal second) {
    int res = 0;
    int neg1 = 0;
    int neg2 = 0;
    if (get_bit(first.bits[3], 31)) {
        neg1 = 1;
        set_bit_to_0(&first.bits[3], 31);
    }
    if (get_bit(second.bits[3], 31)) {
        neg2 = 1;
        set_bit_to_0(&second.bits[3], 31);
    }
    for (int i = 2; i > -1; i--) {
        for (int j = 31; j > -1; j--) {
            if (get_bit(first.bits[i], j) && !get_bit(second.bits[i], j)) {
                res = 1;
                break;
            }
            if (!get_bit(first.bits[i], j) && get_bit(second.bits[i], j)) {
                break;
            }
        }
    }
    if (res && neg1 && !neg2) {
        res = 0;
    } else if (!res && !neg1 && neg2) {
        res = 1;
    } else if (!res && neg1 && neg2) {
        res = 1;
    } else if (res && neg1 && neg2) {
        res = 0;
    }
    return res;
}
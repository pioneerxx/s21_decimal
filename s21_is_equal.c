#include "s21_decimal.h"

int s21_is_equal(s21_decimal first, s21_decimal second) {
    int res = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            if (get_bit(first.bits[i], j) != get_bit(second.bits[i], j)) {
                res = 0;
                break;
            }
        }
    }
    return res;
}
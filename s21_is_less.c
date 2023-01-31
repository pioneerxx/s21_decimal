#include "s21_decimal.h"

int s21_is_less(s21_decimal first, s21_decimal second) {
    int res = 0;
    if (!s21_is_greater_or_equal(first, second)) {
        res = 1;
    }
}
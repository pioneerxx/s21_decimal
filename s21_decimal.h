#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


#define MAX 79228162514264337593543950335

typedef struct 
{
    int bits[4];
} s21_decimal;

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Comparison Operators
int s21_is_less(s21_decimal first, s21_decimal second);
int s21_is_less_or_equal(s21_decimal first, s21_decimal second);
int s21_is_greater(s21_decimal first, s21_decimal second);
int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);
int s21_is_equal(s21_decimal first, s21_decimal second);
int s21_is_not_equal(s21_decimal first, s21_decimal second);

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

//Support functions
void set_bit_to_1(int *value, int bitNum);
void set_bit_to_0(int *value, int bitNum);
void invert_bit(int *value, int bitNum);
int get_bit(unsigned int value, int bitNum);
void print_bits(s21_decimal src);
int get_exp(s21_decimal src);
void set_exp(s21_decimal *dst, int exp);
void multiply(s21_decimal *value1, int value2);
void add(s21_decimal *value1, int value2);
int is_neg(s21_decimal value);
void from_decimal_to_decimal(s21_decimal src, s21_decimal *dst);
void nullify(s21_decimal *value);

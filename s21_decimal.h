#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define get_bit(x, y) (((x)->bits[(y) / 32] & (1u << ((y) % 32))) >> ((y) % 32))
#define set_bit(x, y) ((x)->bits[(y) / 32] |= (1u << ((y) % 32)))
#define unset_bit(x, y) ((x)->bits[(y) / 32] &= ~(1u << ((y) % 32)))
#define get(x, y) ((s21_exposign *)x)->y

#define MINUS 0x80000000
#define PLUS 0xFF0000
#define MAX_DECIMAL powl(2.0, 96)
#define MIN_DECIMAL -1 * powl(2.0, 96)
#define START_INFO 96
#define FLOAT_ACCURACY 7

#define ONE_DEC ((s21_decimal){{1, 0, 0, 0}})
#define ZERO_DEC ((s21_decimal){{0, 0, 0, 0}})

#define SUCCESS 0
#define CALCULATION_ERROR 1

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct s21_exposign {
  unsigned int bits[3];
  unsigned zero1 : 16;
  unsigned expo : 8;
  unsigned zero2 : 7;
  unsigned sign : 1;
} s21_exposign;

typedef struct binaryfloat {
  unsigned int mantisse : 23;
  unsigned int expo : 8;
  unsigned int sign : 1;
} binaryfloat;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_get_bit(s21_decimal num, int bit);
void s21_set_bit(s21_decimal *num, int bit, int value);

int s21_get_sign(s21_decimal number);
void s21_set_sign(s21_decimal *num, int sign);

int s21_get_scale(s21_decimal num);
void s21_set_scale(s21_decimal *num, int scale);
int round_scale(s21_decimal *num1, s21_decimal *num2);

void s21_shift_left(s21_decimal *num, int i);

int s21_multiply(s21_decimal value, s21_decimal *res);

void s21_init(s21_decimal *num);

int s21_is_zero(s21_decimal num);

int s21_absi(int x);

int s21_goes_in_int(s21_decimal src);
int s21_get_sign_2(s21_decimal number);

int is_dec_correct(s21_decimal dec);
void init_dec(s21_decimal *dec);
int is_null(s21_decimal dec);
int unidec(s21_decimal *dec1, s21_decimal *dec2);
int add_help(s21_decimal val1, s21_decimal val2, s21_decimal *result);
int add_dev(s21_decimal val1, s21_decimal val2, s21_decimal *result, int *left);
int sub_help(s21_decimal val1, s21_decimal val2, s21_decimal *result);
int expo_down_extra(s21_decimal *dec, unsigned left);
int expo_up(s21_decimal *dec);
unsigned int mul_by_ten(s21_decimal *dec);
int expo_down(s21_decimal *dec);
int equal_help(s21_decimal dec1, s21_decimal dec2);

int bank_round(s21_decimal *dec, int digit);
int merge_dev(s21_decimal *dec, s21_decimal left_over, int *left);
void div_help(s21_decimal *value_1, s21_decimal *value_2);
int double_d_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                 s21_decimal *left_over);
void invert(s21_decimal *dec);

#endif
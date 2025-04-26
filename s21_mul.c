#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!is_dec_correct(value_1) || !is_dec_correct(value_2) || !result) return 1;
  int error = 0;
  init_dec(result);
  if (!is_null(value_1) && !is_null(value_2)) {
    s21_decimal left_over = {{0}};
    get(result, expo) = get(&value_1, expo) + get(&value_2, expo);
    get(result, sign) = get(&value_1, sign) ^ get(&value_2, sign);
    error = double_d_mul(value_1, value_2, result, &left_over);
    int carry = 0;
    error += merge_dev(result, left_over, &carry);
    error += bank_round(result, carry);
    if (error) error = get(result, sign) + 1;
  }
  return error;
}
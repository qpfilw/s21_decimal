#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!is_dec_correct(value_1) || !is_dec_correct(value_2) || !result) return 1;
  init_dec(result);
  if (is_null(value_2)) return 3;
  if (is_null(value_1)) return 0;
  int error = 0;
  div_help(&value_1, &value_2);
  int res_expo = (int)get(&value_1, expo) - (int)get(&value_2, expo);
  short res_sign = get(&value_1, sign) ^ get(&value_2, sign);
  int carry = 0;
  s21_decimal left_over = {{0}};
  while (!is_null(value_1) && !error) {
    if (equal_help(value_1, value_2) < 0) {
      s21_decimal tmp_dec = left_over;
      if (mul_by_ten(&tmp_dec))
        init_dec(&value_1);
      else {
        left_over = tmp_dec;
        add_help(left_over, (s21_decimal){{mul_by_ten(result), 0, 0, 0}},
                 &left_over);
        res_expo++;
      }
      carry = mul_by_ten(&value_1);
    }
    while (((equal_help(value_1, value_2) >= 0) || (carry > 0))) {
      carry -= sub_help(value_1, value_2, &value_1);
      if (add_help(*result, (s21_decimal){{1, 0, 0, 0}}, result)) {
        error += add_help(left_over, (s21_decimal){{1, 0, 0, 0}}, &left_over);
        init_dec(result);
      }
    }
  }
  while (is_null(left_over) && !error && res_expo < 0) {
    error += expo_up(result);
    res_expo++;
  }
  get(result, sign) = res_sign;
  if (!error) {
    get(result, expo) = res_expo;
    error = merge_dev(result, left_over, &carry);
    error += bank_round(result, carry);
  }
  if (error) {
    result->bits[0] = result->bits[1] = result->bits[2] = UINT_MAX;
    get(result, expo) = 0;
    error = get(result, sign) + 1;
  }
  return error;
}

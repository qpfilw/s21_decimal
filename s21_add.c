#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  if (!is_dec_correct(value_1) || !is_dec_correct(value_2) || !result) return 1;
  init_dec(result);
  if (is_null(value_2))
    *result = value_1;
  else if (is_null(value_1))
    *result = value_2;
  else {
    int shift = abs(unidec(&value_1, &value_2));
    get(result, sign) = (equal_help(value_1, value_2) == 1)
                            ? get(&value_1, sign)
                            : get(&value_2, sign);
    if (get(&value_1, sign) == get(&value_2, sign))
      error += add_dev(value_1, value_2, result, &shift);
    else {
      if (equal_help(value_1, value_2) == 1)
        invert(&value_1);
      else
        invert(&value_2);
      result->bits[3] ^= (1u << 31);
      get(&value_1, sign) = get(&value_2, sign) = get(result, sign);
      error += add_dev(value_1, value_2, result, &shift);
      invert(result);
      shift = -shift;
    }
    error += bank_round(result, shift);
  }
  error = error ? get(result, sign) + 1 : error;
  get(result, sign) &= !is_null(*result);
  return error;
}
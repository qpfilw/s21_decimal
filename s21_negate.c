#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  *result = value;
  int sign = s21_get_bit(value, 127);

  if (sign) {
    sign = 0;
  } else {
    sign = 1;
  }

  s21_set_bit(result, 127, sign);
  return error_code;
}

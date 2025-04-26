#include "s21_decimal.h"

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int flag = 1, sign1 = s21_get_sign(num1), sign2 = s21_get_sign(num2);

  round_scale(&num1, &num2);
  if (sign1 == sign2) {
    for (int i = 95; i >= 0; i--) {
      int bit1 = s21_get_bit(num1, i);
      int bit2 = s21_get_bit(num2, i);
      if (bit1 != bit2) {
        flag = 0;
        break;
      }
    }
  } else {
    if (s21_is_zero(num1) && s21_is_zero(num2))
      flag = 1;
    else
      flag = 0;
  }
  return flag;
}

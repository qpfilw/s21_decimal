#include "s21_decimal.h"

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  int flag = 0, end = 0;
  round_scale(&num1, &num2);

  if (s21_get_sign(num1) && !s21_get_sign(num2)) {
    flag = 1;
    end = 1;
  } else if (!s21_get_sign(num1) && s21_get_sign(num2))
    end = 1;
  for (int i = 95; i >= 0 && !end; i--) {
    int bit1 = s21_get_bit(num1, i);
    int bit2 = s21_get_bit(num2, i);
    if (bit1 != bit2) {
      if (bit1 > bit2)
        end = 1;
      else {
        flag = 1;
        end = 1;
      }
    }
  }
  if ((s21_get_sign(num1) && s21_get_sign(num2)) && end) flag = !flag;
  return flag;
}

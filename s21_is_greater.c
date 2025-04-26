#include "s21_decimal.h"

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  int flag = 0, end = 0, scale1 = s21_get_scale(num1),
      scale2 = s21_get_scale(num2), sign1 = s21_get_sign(num1),
      sign2 = s21_get_sign(num2);
  int val = round_scale(&num1, &num2);

  if (val) {
    if (scale1 > scale2) {
      flag = 0;
      end = 1;
    } else {
      flag = 1;
      end = 1;
    }
  }

  if (!sign1 && sign2) {
    if (s21_is_zero(num1) && s21_is_zero(num2))
      flag = 0;
    else
      flag = 1;
    end = 1;
  }

  for (int i = 95; i >= 0 && !end; i--) {
    int bit1 = s21_get_bit(num1, i);
    int bit2 = s21_get_bit(num2, i);

    if (bit1 != bit2) {
      if (bit1 < bit2)
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

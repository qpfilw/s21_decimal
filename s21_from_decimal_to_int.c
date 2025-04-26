#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  *dst = 0;
  s21_truncate(src, &src);
  flag = s21_goes_in_int(src);
  if (!flag) {
    *dst = src.bits[0];
    if (s21_get_sign_2(src)) *dst *= -1;
  }
  return flag;
}

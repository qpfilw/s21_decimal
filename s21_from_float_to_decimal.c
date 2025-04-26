#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  int scale = 8;
  int minus = 0;
  for (int i = 0; i < 4; i++) dst->bits[i] = 0;
  if ((fabs(src) < powl(10.0, -1 * 28)) & (fabs(src) > 0.0))
    error = 1;
  else if ((src >= MAX_DECIMAL) || (src <= MIN_DECIMAL))
    error = 1;
  else if ((src != src) || (isinf(src) == 1)) {
    error = 1;
  } else {
    if (src < 0) {
      src = -src;
      minus = 1;
    }
    unsigned int temp = (int)src;
    double tempDouble = src - temp;
    unsigned int tempInt = tempDouble * pow(10, 8);
    s21_decimal value_1 = {{temp, 0, 0, 0}};
    s21_decimal value_2 = {{tempInt, 0, 0, scale << 16}};
    s21_add(value_1, value_2, dst);
    if (minus == 1) dst->bits[3] |= MINUS;
  }
  return error;
}

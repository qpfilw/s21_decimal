#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = 0;
  double res = 0.0;
  int sign = (src.bits[3] & 0x80000000) ? -1 : 1;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      if (j == 0 && i == 0)
        res += (double)(src.bits[j] & 1);
      else
        res += pow((src.bits[j] >> i & 1) * 2, i + j * 32);
    }
  }
  for (int i = s21_get_scale(src); i > 0; i--) res /= 10;
  res *= sign;
  *dst = (float)res;
  return err;
}

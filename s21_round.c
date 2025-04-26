#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int return_val = 0;
  s21_init(result);
  float float_value = 0.0;
  s21_from_decimal_to_float(value, &float_value);
  float_value = roundf(float_value);
  if (float_value < 0.0) {
    s21_set_sign(result, 1);
    float_value *= -1;
  }
  for (int i = 0; float_value >= 1 && i < START_INFO; i++) {
    float_value = floorl(float_value) / 2;
    if (float_value - floorl(float_value) > powl(10.0, -1 * FLOAT_ACCURACY)) {
      s21_set_bit(result, i, 1);
    }
  }
  s21_set_scale(result, 0);
  return return_val;
}

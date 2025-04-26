#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_init(dst);
  if (src < 0) {
    src = s21_absi(src);
    dst->bits[3] |= (1u << 31);
  }
  memcpy((dst->bits), &src, sizeof(int));
  return 0;
}

#include "s21_decimal.h"

void s21_init(s21_decimal *num) {
  for (int i = 0; i < 4; i++) num->bits[i] = 0;
}

int s21_is_zero(s21_decimal num) {
  return (num.bits[0] == 0 && num.bits[1] == 0 && num.bits[2] == 0);
}

int s21_get_bit(s21_decimal num, int bit) {
  int res = 0;
  unsigned int mask = 1u << (bit % 32);
  if ((num.bits[bit / 32] & mask) != 0) res = 1;
  return res;
}

int s21_get_sign_2(s21_decimal number) {
  int result = 0;
  unsigned int mask = 1u << 31;
  if ((number.bits[3] & mask) != 0) result = 1;
  return result;
}

int s21_goes_in_int(s21_decimal src) {
  int flag = 0;
  for (int i = 32; i < 96 && !flag; i++)
    if (s21_get_bit(src, i)) flag = 1;
  if (!flag) flag = s21_get_bit(src, 31);
  if (!flag) flag = src.bits[0] <= 2147483647 ? 0 : 1;
  return flag;
}

void s21_set_bit(s21_decimal *num, int bit, int value) {
  if (bit >= 0 && bit < 128) {
    if (value)
      num->bits[bit / 32] |= (1u << (bit % 32));
    else
      num->bits[bit / 32] &= ~(1u << (bit % 32));
  }
}

void s21_set_sign(s21_decimal *num, int sign) {
  if (sign == 1)
    num->bits[3] |= 0x80000000;
  else if (sign == 0)
    num->bits[3] &= ~0x80000000;
}

int s21_get_sign(s21_decimal number) {
  unsigned int sign = ((unsigned int)number.bits[3] >> 31) & 1;
  return sign;
}

int s21_get_scale(s21_decimal num) { return (num.bits[3] >> 16) & 0xFF; }

void s21_set_scale(s21_decimal *num, int scale) {
  num->bits[3] &= ~(0xFF << 16);
  num->bits[3] |= (scale & 0xFF) << 16;
}

int round_scale(s21_decimal *num1, s21_decimal *num2) {
  int scale1 = s21_get_scale(*num1);
  int scale2 = s21_get_scale(*num2);

  while (scale1 < scale2) {
    s21_decimal result = {0};
    if (s21_multiply(*num1, &result) != 0) {
      return 1;
    }
    *num1 = result;
    scale1++;
  }
  while (scale2 < scale1) {
    s21_decimal result = {0};
    if (s21_multiply(*num2, &result) != 0) {
      return 1;
    }
    *num2 = result;
    scale2++;
  }

  s21_set_scale(num1, scale1);
  s21_set_scale(num2, scale2);

  return 0;
}

void s21_shift_left(s21_decimal *num, int i) {
  while (i > 0) {
    for (int j = 95; j >= 0; j--) {
      if (j == 0)
        s21_set_bit(num, j, 0);
      else
        s21_set_bit(num, j, s21_get_bit(*num, j - 1));
    }
    i--;
  }
}

int s21_multiply(s21_decimal value, s21_decimal *res) {
  s21_decimal buf = {0};
  *res = buf;
  s21_decimal value_buf1 = value, value_buf2 = value;
  int flag_shift = 0, flag = 0;

  s21_shift_left(&value_buf1, 1);
  s21_shift_left(&value_buf2, 3);

  for (int i = 0; i < 96; i++) {
    int bit1 = s21_get_bit(value_buf1, i);
    int bit2 = s21_get_bit(value_buf2, i);

    if (!bit1 && !bit2) {
      if (!flag_shift)
        s21_set_bit(res, i, 0);
      else {
        s21_set_bit(res, i, 1);
        flag_shift = 0;
      }
    } else if (bit1 && bit2) {
      s21_set_bit(res, i, flag_shift ? 1 : 0);
      flag_shift = 1;
    } else {
      s21_set_bit(res, i, flag_shift ? 0 : 1);
      flag_shift ^= 1;
    }
  }

  if (s21_get_sign(value)) s21_set_sign(res, 1);

  return flag;
}

int s21_absi(int x) { return (x < 0) ? -x : x; }

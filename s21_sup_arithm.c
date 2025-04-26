#include "s21_decimal.h"

int is_dec_correct(s21_decimal dec) {
  return !get(&dec, zero1) && !get(&dec, zero2) && get(&dec, expo) <= 28;
}

void init_dec(s21_decimal *dec) {
  dec->bits[0] = 0;
  dec->bits[1] = 0;
  dec->bits[2] = 0;
  dec->bits[3] = 0;
}

int is_null(s21_decimal dec) {
  return dec.bits[0] == 0 && dec.bits[1] == 0 && dec.bits[2] == 0;
}

int unidec(s21_decimal *dec1, s21_decimal *dec2) {
  int tmp, carry = 0;
  if (is_null(*dec1)) get(dec1, expo) = 0;
  if (is_null(*dec2)) get(dec2, expo) = 0;
  if (is_null(*dec1)) get(dec1, expo) = get(dec2, expo);
  if (is_null(*dec2)) get(dec2, expo) = get(dec1, expo);
  while (get(dec1, expo) < get(dec2, expo) && !expo_up(dec1))
    ;
  while (get(dec1, expo) > get(dec2, expo) && !expo_up(dec2))
    ;
  while (!is_null(*dec1) && !is_null(*dec2) &&
         get(dec1, expo) < get(dec2, expo) && (tmp = expo_down(dec2)) != -1)
    carry = tmp;
  while (!is_null(*dec1) && !is_null(*dec2) &&
         get(dec1, expo) > get(dec2, expo) && (tmp = expo_down(dec1)) != -1)
    carry = -tmp;
  return carry;
}

int add_help(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int error = 0;
  result->bits[0] = val1.bits[0] + val2.bits[0];
  if (result->bits[0] < val2.bits[0] || result->bits[0] < val1.bits[0]) {
    val1.bits[1]++;
    if (val1.bits[1] == 0) {
      val1.bits[2]++;
      if (val1.bits[2] == 0) error = 1;
    }
  }
  result->bits[1] = val1.bits[1] + val2.bits[1];
  if (result->bits[1] < val2.bits[1] || result->bits[1] < val1.bits[1]) {
    val1.bits[2]++;
    if (val1.bits[2] == 0) error = 1;
  }
  result->bits[2] = val1.bits[2] + val2.bits[2];
  if (result->bits[2] < val2.bits[2] || result->bits[2] < val1.bits[2])
    error = 1;
  return error;
}

int add_dev(s21_decimal val1, s21_decimal val2, s21_decimal *result,
            int *left) {
  int error = 0;
  while (error == 0 && (error = add_help(val1, val2, result))) {
    if (get(&val1, expo) && get(&val2, expo)) {
      *left = expo_down(&val1) + expo_down(&val2);
      if (*left > 9) add_help(val1, ONE_DEC, &val1);
      *left %= 10;
      error = 0;
    }
  }
  get(result, expo) = get(&val1, expo);
  while (get(result, expo) > 28) *left = expo_down(result);
  return error;
}

int sub_help(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int error = 0;
  result->bits[0] = val1.bits[0] - val2.bits[0];
  if (val2.bits[0] > val1.bits[0]) {
    val1.bits[1]--;
    if (val1.bits[1] == UINT_MAX) {
      val1.bits[2]--;
      if (val1.bits[2] == UINT_MAX) error = 1;
    }
  }
  result->bits[1] = val1.bits[1] - val2.bits[1];
  if (val2.bits[1] > val1.bits[1]) {
    val1.bits[2]--;
    if (val1.bits[2] == UINT_MAX) error = 1;
  }
  result->bits[2] = val1.bits[2] - val2.bits[2];
  if (val2.bits[2] > val1.bits[2]) error = 1;
  return error;
}

int expo_down_extra(s21_decimal *dec, unsigned left) {
  unsigned long tmp = 0UL + left;
  if (!is_null(*dec) || left)
    for (int n = 2; n >= 0; n--) {
      tmp = tmp * (UINT_MAX + 1UL) + dec->bits[n];
      dec->bits[n] = (unsigned int)(tmp / 10);
      tmp = tmp % 10;
    }
  get(dec, expo)--;
  return (int)tmp;
}

int expo_down(s21_decimal *dec) {
  if (get(dec, expo) == 0) return -1;
  return expo_down_extra(dec, 0);
}

int expo_up(s21_decimal *dec) {
  if (get(dec, expo) >= 28U) return 1;
  s21_decimal tmp = *dec;
  int error = mul_by_ten(&tmp);
  if (!error) {
    dec->bits[0] = tmp.bits[0];
    dec->bits[1] = tmp.bits[1];
    dec->bits[2] = tmp.bits[2];
    get(dec, expo)++;
  }
  return error;
}

unsigned int mul_by_ten(s21_decimal *dec) {
  unsigned error = 0;
  unsigned long tmp = 0;
  for (int n = 0; n < 3; n++) {
    tmp += 10UL * (unsigned long)dec->bits[n];
    error = tmp >> 32;
    dec->bits[n] = (unsigned int)(tmp % (UINT_MAX + 1UL));
    tmp /= (unsigned long)UINT_MAX + 1UL;
  }
  return error;
}

void invert(s21_decimal *dec) {
  for (int i = 0; i < 3; i++) {
    dec->bits[i] = ~dec->bits[i];
  }
  dec->bits[3] ^= (1u << 31);
}

int equal_help(s21_decimal dec1, s21_decimal dec2) {
  int error = 0;
  for (int i = 2; i >= 0 && !error; i--)
    error = dec1.bits[i] > dec2.bits[i]   ? 1
            : dec1.bits[i] < dec2.bits[i] ? -1
                                          : 0;

  return error;
}

int bank_round(s21_decimal *dec, int digit) {
  int error = 0;
  if (abs(digit) > 5 || (abs(digit) == 5 && get_bit(dec, 0))) {
    if (digit < 0)
      sub_help(*dec, (s21_decimal){{1, 0, 0, 0}}, dec);
    else if (add_help(*dec, (s21_decimal){{1, 0, 0, 0}}, dec)) {
      *dec = (s21_decimal){{0, 0, 0, dec->bits[3]}};
      if (get(dec, expo) > 0)
        expo_down_extra(dec, 1),
            add_help(*dec, (s21_decimal){{1, 0, 0, 0}}, dec);
      else
        error = get(dec, sign) + 1;
    }
  }
  return error;
}

int merge_dev(s21_decimal *dec, s21_decimal left_over, int *left) {
  int error = 0;
  while (!is_null(left_over) && !error) {
    error += (get(dec, expo) == 0);
    if (!error) {
      *left = expo_down_extra(&left_over, 0);
      *left = expo_down_extra(dec, *left);
    }
  }
  while (get(dec, expo) > 28) *left = expo_down(dec);
  return error;
}

void div_help(s21_decimal *value_1, s21_decimal *value_2) {
  unsigned tmp_exp = get(value_2, expo);
  get(value_2, expo) = 0;
  while (!expo_up(value_2)) tmp_exp += get(value_2, expo)--;
  get(value_2, expo) += tmp_exp;
  tmp_exp = get(value_1, expo);
  get(value_1, expo) = 0;
  while (!expo_up(value_1)) tmp_exp += get(value_1, expo)--;
  get(value_1, expo) += tmp_exp;
  tmp_exp = get(value_2, expo);
  get(value_2, expo) = 28U;
  s21_decimal tmp_dec = *value_2;
  while ((equal_help(*value_1, *value_2) < 0) && expo_down(&tmp_dec) == 0)
    *value_2 = tmp_dec;
  while (28U - get(value_2, expo) > tmp_exp)
    get(value_2, expo)++, get(value_1, expo)++;
  get(value_2, expo) = tmp_exp - (28U - get(value_2, expo));
  while (get(value_1, expo) > 0 && get(value_2, expo) > 0)
    get(value_1, expo)--, get(value_2, expo)--;
}

int double_d_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                 s21_decimal *left_over) {
  int error = 0;
  for (int i = 0; i <= 2 && !error; i++) {
    unsigned long carry = 0;
    short ind = 0;
    for (int j = 0; j < 3; j++) {
      unsigned long tmp =
          (unsigned long)value_1.bits[i] * (unsigned long)value_2.bits[j];
      tmp += carry;
      carry = tmp >> 32;
      tmp &= UINT_MAX;
      if (j + i <= 2)
        tmp += result->bits[j + i], result->bits[i + j] = (unsigned)tmp;
      else
        tmp += left_over->bits[ind], left_over->bits[ind++] = (unsigned)tmp;
      carry += tmp >> 32;
      if (carry && j == 2) {
        s21_decimal tmp_dec = {{0}};
        tmp_dec.bits[i] = (unsigned)carry;
        error += add_help(*left_over, tmp_dec, left_over);
      }
    }
  }
  return error;
}
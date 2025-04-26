#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  int end = 0;

  if (s21_is_equal(num1, num2) || s21_is_greater(num2, num1))
    end = 1;
  else
    end = 0;

  return end;
}

#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  int end = 0;
  if (s21_is_equal(num1, num2))
    end = 0;
  else
    end = 1;
  return end;
}

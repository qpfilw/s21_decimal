#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

#define TEST_ARITHMETIC_OK 0

Suite *comp_suite(void);
Suite *arithm_suite(void);
Suite *convert_suite(void);
Suite *other_suite(void);
Suite *test_add(void);
Suite *test_div(void);
Suite *test_mul(void);
Suite *test_sub(void);

#endif

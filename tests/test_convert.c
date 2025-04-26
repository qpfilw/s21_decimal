#include "test.h"

START_TEST(s21_from_float_to_decimal_1) {
  float src = 0.0000000;
  s21_decimal value_1 = {{0xffffff, 0xffffff, 0xffffff, 0xffffff}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(src, &value_1);
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  float src = 1.23456789999;
  float temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {0};
  return_value = s21_from_float_to_decimal(src, &value_1);
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 1e-06);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  float src = 7.92281625143e+30;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
  float src = 1e-29f;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  return_value = s21_from_float_to_decimal(src, &value_1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_1) {
  int src = -0;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  int src = 101;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  int src = -31325;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(src, &value_1);
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_1) {
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 1, 0}};
  return_value = s21_from_decimal_to_int(value_1, &temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  int src = 0;
  int temp = 100;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  int src = 133;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0x85, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
  float src = 0.00000000000;
  float temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_float(value_1, &temp);
  if (fabs(src - temp) < pow(10, -7)) {
    return_value = 1;
  }
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  float src = 0.0001;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0b00000000000001000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  float src = 0.0000000000000123;
  float temp = 0;
  s21_decimal value_1 = {{123, 0, 0, 0b00000000000100000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  float src = -0.0001;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000001000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_float_to_decimal_neg_1) {
  float src = -123.456;
  s21_decimal result = {0};
  int error = s21_from_float_to_decimal(src, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_negative) {
  int src = -123;
  s21_decimal result;
  s21_from_int_to_decimal(src, &result);

  s21_decimal expected = {{123, 0, 0, 0x80000000}};
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

Suite *convert_suite(void) {
  Suite *suite = suite_create("convert");
  TCase *tc_insert = tcase_create("convert_func");
  suite_add_tcase(suite, tc_insert);

  tcase_add_test(tc_insert, s21_from_float_to_decimal_1);
  tcase_add_test(tc_insert, s21_from_float_to_decimal_2);
  tcase_add_test(tc_insert, s21_from_float_to_decimal_3);
  tcase_add_test(tc_insert, s21_from_float_to_decimal_4);
  tcase_add_test(tc_insert, s21_from_int_to_decimal_1);
  tcase_add_test(tc_insert, s21_from_int_to_decimal_2);
  tcase_add_test(tc_insert, s21_from_int_to_decimal_3);
  tcase_add_test(tc_insert, s21_from_decimal_to_int_1);
  tcase_add_test(tc_insert, s21_from_decimal_to_int_2);
  tcase_add_test(tc_insert, s21_from_decimal_to_int_3);
  tcase_add_test(tc_insert, s21_from_decimal_to_float_1);
  tcase_add_test(tc_insert, s21_from_decimal_to_float_2);
  tcase_add_test(tc_insert, s21_from_decimal_to_float_3);
  tcase_add_test(tc_insert, s21_from_decimal_to_float_4);
  tcase_add_test(tc_insert, s21_from_float_to_decimal_neg_1);
  tcase_add_test(tc_insert, s21_from_int_to_decimal_negative);
  return suite;
}
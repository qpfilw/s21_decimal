#include "test.h"

START_TEST(s21_negate_1) {
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(value_1, result), 1);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_2), 1);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal value_2 = {{0, 0, 0, 0x80020000}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(value_2, value_1), 1);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal value_2 = {0};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(0.1111000, &value_2);
  int return_value = s21_truncate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_1), 1);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(1.7111000, &value_2);
  int return_value = s21_round(value_2, &result), result_int = 0;
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, 0x80020000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(2.2, &value_2);
  int return_value = s21_round(value_2, &result), result_int = 0;
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, 2);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal value_2 = {{15, 0, 0, pow(2, 16)}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal value_2 = {{15, 0, 0, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, 0, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

Suite *other_suite(void) {
  Suite *suite = suite_create("other");
  TCase *tc_insert = tcase_create("other_func");
  suite_add_tcase(suite, tc_insert);
  tcase_add_test(tc_insert, s21_negate_1);
  tcase_add_test(tc_insert, s21_negate_2);
  tcase_add_test(tc_insert, s21_truncate_1);
  tcase_add_test(tc_insert, s21_truncate_2);
  tcase_add_test(tc_insert, s21_round_1);
  tcase_add_test(tc_insert, s21_round_2);
  tcase_add_test(tc_insert, s21_round_3);
  tcase_add_test(tc_insert, s21_round_4);
  tcase_add_test(tc_insert, s21_round_5);
  tcase_add_test(tc_insert, s21_floor_1);
  tcase_add_test(tc_insert, s21_floor_2);
  tcase_add_test(tc_insert, s21_floor_3);
  return suite;
}
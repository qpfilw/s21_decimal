#include "test.h"

START_TEST(s21_add_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 10, y = 10, z = 20, result_int = 0;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_int_to_decimal(y, &value_2);
  int return_value = s21_add(value_1, value_2, &result);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, z);
}
END_TEST

START_TEST(s21_add_5) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_1 = {{1, 0, 0, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[0], 4294967294);
  ck_assert_int_eq(result.bits[1], 0xFFFFFFFF);
  ck_assert_int_eq(result.bits[2], 0xFFFFFFFF);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_add_6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 2;
  float result_float = 0, y = 1.2345678, z = x + y;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_float_to_decimal(y, &value_2);
  int return_value = s21_add(value_1, value_2, &result);
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(fabs((result_float - z)) < 1e-6, 1);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{1, 1, 1, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_add_8) {
  s21_decimal value_1 = {{23, 0, 0, 0}};
  s21_decimal value_2 = {{123, 0, 0, 0x80000000}};
  s21_decimal result = {0};
  s21_add(value_1, value_2, &result);
  int result_int;
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(result_int, -100);
}
END_TEST

START_TEST(s21_add_9) {
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal value_1 = {{123, 0, 0, 0x80000000}};
  s21_decimal result = {0};
  s21_add(value_1, value_2, &result);
  int result_int;
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(result_int, -100);
}
END_TEST

START_TEST(s21_sub_1) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result), x = 0;
  s21_from_decimal_to_int(result, &x);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
  for (int i = 0; i < 3; i++) ck_assert_int_eq(result.bits[i], 0xFFFFFFFF - 1);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{150, 0, 0, 0}};
  s21_decimal result = {0};
  int result_int = 0;
  int return_value = s21_sub(value_1, value_2, &result);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result_int, -140);
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0] + result.bits[1] + result.bits[2], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int x = 2;
  float result_float = 0, y = 1.2345678, z = x - 1.2345678;
  s21_from_int_to_decimal(x, &value_1);
  s21_from_float_to_decimal(y, &value_2);
  int return_value = s21_sub(value_1, value_2, &result);
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(fabs((result_float - z)) < 1e-6, 1);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_div_1) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_div(value_1, value_2, &result);
  float result_float = 0;
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(fabs((result_float - 1)) < 1e-7, 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal value_2 = {{0, 25, 0, 0x80000000}};
  s21_decimal value_1 = {{0, 5, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[0], 5);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_div(value_1, value_2, &result);
  float result_float = 0;
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(fabs((result_float - 0.66666)) < 1e-4, 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_from_float_to_decimal(0.1, &value_2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_mul_1) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_mul(value_2, value_1, &result), result_int = 0;
  ck_assert_int_eq(return_value, 0);
  s21_from_decimal_to_int(result, &result_int);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_mul(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal value_1 = {{15, 0, 0, 0b00000000000000100000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0xffffffff}};
  s21_decimal result = {0};
  float result_float = 0.0;
  s21_mul(value_2, value_1, &result);
  s21_from_decimal_to_float(result, &result_float);
  ck_assert_int_eq(result_float, -4.5);
}
END_TEST

Suite *arithm_suite(void) {
  Suite *suite = suite_create("arithm");
  TCase *tc_insert = tcase_create("arithm_func");
  suite_add_tcase(suite, tc_insert);

  tcase_add_test(tc_insert, s21_add_1);
  tcase_add_test(tc_insert, s21_add_2);
  tcase_add_test(tc_insert, s21_add_3);
  tcase_add_test(tc_insert, s21_add_4);
  tcase_add_test(tc_insert, s21_add_5);
  tcase_add_test(tc_insert, s21_add_6);
  tcase_add_test(tc_insert, s21_add_7);
  tcase_add_test(tc_insert, s21_add_8);
  tcase_add_test(tc_insert, s21_add_9);
  tcase_add_test(tc_insert, s21_sub_1);
  tcase_add_test(tc_insert, s21_sub_2);
  tcase_add_test(tc_insert, s21_sub_3);
  tcase_add_test(tc_insert, s21_sub_4);
  tcase_add_test(tc_insert, s21_sub_5);
  tcase_add_test(tc_insert, s21_sub_6);
  tcase_add_test(tc_insert, s21_sub_7);
  tcase_add_test(tc_insert, s21_div_1);
  tcase_add_test(tc_insert, s21_div_2);
  tcase_add_test(tc_insert, s21_div_3);
  tcase_add_test(tc_insert, s21_div_4);
  tcase_add_test(tc_insert, s21_div_5);
  tcase_add_test(tc_insert, s21_div_6);
  tcase_add_test(tc_insert, s21_mul_1);
  tcase_add_test(tc_insert, s21_mul_2);
  tcase_add_test(tc_insert, s21_mul_3);
  tcase_add_test(tc_insert, s21_mul_4);
  return suite;
}
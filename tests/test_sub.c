#include "test.h"

START_TEST(test_1) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000111111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 1);
}
END_TEST

START_TEST(test_2) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b10000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b10000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 2);
}
END_TEST

START_TEST(test_3) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);

  original.bits[0] = 0b11111111111111111111111111111110;
  original.bits[1] = 0b11111111111111111111111111111111;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_4) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000000101;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_5) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000011;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000000011;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_6) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000011;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 1);
}
END_TEST

START_TEST(test_7) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b01111000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 1);
}
END_TEST

START_TEST(test_8) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000011111111000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 1);
}
END_TEST

START_TEST(test_9) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000011111111;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);
}
END_TEST

START_TEST(test_10) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000011111111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);
}
END_TEST

START_TEST(test_11) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b10000000000000000000000000000000;

  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);
}
END_TEST

START_TEST(test_12) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000110;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);
}
END_TEST

START_TEST(test_13) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);
}
END_TEST

START_TEST(test_14) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000001010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000001000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_15) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_sub(value_1, value_2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000010010;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000010000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_16) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = UINT32_MAX;
  value_1.bits[1] = UINT32_MAX;
  value_1.bits[2] = UINT32_MAX;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 6;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0;

  get(&value_2, expo) = 1;
  s21_sub(value_1, value_2, &result);

  original.bits[0] = 0b11111111111111111111111111111110;
  original.bits[1] = 0b11111111111111111111111111111111;
  original.bits[2] = 0b11111111111111111111111111111111;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(decimal_test_sub_1) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num), "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_2) {
  s21_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0}};
  s21_decimal num2 = {{1, 1, 1, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0xfffffffd, 0xfffffffd, 0xfffffffd, 0}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num), "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_3) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{4294967294, 4294967295, 4294967295, 0}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num), "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_4) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{1, 0, 0, 0x80000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num), "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_5) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 1, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 1, 0x80000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_6) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0, 0x00030000}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{4294966295, 4294967295, 0, 0x00030000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num), "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_7) {
  s21_decimal num1 = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x00030000}};
  s21_decimal num2 = {{1, 0, 0, 0x00030000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{4294967293, 4294967295, 4294967295, 0x00030000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_8) {
  s21_decimal num1 = {{1000, 1000, 0, 0x00030000}};
  s21_decimal num2 = {{1, 1, 1, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{2000, 2000, 1000, 0x00030000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_9) {
  s21_decimal num1 = {{1000, 1000, 0, 0x00000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{2000, 2000, 1000, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_10) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x00000000}};
  s21_decimal num2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  s21_decimal num3 = {{0}};

  int error = s21_sub(num1, num2, &num3);
  ck_assert_msg(error == 1, "overflow test error");
}
END_TEST

START_TEST(decimal_test_sub_11) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal num2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num), "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_12) {
  s21_decimal num1 = {{0, 0, 0, 0x001c0000}};
  s21_decimal num2 = {{0, 0, 0, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 0, 0x001c0000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_13) {
  s21_decimal num1 = {{1, 1, 0, 0x00000000}};
  s21_decimal num2 = {{1, 1, 1, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{2, 2, 1, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_14) {
  s21_decimal num1 = {{1, 1, 0, 0x80000000}};
  s21_decimal num2 = {{1, 1, 1, 0x00000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{2, 2, 1, 0x80000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_15) {
  s21_decimal num1 = {{1, 1, 1, 0x00000000}};
  s21_decimal num2 = {{1, 1, 0, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{2, 2, 1, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_16) {
  s21_decimal num1 = {{1, 1, 1, 0x80000000}};
  s21_decimal num2 = {{1, 1, 0, 0x00000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{2, 2, 1, 0x80000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_17) {
  s21_decimal num1 = {{1, 1, 0, 0x00000000}};
  s21_decimal num2 = {{1, 1, 1, 0x00000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 1, 0x80000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_18) {
  s21_decimal num1 = {{1, 1, 1, 0x00000000}};
  s21_decimal num2 = {{1, 1, 0, 0x00000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 1, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_19) {
  s21_decimal num1 = {{1, 1, 1, 0x80000000}};
  s21_decimal num2 = {{1, 1, 0, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 1, 0x80000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_20) {
  s21_decimal num1 = {{1, 1, 0, 0x80000000}};
  s21_decimal num2 = {{1, 1, 1, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 1, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_21) {
  s21_decimal num1 = {{1, 1, 1, 0x801E0000}};
  s21_decimal num2 = {{1, 1, 0, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_22) {
  s21_decimal num1 = {{1, 1, 0, 0x80000000}};
  s21_decimal num2 = {{1, 1, 1, 0x801E0000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_23) {
  s21_decimal num1 = {{1, 1, 1, 0x80000011}};
  s21_decimal num2 = {{1, 1, 0, 0x80000000}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_24) {
  s21_decimal num1 = {{1, 1, 0, 0x80000000}};
  s21_decimal num2 = {{1, 1, 1, 0x80000011}};
  s21_decimal num3 = {{0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = s21_sub(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(s21_is_equal(num3, test_num) == 1, "s21_is_equal failed");
}
END_TEST

Suite* test_sub(void) {
  Suite* suite = suite_create("test_sub");
  TCase* tcase_core = tcase_create("sub");
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);
  tcase_add_test(tcase_core, test_10);
  tcase_add_test(tcase_core, test_11);
  tcase_add_test(tcase_core, test_12);
  tcase_add_test(tcase_core, test_13);
  tcase_add_test(tcase_core, test_14);
  tcase_add_test(tcase_core, test_15);
  tcase_add_test(tcase_core, test_16);

  tcase_add_test(tcase_core, decimal_test_sub_1);
  tcase_add_test(tcase_core, decimal_test_sub_2);
  tcase_add_test(tcase_core, decimal_test_sub_3);
  tcase_add_test(tcase_core, decimal_test_sub_4);
  tcase_add_test(tcase_core, decimal_test_sub_5);
  tcase_add_test(tcase_core, decimal_test_sub_6);
  tcase_add_test(tcase_core, decimal_test_sub_7);
  tcase_add_test(tcase_core, decimal_test_sub_8);
  tcase_add_test(tcase_core, decimal_test_sub_9);
  tcase_add_test(tcase_core, decimal_test_sub_10);
  tcase_add_test(tcase_core, decimal_test_sub_11);
  tcase_add_test(tcase_core, decimal_test_sub_12);
  tcase_add_test(tcase_core, decimal_test_sub_13);
  tcase_add_test(tcase_core, decimal_test_sub_14);
  tcase_add_test(tcase_core, decimal_test_sub_15);
  tcase_add_test(tcase_core, decimal_test_sub_16);
  tcase_add_test(tcase_core, decimal_test_sub_17);
  tcase_add_test(tcase_core, decimal_test_sub_18);
  tcase_add_test(tcase_core, decimal_test_sub_19);
  tcase_add_test(tcase_core, decimal_test_sub_20);
  tcase_add_test(tcase_core, decimal_test_sub_21);
  tcase_add_test(tcase_core, decimal_test_sub_22);
  tcase_add_test(tcase_core, decimal_test_sub_23);
  tcase_add_test(tcase_core, decimal_test_sub_24);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
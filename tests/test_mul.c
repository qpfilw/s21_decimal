#include "test.h"

START_TEST(test_1) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00000000000000000000000000000000;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_2) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00000000000000000000000000001010;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000000000000000;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000000000;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_3) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00000000000000001101010101010101;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000001010010110;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b00000010001001111010100111001110;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_4) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000010101101010;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b11111111111111111111101010010110;
  original.bits[1] = 0b00000000000000000000010101101001;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_5) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00000000000000000000000010101010;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b11111111111111111111111100000001;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b11111111111111110101011010101010;
  original.bits[1] = 0b00000000000000000000000010101001;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_6) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00000000000000000000000000000001;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000000000000001;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000000001;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
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
  value_2.bits[3] = 0b00000000000000000000000000000011;
  ck_assert_int_eq(s21_mul(value_1, value_2, &result), 1);
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
  value_2.bits[3] = 0b01111000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value_1, value_2, &result), 1);
}
END_TEST

START_TEST(test_9) {
  s21_decimal value_1, value_2, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000011111111000000000000000;
  ck_assert_int_eq(s21_mul(value_1, value_2, &result), 1);
}
END_TEST

START_TEST(test_10) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b11111111111111111111111111110110;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00111001100010111010010101100010;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b11000000100010111000101000101100;
  original.bits[1] = 0b11111111111111111111111111111101;
  original.bits[2] = 0b00111001100010111010010101100001;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_11) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00110011001100110011001100110011;
  value1.bits[1] = 0b00110011001100110011001100110011;
  value1.bits[2] = 0b00110011001100110011001100110011;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000000000000101;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b11111111111111111111111111111111;
  original.bits[1] = 0b11111111111111111111111111111111;
  original.bits[2] = 0b11111111111111111111111111111111;
  original.bits[3] = 0b00000000000000000000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_12) {
  s21_exposign value1 = {0}, value2 = {0};
  s21_decimal result = {0};

  value1.bits[0] = 0b00110011001100110011001100110011;
  value1.bits[1] = 0b00110011001100110011001100110011;
  value1.bits[2] = 0b10110011001100110011001100110011;
  value1.sign = 0;
  value1.expo = 0;

  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[2] = 0b11111111111111111111111111111111;
  value2.sign = 0;
  value2.expo = 28;

  s21_decimal* val1 = (s21_decimal*)&value1;
  s21_decimal* val2 = (s21_decimal*)&value2;
#ifdef DEBUG
  printf("Test 12: \n");
  print_dec(*val1);
  print_dec(*val2);
#endif
  int r = s21_mul(*val1, *val2, &result);
#ifdef DEBUG
  print_dec(result);
#endif
  ck_assert_int_eq(r, 1);
}
END_TEST

START_TEST(test_13) {
  s21_decimal value_1, value_2, original, result = {0};

  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value_1, value_2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000000100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b00000000000000010000000000000000;

  ck_assert_int_eq(original.bits[3], result.bits[3]);
  ck_assert_int_eq(original.bits[2], result.bits[2]);
  ck_assert_int_eq(original.bits[1], result.bits[1]);
  ck_assert_int_eq(original.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_14) {
  s21_decimal value1, value2, result = {0};

  value1.bits[0] = 0b11111111111111111111111111111111;
  value1.bits[1] = 0b11111111111111111111111111111111;
  value1.bits[2] = 0b11111111111111111111111111111111;
  value1.bits[3] = 0b10000000000000000000000000000000;

  value2.bits[0] = 0b11111111111111111111111111111111;
  value2.bits[1] = 0b11111111111111111111111111111111;
  value2.bits[2] = 0b11111111111111111111111111111111;
  value2.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 2);
}
END_TEST

START_TEST(test_15) {
  s21_decimal value1, value2, original, result = {0};

  value1.bits[0] = 0b00000000000000000000000000001010;
  value1.bits[1] = 0b00000000000000000000000000000000;
  value1.bits[2] = 0b00000000000000000000000000000000;
  value1.bits[3] = 0b00000000000000000000000000000000;

  value2.bits[0] = 0b00000000000000000000000000000010;
  value2.bits[1] = 0b00000000000000000000000000000000;
  value2.bits[2] = 0b00000000000000000000000000000000;
  value2.bits[3] = 0b10000000000001110000000000000000;
  ck_assert_int_eq(s21_mul(value1, value2, &result), 0);

  original.bits[0] = 0b00000000000000000000000000010100;
  original.bits[1] = 0b00000000000000000000000000000000;
  original.bits[2] = 0b00000000000000000000000000000000;
  original.bits[3] = 0b10000000000001110000000000000000;
  ck_assert_msg(s21_is_equal(result, original), "s21_mul test_15 failed");
}
END_TEST

START_TEST(decimal_test_mul_1) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_2) {
  s21_decimal num1 = {{357, 0, 0, 0}};
  s21_decimal num2 = {{753, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00041A15);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_3) {
  s21_decimal num1 = {{357, 357, 0, 0}};
  s21_decimal num2 = {{753, 753, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00041A15);
  ck_assert_uint_eq(num3.bits[1], 0x0008342A);
  ck_assert_uint_eq(num3.bits[2], 0x00041A15);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_4) {
  s21_decimal num1 = {{0xFF7FF9F7, 0x7FEFEF1F, 0x0037F7FF, 0}};
  s21_decimal num2 = {{793, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x736D4E1F);
  ck_assert_uint_eq(num3.bits[1], 0x4E3BBA1E);
  ck_assert_uint_eq(num3.bits[2], 0xAD5F3673);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_5) {
  s21_decimal num1 = {{0xFF7FF9F7, 0x7FEFEF1F, 0x0037F7FF, 0x001c0000}};
  s21_decimal num2 = {{793, 0, 0, 0x001c0000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
#ifdef DEBUG
  printf("test_mul_5:\n");
  print_dec(num1);
  print_dec(num2);
  print_dec(num3);
#endif
  ck_assert_msg(
      s21_is_equal(num3, (s21_decimal){{0x00000005, 0, 0, 0x001C0000}}),
      "s21_mul_5 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_6) {
  s21_decimal num1 = {{25, 0, 0, 0x00020000}};
  s21_decimal num2 = {{25, 0, 0, 0x00020000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00000271);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00040000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_7) {
  s21_decimal num1 = {{250, 7, 0, 0x80020000}};
  s21_decimal num2 = {{25, 0, 0, 0x00020000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
#ifdef DEBUG
  printf("test_mul_7:\n");
  print_dec(num1);
  print_dec(num2);
  print_dec(num3);
  print_dec((s21_decimal){{0x0000186A, 0x000000AF, 0, 0x80040000}});
#endif
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0x0000186A, 0x000000AF, 0,
                                                  0x80040000}}),
                "s21_mul_7 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_8) {
  s21_decimal num1 = {{250, 7, 0, 0x80020000}};
  s21_decimal num2 = {{25, 0, 1, 0x80020000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
#ifdef DEBUG
  printf("test_mul_8:\n");
  print_dec(num1);
  print_dec(num2);
  print_dec(num3);
  print_dec((s21_decimal){{0xB33335A4, 0x33333344, 0xB333334C, 0x00030000}});
#endif
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xB33335A4, 0x33333344,
                                                  0xB333334C, 0x00030000}}),
                "s21_mul_8 failed");
}
START_TEST(decimal_test_mul_9) {
  s21_decimal num1 = {{250, 97, 0, 0x80020000}};
  s21_decimal num2 = {{25, 0, 73, 0x80020000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
#ifdef DEBUG
  printf("test_mul_9:\n");
  print_dec(num1);
  print_dec(num2);
  print_dec(num3);
  print_dec((s21_decimal){{0xBB6AE7D6, 0x1F62B6AE, 0xB5460AA8, 0x00000000}});
#endif
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xBB6AE7D6, 0x1F62B6AE,
                                                  0xB5460AA8, 0x00000000}}),
                "s21_mul_9 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_10) {
  s21_decimal num1 = {{250, 597, 1, 0x00050000}};
  s21_decimal num2 = {{25, 0, 695, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
#ifdef DEBUG
  printf("test_mul_10:\n");
  print_dec(num1);
  print_dec(num2);
  print_dec(num3);
  print_dec((s21_decimal){{0xB4FB4E1A, 0x53D3B997, 0x4C6A837B, 0x80010000}});
#endif
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xB4FB4E1A, 0x53D3B997,
                                                  0x4C6A837B, 0x80010000}}),
                "s21_mul_10 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_11) {
  s21_decimal num1 = {{7250, 1797, 1, 0x00050000}};
  s21_decimal num2 = {{4925, 531, 3695, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xba14b106, 0xba8265ee,
                                                  0x28a08136, 0x80000000}}),
                "s21_mul_11 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_12) {
  s21_decimal num1 = {{72501935, 17973, 12345, 0x80110000}};
  s21_decimal num2 = {{492543, 5315893, 369512, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0x8403F9F4, 0x83EB9FC7,
                                                  0x3227D5B2, 0x00060000}}),
                "s21_mul_12 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_13) {
  s21_decimal num1 = {{72501935, 17973, 9123745, 0x80110000}};
  s21_decimal num2 = {{492543, 5315893, 57369512, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xD376909E, 0x8F2E6BD1,
                                                  0x398D1929, 0x00010000}}),
                "s21_mul_13 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_14) {
  s21_decimal num1 = {{72501935, 17973, 9123745, 0x80110000}};
  s21_decimal num2 = {{4925433, 53158934, 57369512, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xEC22A01B, 0xBF2D0553,
                                                  0x398D1929, 0x00010000}}),
                "s21_mul_14 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_15) {
  s21_decimal num1 = {{72501935, 1797323, 91237451, 0x80110000}};
  s21_decimal num2 = {{4925433, 53158934, 57369512, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xBCBC2420, 0x55651307,
                                                  0x398D1934, 0x00000000}}),
                "s21_mul_15 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_16) {
  s21_decimal num1 = {{1725019353, 1317397329, 392002059, 0x80110000}};
  s21_decimal num2 = {{1492543345, 2131589349, 59395259, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0xF79A2829, 0x2A948B48,
                                                  0xFFFFFFC3, 0x00000000}}),
                "s21_mul_16 failed");
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_mul_17) {
  s21_decimal num1 = {{1725019353, 1317397329, 392005059, 0x80110000}};
  s21_decimal num2 = {{1492543345, 2131589349, 59395259, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(decimal_test_mul_18) {
  s21_decimal num1 = {{2, 0, 0, 0x001c0000}};
  s21_decimal num2 = {{2, 0, 0, 0x001c0000}};
  s21_decimal num3 = {{1, 1, 1, 0x001c0000}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0}}), "s21_mul_18 failed");
}
END_TEST
START_TEST(decimal_test_mul_19) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x801E0000}};
  s21_decimal num2 = {{1, 1, 1, 0x80090000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(decimal_test_mul_20) {
  s21_decimal num1 = {{2, 0, 0, 0x001c0021}};
  s21_decimal num2 = {{2, 0, 0, 0x001c0000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(decimal_test_mul_21) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num2 = {{1, 1, 1, 0x801E0000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(decimal_test_mul_22) {
  s21_decimal num1 = {{2, 0, 0, 0x001c0000}};
  s21_decimal num2 = {{2, 0, 0, 0x001c0012}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(decimal_test_mul_23) {
  s21_decimal num1 = {{2, 0, 0, 0x001c0000}};
  s21_decimal num2 = {{2, 0, 0, 0x001c0012}};
  int error = s21_mul(num1, num2, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(decimal_test_mul_24) {
  s21_decimal num1 = {{0x88000001, 0x1F128130, 0x2027E72F, 0x1C0000}};
  s21_decimal num2 = {{1, 0, 0, 0x1C0000}};
  s21_decimal num3 = {{0}};
  int error = s21_mul(num1, num2, &num3);
#ifdef DEBUG
  printf("decimal_test_mul_24\n");
  print_dec(num1);
  print_dec(num2);
  print_dec(num3);
  print_dec((s21_decimal){{0x1, 0, 0, 0x1C0000}});
#endif
  ck_assert_int_eq(error, 0);
  ck_assert_msg(s21_is_equal(num3, (s21_decimal){{0x1, 0, 0, 0x1C0000}}),
                "s21_mul_24 failed");
}
END_TEST

Suite* test_mul(void) {
  Suite* suite = suite_create("test_mul");
  TCase* tcase_core = tcase_create("mul");
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
  tcase_add_test(tcase_core, decimal_test_mul_1);
  tcase_add_test(tcase_core, decimal_test_mul_2);
  tcase_add_test(tcase_core, decimal_test_mul_3);
  tcase_add_test(tcase_core, decimal_test_mul_4);
  tcase_add_test(tcase_core, decimal_test_mul_5);
  tcase_add_test(tcase_core, decimal_test_mul_6);
  tcase_add_test(tcase_core, decimal_test_mul_7);
  tcase_add_test(tcase_core, decimal_test_mul_8);
  tcase_add_test(tcase_core, decimal_test_mul_9);
  tcase_add_test(tcase_core, decimal_test_mul_10);
  tcase_add_test(tcase_core, decimal_test_mul_11);
  tcase_add_test(tcase_core, decimal_test_mul_12);
  tcase_add_test(tcase_core, decimal_test_mul_13);
  tcase_add_test(tcase_core, decimal_test_mul_14);
  tcase_add_test(tcase_core, decimal_test_mul_15);
  tcase_add_test(tcase_core, decimal_test_mul_16);
  tcase_add_test(tcase_core, decimal_test_mul_17);
  tcase_add_test(tcase_core, decimal_test_mul_18);
  tcase_add_test(tcase_core, decimal_test_mul_19);
  tcase_add_test(tcase_core, decimal_test_mul_20);
  tcase_add_test(tcase_core, decimal_test_mul_21);
  tcase_add_test(tcase_core, decimal_test_mul_22);
  tcase_add_test(tcase_core, decimal_test_mul_23);
  tcase_add_test(tcase_core, decimal_test_mul_24);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
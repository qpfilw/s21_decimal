#include "test.h"

void runtest(Suite *suite, int *result);

int main(void) {
  int result = 0;

  runtest(comp_suite(), &result);
  printf("\n");
  runtest(arithm_suite(), &result);
  printf("\n");
  runtest(test_add(), &result);
  printf("\n");
  runtest(test_div(), &result);
  printf("\n");
  runtest(test_mul(), &result);
  printf("\n");
  runtest(test_sub(), &result);
  printf("\n");
  runtest(convert_suite(), &result);
  printf("\n");
  runtest(other_suite(), &result);
  printf("\n");

  return 0;
}

void runtest(Suite *suite, int *result) {
  int n;
  SRunner *sr;
  sr = srunner_create(suite);
  srunner_run_all(sr, CK_NORMAL);
  n = srunner_ntests_failed(sr);
  *result += n;
  srunner_free(sr);
}

#include <check.h>

#include "test_suite.h"

#define SUITE_NAME "My Spec"

void add_test_cases(Suite *suite) {
  suite_add_tcase(suite, math_test());
}

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  add_test_cases(suite);
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}


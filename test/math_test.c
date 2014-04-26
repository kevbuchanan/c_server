#include <check.h>
#include <stdlib.h>

#include "math.h"
#include "test_suite.h"

START_TEST (test1) {
  ck_assert_int_eq(plus_one(1), 2);
} END_TEST

START_TEST (test2) {
  ck_assert_int_eq(minus_one(10), 9);
} END_TEST

TCase *math_test(void) {
  TCase *tcase = tcase_create("Math Test");
  tcase_add_test(tcase, test1);
  tcase_add_test(tcase, test2);
  return tcase;
}

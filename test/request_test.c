#include <check.h>
#include <stdlib.h>

#include "request.h"
#include "test_suite.h"

START_TEST (test_create_method) {
  Request *request = request_create(GET, "/");
  ck_assert_int_eq(GET, request->method);
  request_free(request);
} END_TEST

START_TEST (test_create_route) {
  Request *request = request_create(GET, "/");
  ck_assert_str_eq("/", request->route);
  request_free(request);
} END_TEST

TCase *request_test(void) {
  TCase *tcase = tcase_create("Request Test");
  tcase_add_test(tcase, test_create_method);
  tcase_add_test(tcase, test_create_route);
  return tcase;
}

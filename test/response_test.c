#include <check.h>
#include <stdlib.h>

#include "response.h"
#include "test_suite.h"

START_TEST (test_status) {
  Response *response = response_create();
  response_set_status(response, 200);
  ck_assert_int_eq(200, response->status);
  response_free(response);
} END_TEST

START_TEST (test_body) {
  Response *response = response_create();
  response_set_body(response, "test-body");
  ck_assert_str_eq("test-body", response->body);
  response_free(response);
} END_TEST

START_TEST (test_response_string) {
  Response *response = response_create();
  response_set_status(response, 200);
  response_set_body(response, "Test\n");
  char *expected_response = "HTTP/1.1 200 OK\r\nConnection: close\r\nContent-Length: 5\r\n\r\nTest\n";
  char *my_response = response_string(response);
  ck_assert_str_eq(expected_response, my_response);
  response_free(response);
  free(my_response);
} END_TEST

TCase *response_test(void) {
  TCase *tcase = tcase_create("Response Test");
  tcase_add_test(tcase, test_status);
  tcase_add_test(tcase, test_body);
  tcase_add_test(tcase, test_response_string);
  return tcase;
}

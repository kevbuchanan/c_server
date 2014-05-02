#include <check.h>
#include <stdlib.h>

#include "server.h"
#include "test_suite.h"

START_TEST (test_address) {
  struct sockaddr_in address = make_address(3000);
  ck_assert_int_eq(address.sin_port, htons(3000));
  ck_assert_int_eq(address.sin_family, AF_INET);
} END_TEST

TCase *server_test(void) {
  TCase *tcase = tcase_create("Server Test");
  tcase_add_test(tcase, test_address);
  return tcase;
}

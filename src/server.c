#include "server.h"
#include "response.h"

struct sockaddr_in make_address(int port) {
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(port);
  return address;
}

Response *test_response(void) {
  Response *response = response_create();
  response_set_status(response, 200);
  response_set_body(response, "Test\n");
  return response;
}

void accept_socket(int listener) {
  int connection = accept(listener, NULL, NULL);

  char requestBuffer[1000];
  read(connection, requestBuffer, 1000);
  printf("%s\n", requestBuffer);

  Response* response = test_response();
  char* output = response_string(response);
  write(connection, output, strlen(output));
  response_free(response);
  free(output);
  close(connection);
}

#include "server.h"

char *response = "HTTP/1.1 200 OK\r\nConnection: keep-alive\r\nContent-Length: 5\r\n\r\nTest\n";

struct sockaddr_in make_address(int port) {
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(port);
  return address;
}

void accept_socket(int listener) {
  int connection = accept(listener, NULL, NULL);

  char requestBuffer[1025];
  read(connection, requestBuffer, 1000);
  printf("%s\n", requestBuffer);

  char responseBuffer[1025];
  strcpy(responseBuffer, response);
  write(connection, responseBuffer, strlen(responseBuffer));
  close(connection);
}

#include "server.h"

int main(int argc, char **argv) {
  int port = 8080;
  int listener = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in address = make_address(port);
  bind(listener, (struct sockaddr*) &address, sizeof(address));
  listen(listener, 100);
  while(1) {
    accept_socket(listener);
  }
  close(listener);
  return 0;
}

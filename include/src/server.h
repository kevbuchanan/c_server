#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct sockaddr_in make_address(int port);
void accept_socket(int listener);

#endif

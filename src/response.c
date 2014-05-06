#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "response.h"

Response *response_create(void) {
  Response *response = malloc(sizeof(Response));
  response->body = NULL;
  return response;
}

void response_set_status(Response *response, int status) {
  response->status = status;
}

void response_set_body(Response *response, char *body) {
  response->body = strdup(body);
}

void response_free(Response *response) {
  free(response->body);
  free(response);
}

char *response_string(Response *response) {
  char *buffer = malloc(1000);
  strcpy(buffer, "HTTP/1.1 ");
  char status[4];
  sprintf(status, "%d", response->status);
  strcat(buffer, status);
  strcat(buffer, " OK");
  strcat(buffer, "\r\n");
  strcat(buffer, "Connection: close");
  strcat(buffer, "\r\n");
  strcat(buffer, "Content-Length: 5");
  strcat(buffer, "\r\n\r\n");
  strcat(buffer, response->body);
  return buffer;
}


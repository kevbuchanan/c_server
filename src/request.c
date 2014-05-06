#include <stdlib.h>
#include <string.h>

#include "request.h"

Request *request_create(HttpMethod method, char *route) {
  Request *request = malloc(sizeof(Request));
  request->method = method;
  request->route = strdup(route);
  return request;
}

void request_free(Request *request) {
  free(request->route);
  free(request);
}

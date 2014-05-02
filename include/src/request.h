#ifndef REQUEST_H
#define REQUEST_H

typedef enum {
  DELETE,
  GET,
  HEAD,
  OPTION,
  POST,
  PUT
} HttpMethod;

typedef struct Request {
  HttpMethod method;
  char* route;
} Request;

Request *request_create(HttpMethod method, char* route);
void request_free(Request *request);

#endif

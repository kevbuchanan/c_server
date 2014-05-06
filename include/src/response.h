#ifndef RESPONSE_H
#define RESPONSE_H

typedef struct Response {
  int status;
  char *body;
} Response;

Response *response_create(void);
void response_set_status(Response *response, int status);
void response_set_body(Response *response, char *body);
void response_free(Response *response);
char *response_string(Response *response);

#endif

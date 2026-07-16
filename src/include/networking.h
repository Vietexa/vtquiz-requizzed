#pragma once

#include "uv.h"

typedef struct app_ctx app_ctx ;


typedef struct networking_t {
    uv_loop_t *loop;
    uv_tcp_t *socket;
    uv_connect_t *connect;
    struct sockaddr_in dest;
    char *message_buf;
} networking_t;

void network_init(app_ctx *ctx);
void network_run(app_ctx *ctx);
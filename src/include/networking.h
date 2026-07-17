#pragma once

#define MAX_BUFFER_SIZE (1024 * 1024)

#include "uv.h"

typedef struct app_ctx app_ctx ;

typedef struct message_buf_t {
int size;
int capacity;
char *buf;
} message_buf_t ;

typedef struct networking_t {
    uv_loop_t *loop;
    uv_tcp_t *socket;
    uv_connect_t *connect;
    struct sockaddr_in dest;
    message_buf_t read_buf;
    message_buf_t input_buf;
    message_buf_t final_packet_buf;
} networking_t;

void network_init(app_ctx *ctx);
void network_run(app_ctx *ctx);
void network_disconnect(app_ctx *ctx);
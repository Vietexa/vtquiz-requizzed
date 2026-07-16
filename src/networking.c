#include "include/networking.h"
#include "include/app_context.h"
#include "include/button.h"
#include "uv.h"
#include <stdio.h>
#include <stdlib.h>

static void on_close(uv_handle_t *handle) {
    free(handle);
}

static void on_write_end(uv_write_t *req, int status) {
    if (status < 0) {
        fprintf(stderr, "write error: %s\n", uv_strerror(status));
        free(req);
        return;
    }
    free(req);
}

static void on_connect(uv_connect_t *req, int status) {
app_ctx *ctx = req->data;

if (status < 0) {
    fprintf(stderr, "Error connecting!\n");
    uv_close((uv_handle_t *)req->handle, on_close);
    free(req);
    return;
}

ctx->networking_ctx.message_buf = malloc(50);
snprintf(ctx->networking_ctx.message_buf,9, "hi there");

uv_buf_t buffer = uv_buf_init(ctx->networking_ctx.message_buf, 9);
uv_stream_t *tcp = req->handle;
uv_write_t *write_request = malloc(sizeof(*write_request));

uv_write(write_request, tcp, &buffer, 1, on_write_end);
}

void network_init(app_ctx *ctx){

ctx->networking_ctx.loop = uv_default_loop();
ctx->networking_ctx.socket = malloc(sizeof(uv_tcp_t));

ctx->networking_ctx.connect = malloc(sizeof(uv_connect_t));
ctx->networking_ctx.connect->data = ctx;

uv_tcp_init(ctx->networking_ctx.loop, ctx->networking_ctx.socket);

uv_ip4_addr("127.0.0.1", 7000, &ctx->networking_ctx.dest);


uv_tcp_connect(ctx->networking_ctx.connect, ctx->networking_ctx.socket, (const struct sockaddr*)&ctx->networking_ctx.dest, on_connect);

}

void network_run(app_ctx *ctx){
    uv_run(ctx->networking_ctx.loop, UV_RUN_NOWAIT);
}

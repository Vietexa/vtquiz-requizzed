#include "include/networking.h"
#include "include/app_context.h"
#include "include/button.h"
#include "include/scene.h"
#include "include/parser.h"
#include "uv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf) {
    buf->base = malloc(suggested_size);
    buf->len = suggested_size;
}

static void on_disconnect(uv_handle_t *handle){
    app_ctx *ctx = handle->data;                

    
    if (ctx->networking_ctx.input_buf.buf){
        free(ctx->networking_ctx.input_buf.buf);
        ctx->networking_ctx.input_buf.buf = NULL;
    }

    if (ctx->networking_ctx.read_buf.buf){
        free(ctx->networking_ctx.read_buf.buf);
        ctx->networking_ctx.read_buf.buf = NULL;
    }

    if (ctx->networking_ctx.connect){
        free(ctx->networking_ctx.connect);
        ctx->networking_ctx.connect = NULL;
    }
    
    if (handle){
    free(handle);
    ctx->networking_ctx.socket = NULL;
    }
    
}


static void on_write_end(uv_write_t *req, int status) {
    if (status < 0) {
        fprintf(stderr, "write error: %s\n", uv_strerror(status));
        free(req);
        return;
    }
    free(req);
}

static void read_data(uv_stream_t *server, ssize_t nread, const uv_buf_t *buf)
{
    app_ctx *ctx = server->data;

    char *read_buf = ctx->networking_ctx.read_buf.buf;
    int *size = &ctx->networking_ctx.read_buf.size;
    size_t capacity = ctx->networking_ctx.read_buf.capacity;

    if (nread < 0) {
        fprintf(stderr, "read error: %s\n", uv_strerror((int)nread));
        free(buf->base);
        uv_close((uv_handle_t *)server, on_disconnect);
        change_scene(main_menu_scene, ctx);
        return;
    }

    if (nread == 0) {
        free(buf->base);
        return;
    }

    printf("Received (%zd bytes): '%.*s'\n",
       nread, (int)nread, buf->base);


    if ((size_t)nread > capacity - *size) {
        fprintf(stderr, "message too large\n");
        free(buf->base);
        uv_close((uv_handle_t *)server, on_disconnect);
        return;
    }

    memcpy(read_buf + *size, buf->base, (size_t)nread);
    *size += (size_t)nread;
    free(buf->base);

    char *newline;

    while ((newline = memchr(read_buf, '\n', *size)) != NULL) {
        size_t message_size = (size_t)(newline - read_buf);

        printf("%.*s\n", (int)message_size, read_buf);
        parse_packet(read_buf, message_size, &ctx->parsing_ctx);
        

        size_t consumed = message_size + 1;
        *size -= consumed;

        memmove(read_buf, read_buf + consumed, *size);
    }
}

static void on_connect(uv_connect_t *req, int status) {
app_ctx *ctx = req->data;

if (status < 0) {
    fprintf(stderr, "Error connecting!\n");
    uv_close((uv_handle_t *)req->handle, on_disconnect);
    change_scene(main_menu_scene, ctx);
    return;
}
ctx->networking_ctx.input_buf.buf = malloc(9);
snprintf(ctx->networking_ctx.input_buf.buf,9, "hi there");

uv_buf_t buffer = uv_buf_init(ctx->networking_ctx.input_buf.buf, 9);
uv_stream_t *tcp = req->handle;
uv_write_t *write_request = malloc(sizeof(*write_request));

uv_write(write_request, tcp, &buffer, 1, on_write_end);


 uv_read_start((uv_stream_t *)ctx->networking_ctx.socket, alloc_buffer, read_data);
}

void network_init(app_ctx *ctx){

printf("running network init...\n");

ctx->networking_ctx.read_buf.buf = calloc(MAX_BUFFER_SIZE, sizeof(char));
ctx->networking_ctx.read_buf.capacity = MAX_BUFFER_SIZE;

ctx->networking_ctx.loop = uv_default_loop();
ctx->networking_ctx.socket = malloc(sizeof(uv_tcp_t));

ctx->networking_ctx.socket->data = ctx;

ctx->networking_ctx.connect = malloc(sizeof(uv_connect_t));
ctx->networking_ctx.connect->data = ctx;

uv_tcp_init(ctx->networking_ctx.loop, ctx->networking_ctx.socket);

uv_ip4_addr("127.0.0.1", 7000, &ctx->networking_ctx.dest);


uv_tcp_connect(ctx->networking_ctx.connect, ctx->networking_ctx.socket,
 (const struct sockaddr*)&ctx->networking_ctx.dest, on_connect);

}

void network_run(app_ctx *ctx){
    uv_run(ctx->networking_ctx.loop, UV_RUN_NOWAIT);
}

void network_disconnect(app_ctx *ctx){
    uv_close((uv_handle_t *)ctx->networking_ctx.socket,on_disconnect);
}

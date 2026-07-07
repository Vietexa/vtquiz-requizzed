#pragma once

#include "raylib.h"
#include "button.h"

typedef struct init_ctx{
int virtual_width;
int virtual_height;
RenderTexture2D target;
} init_ctx;

typedef struct app_ctx {
init_ctx init_ctx;
button_array *btn_arr;

} app_ctx;


void init_app(app_ctx *ctx);

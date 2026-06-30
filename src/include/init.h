#pragma once

#include "raylib.h"
#include "button.h"

typedef struct init_ctx{
int virtual_width;
int virtual_height;
int screen_width;
int screen_height;
RenderTexture2D target;
} init_ctx;

typedef struct app_ctx {
init_ctx init_ctx;
button button_1;

} app_ctx;


void init_app(app_ctx *ctx);

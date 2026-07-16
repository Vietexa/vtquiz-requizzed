#pragma once

typedef struct app_ctx app_ctx;

#include "raylib.h"


typedef struct init_ctx{
int virtual_width;
int virtual_height;
RenderTexture2D target;
bool keep_alive;
} init_ctx_t;

void init_app(app_ctx *ctx);

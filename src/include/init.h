#pragma once

typedef struct button_array button_array;
#include "raylib.h"
#include "button.h"


typedef struct init_ctx{
int virtual_width;
int virtual_height;
RenderTexture2D target;
} init_ctx_t;

typedef struct scene_ctx_t {
int scene_num;
void (*update_scene)(app_ctx*);
void (*draw_scene)(app_ctx*);
} scene_ctx_t;

typedef struct app_ctx {
init_ctx_t init_ctx;
scene_ctx_t scene_ctx;
button_array *btn_arr_m_menu;
button_array *btn_arr_game;


} app_ctx;


void init_app(app_ctx *ctx);

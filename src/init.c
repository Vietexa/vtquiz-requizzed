#include "include/init.h"
#include "include/scene.h"
#include "raylib.h"
#include "include/button.h"
#include <stdlib.h>


void init_app(app_ctx *ctx){
InitWindow(1920, 1080, "Online Quiz");

    ToggleFullscreen();

    ctx->init_ctx.target = LoadRenderTexture(ctx->init_ctx.virtual_width, ctx->init_ctx.virtual_height);

    SetTargetFPS(60);

    scene_select(ctx);

    ctx->btn_arr = calloc(1, sizeof(button_array));
    
    ctx->btn_arr->btn = button_allocate(5, ctx->btn_arr);

    button_create(ctx->btn_arr, 500, 500,
    200, 100, RED, ORANGE, "Hi there!", 20, WHITE, main_menu_scene);

    button_create(ctx->btn_arr, 1000, 500,
    200, 100, RED, ORANGE, "What's up?", 20, WHITE , main_menu_scene);
    
    
    
   
}
#include "include/init.h"
#include "raylib.h"
#include "include/button.h"


void init_app(app_ctx *ctx){
InitWindow(1920, 1080, "Online Quiz");

    ctx->init_ctx.screen_width = GetScreenWidth();
    ctx->init_ctx.screen_height = GetScreenHeight();

    ToggleFullscreen();

    ctx->init_ctx.target = LoadRenderTexture(ctx->init_ctx.virtual_width, ctx->init_ctx.virtual_height);

    SetTargetFPS(60);
    
    button_create(&ctx->button_1, 500, 500,
    200, 100, RED, ORANGE, "Hi there!", 20, WHITE);
    
    
    
   
}
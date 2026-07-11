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

    ctx->btn_arr_game = calloc(1, sizeof(button_array));
    ctx->btn_arr_m_menu = calloc(1, sizeof(button_array));
    
    ctx->btn_arr_game->btn = button_allocate(5, ctx->btn_arr_game);
    ctx->btn_arr_m_menu->btn = button_allocate(5, ctx->btn_arr_m_menu);

    button_create(ctx->btn_arr_m_menu, 900, 400,
    200, 100, RED, ORANGE, "Play", 20, WHITE, main_menu_scene);

    button_create(ctx->btn_arr_m_menu, 900, 550,
    200, 100, RED, ORANGE, "Quit", 20, WHITE , main_menu_scene);

    button_create(ctx->btn_arr_game, 50, 950,
    200, 100, RED, ORANGE, "Go back!", 20, WHITE, game_scene);
    
    
    
   
}
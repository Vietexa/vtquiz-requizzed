#include "include/scene.h"
#include "include/button.h"
#include "include/draw.h"
#include "include/init.h"
#include "include/update.h"


void scene_select(app_ctx *ctx){

    switch (ctx->scene_ctx.scene_num) {
    
    case main_menu_scene:
    ctx->scene_ctx.update_scene = update_main_menu;
    ctx->scene_ctx.draw_scene = draw_main_menu;
    break;
    
    case game_scene:
    ctx->scene_ctx.update_scene = update_game;
    ctx->scene_ctx.draw_scene = draw_game;
     break;
    }
}

void change_scene(int number, app_ctx *ctx){
    if (number < 0) return;

    ctx->scene_ctx.scene_num = number;
    scene_select(ctx);
}


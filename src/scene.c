#include "include/scene.h"
#include "include/draw.h"
#include "include/init.h"
#include "include/update.h"


void scene_select(app_ctx *ctx){

    switch (ctx->scene_ctx.scene_num) {
    
    case main_menu_scene:
    ctx->scene_ctx.update_scene = update_main_menu;
    ctx->scene_ctx.draw_scene = draw_main_menu;
    }
}


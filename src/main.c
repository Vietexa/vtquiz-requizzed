
#include "include/button.h"
#include "include/init.h"
#include "include/scene.h"
#include "include/cleanup.h"
#include "include/app_context.h"

#include "raylib.h"
#include <stdlib.h>


int main(void){

    app_ctx *ctx = calloc(1,sizeof(app_ctx));
    ctx->init_ctx.virtual_width = 1920;
    ctx->init_ctx.virtual_height = 1080;
    ctx->init_ctx.keep_alive = true;
    ctx->scene_ctx.scene_num = main_menu_scene;
    ctx->scene_ctx.subscene_num = 0;
    init_app(ctx);
    
    while (!WindowShouldClose() && ctx->init_ctx.keep_alive)    
    {
        
       ctx->scene_ctx.update_scene(ctx);
       ctx->scene_ctx.draw_scene(ctx);
       
    }

    cleanup(ctx);
   
    return 0;
}


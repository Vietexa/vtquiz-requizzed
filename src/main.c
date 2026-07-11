
#include "include/init.h"
#include "include/draw.h"
#include "include/scene.h"
#include "include/update.h"
#include "include/cleanup.h"

#include "raylib.h"
#include <stdlib.h>


int main(void){

    app_ctx *ctx = calloc(1,sizeof(app_ctx));
    ctx->init_ctx.virtual_width = 1920;
    ctx->init_ctx.virtual_height = 1080;
    ctx->scene_ctx.scene_num = main_menu_scene;
    init_app(ctx);
    
    while (!WindowShouldClose())    
    {
        
       ctx->scene_ctx.update_scene(ctx);
       ctx->scene_ctx.draw_scene(ctx);
       
    }

    cleanup(ctx);
   
    return 0;
}


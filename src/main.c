
#include "include/button.h"
#include "include/init.h"
#include "include/draw.h"
#include "include/update.h"
#include "include/utils.h"

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>



int main(void){

    app_ctx *ctx = calloc(1,sizeof(app_ctx));
    ctx->init_ctx.virtual_width = 1920;
    ctx->init_ctx.virtual_height = 1080;

    init_app(ctx);
    
    while (!WindowShouldClose())    
    {
        if (button_clicked(&ctx->btn_arr->btn[0], get_mouse_coords(ctx))){
            printf("the button was pressed!\n");
        }
        if (button_clicked(&ctx->btn_arr->btn[1], get_mouse_coords(ctx))){
            printf("the 2nd button was pressed!\n");
        }
       
        draw(ctx);
       
    }

    UnloadRenderTexture(ctx->init_ctx.target);
    CloseWindow(); 
    button_deallocate(ctx->btn_arr);
    free(ctx);       
   
    return 0;
}



#include "include/init.h"
#include "include/draw.h"
#include "include/update.h"
#include "include/cleanup.h"

#include "raylib.h"
#include <stdlib.h>


int main(void){

    app_ctx *ctx = calloc(1,sizeof(app_ctx));
    ctx->init_ctx.virtual_width = 1920;
    ctx->init_ctx.virtual_height = 1080;

    init_app(ctx);
    
    while (!WindowShouldClose())    
    {
        update(ctx);
       
        draw(ctx);
       
    }

    cleanup(ctx);
   
    return 0;
}


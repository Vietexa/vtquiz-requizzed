#include "include/cleanup.h"
#include "include/init.h"
#include <stdlib.h>

void cleanup(app_ctx *ctx){

    UnloadRenderTexture(ctx->init_ctx.target);
    CloseWindow(); 
    button_deallocate(ctx->btn_arr);
    free(ctx);   
     
}
#include "include/cleanup.h"
#include "include/button.h"
#include "include/app_context.h"
#include "include/init.h"
#include <stdlib.h>

void cleanup(app_ctx *ctx){

    UnloadRenderTexture(ctx->init_ctx.target);
    CloseWindow(); 
    button_deallocate(ctx->btn_arr_game);
    button_deallocate(ctx->btn_arr_m_menu);
    free(ctx);   
     
}

#include "include/update.h"
#include "include/button.h"
#include "include/utils.h"
#include "include/init.h"
#include <stdio.h>


void update(app_ctx *ctx){

if (button_clicked(&ctx->btn_arr->btn[0], get_mouse_coords(ctx))){
            printf("the button was pressed!\n");
        }
        if (button_clicked(&ctx->btn_arr->btn[1], get_mouse_coords(ctx))){
            printf("the 2nd button was pressed!\n");
        }


}
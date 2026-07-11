
#include "include/update.h"
#include "include/button.h"
#include "include/utils.h"
#include "include/init.h"
#include "include/scene.h"
#include <stdio.h>


void update_main_menu(app_ctx *ctx){

if (button_clicked(&ctx->btn_arr_m_menu->btn[button_play], get_mouse_coords(ctx), ctx)){
            printf("Changing scene...\n");
            change_scene(game_scene, ctx);
            
        }

        if (button_clicked(&ctx->btn_arr_m_menu->btn[button_quit], get_mouse_coords(ctx), ctx)){
            printf("Quitting game\n");
            ctx->init_ctx.keep_alive = false;
        }


}

void update_game(app_ctx *ctx){
if (button_clicked(&ctx->btn_arr_game->btn[0], get_mouse_coords(ctx), ctx)){
            printf("going back\n");
            change_scene(main_menu_scene, ctx);
            
        }
}
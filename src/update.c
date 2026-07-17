
#include "include/update.h"
#include "include/button.h"
#include "include/networking.h"
#include "include/utils.h"
#include "include/init.h"
#include "include/scene.h"
#include "include/app_context.h"
#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>



static void init_game_scene(app_ctx *ctx){
    if (ctx->scene_ctx.is_first_frame){
        network_init(ctx);
        // set it false so this happens only once
        ctx->scene_ctx.is_first_frame = false;
    }
}

void update_main_menu(app_ctx *ctx){

if (button_clicked(&ctx->btn_arr_m_menu->btn[button_play], get_mouse_coords(ctx), ctx)){
            printf("Changing scene...\n");
            change_scene(game_scene, ctx);
            
        }

if (button_clicked(&ctx->btn_arr_m_menu->btn[button_quit], get_mouse_coords(ctx), ctx)){
            printf("Quitting game\n");
            ctx->init_ctx.keep_alive = false;
        }

if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    store_mpos(ctx);
    printf("Clicked: x: %f y: %f\n", ctx->mouse_positions.x, ctx->mouse_positions.y);
}



}

void update_game(app_ctx *ctx){
    init_game_scene(ctx);

    if (button_clicked(&ctx->btn_arr_game->btn[0], get_mouse_coords(ctx), ctx)){
            printf("going back\n");
            network_disconnect(ctx);
            change_scene(main_menu_scene, ctx);
        }
    network_run(ctx);
    
}
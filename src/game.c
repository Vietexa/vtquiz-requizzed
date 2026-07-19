#include "include/main_menu.h"
#include "include/app_context.h"
#include "include/utils.h"

static void init_game_scene(app_ctx *ctx){
    if (ctx->scene_ctx.is_first_frame){
        network_init(ctx);
        // set it false so this happens only once
        ctx->scene_ctx.is_first_frame = false;
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

void draw_game(app_ctx *ctx){

    BeginTextureMode(ctx->init_ctx.target);
        ClearBackground(BLACK);
        button_draw(&ctx->btn_arr_game->btn[0],ctx);
    EndTextureMode();

    BeginDrawing();

    ClearBackground(BLACK);

    DrawTexturePro(
    ctx->init_ctx.target.texture,
    (Rectangle){ 0, 0, ctx->init_ctx.virtual_width, -ctx->init_ctx.virtual_height },
    (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
    (Vector2){ 0, 0 },
    0.0f,
    WHITE
        );

        EndDrawing();

}
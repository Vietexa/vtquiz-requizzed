#include "include/main_menu.h"
#include "include/app_context.h"
#include "include/utils.h"

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

void draw_main_menu(app_ctx *ctx){

    BeginTextureMode(ctx->init_ctx.target);
        ClearBackground(BLACK);
        DrawText("VTQuiz: Requizzed", 850, 300, 35, WHITE);
        button_draw(&ctx->btn_arr_m_menu->btn[button_play],ctx);
        button_draw(&ctx->btn_arr_m_menu->btn[button_quit], ctx);
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

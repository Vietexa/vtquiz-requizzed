#include "include/draw.h"
#include "include/button.h"
#include "include/app_context.h"
#include "include/init.h"
#include "raylib.h"


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
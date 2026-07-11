#include "include/draw.h"
#include "include/button.h"
#include "include/init.h"
#include "raylib.h"


void draw_main_menu(app_ctx *ctx){

    BeginTextureMode(ctx->init_ctx.target);
        DrawText("Congrats! You created your first window!", 10, 5, 20, WHITE);
        button_draw(&ctx->btn_arr->btn[play],ctx);
        button_draw(&ctx->btn_arr->btn[quit], ctx);
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
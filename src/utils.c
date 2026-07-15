#include "include/utils.h"
#include "include/button.h"
#include "include/init.h"
#include "raylib.h"

Vector2 get_mouse_coords(app_ctx *ctx){
    Vector2 mouse = GetMousePosition();

    float scale_x = (float)GetScreenWidth() / ctx->init_ctx.virtual_width;
    float scale_y = (float)GetScreenHeight() / ctx->init_ctx.virtual_height;

    Vector2 mouse_virtual = {
        .x = mouse.x / scale_x,
        .y = mouse.y / scale_y
    };

    return mouse_virtual;
}

void store_mpos(app_ctx *ctx){
    Vector2 mouse_pos = get_mouse_coords(ctx);
    
    ctx->mouse_positions.x = mouse_pos.x;
    ctx->mouse_positions.y = mouse_pos.y;
}
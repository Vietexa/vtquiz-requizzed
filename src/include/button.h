#pragma once

typedef struct app_ctx app_ctx;

#include "init.h"
#include "raylib.h"
#include <stdbool.h>

typedef struct button {
    float pos_x;
    float pos_y;
    float width;
    float height;
    Color btn_color;
    Color btn_hover_color;
    int font_size;
    Color text_color;
    int scene_id;
    bool is_hovered;
    bool is_pressed;
    char text[100];
} button;

typedef struct button_array {
    button *btn;
    int size;
    int capacity;
} button_array;

enum buttons {
    button_play, 
    button_quit
};


bool button_create(button_array *btn_arr, float pos_x, float pos_y, float width, float height,
 Color btn_color, Color btn_hover_color, char* text, int font_size, Color text_color, int scene_id);

void button_draw(button *btn, app_ctx *ctx);

bool button_clicked(button *btn, Vector2 mpos, app_ctx *ctx);

button *button_allocate(int n, button_array *btn_arr);

void button_deallocate(button_array *btn_arr);


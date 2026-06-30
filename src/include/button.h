#pragma once
#include "raylib.h"
#include <stdbool.h>

typedef struct button {
    float pos_x;
    float pos_y;
    float width;
    float height;
    Color btn_color;
    Color btn_hover_color;
    char text[100];
    int font_size;
    Color text_color;
    bool is_hovered;
    bool is_pressed;
} button;

bool button_create(button *btn, float pos_x, float pos_y, float width, float height,
 Color btn_color, Color btn_hover_color, char* text, int font_size, Color text_color);

void button_draw(button *btn);

bool button_clicked(button *btn, Vector2 mpos);


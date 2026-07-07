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
    int font_size;
    Color text_color;
    bool is_hovered;
    bool is_pressed;
    char text[100];
} button;

typedef struct button_array {
    button *btn;
    int size;
    int capacity;
} button_array;


bool button_create(button_array *btn_arr, float pos_x, float pos_y, float width, float height,
 Color btn_color, Color btn_hover_color, char* text, int font_size, Color text_color);

void button_draw(button *btn);

bool button_clicked(button *btn, Vector2 mpos);

button *button_allocate(int n, button_array *btn_arr);

void button_deallocate(button_array *btn_arr);


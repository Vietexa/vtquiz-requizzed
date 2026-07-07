#include "include/button.h"

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool button_create(button_array *btn_arr, float pos_x, float pos_y, float width, float height,
 Color btn_color, Color btn_hover_color, char* text, int font_size, Color text_color)
{
int text_capacity = sizeof(btn_arr->btn[btn_arr->size].text);

if (text == NULL)
    return false;

if (strlen(text) >= text_capacity) false;

btn_arr->btn[btn_arr->size].pos_x = pos_x;
btn_arr->btn[btn_arr->size].pos_y = pos_y;
btn_arr->btn[btn_arr->size].width = width;
btn_arr->btn[btn_arr->size].height = height;
btn_arr->btn[btn_arr->size].btn_color = btn_color;
btn_arr->btn[btn_arr->size].btn_hover_color = btn_hover_color;
snprintf(btn_arr->btn[btn_arr->size].text, text_capacity,"%s",text );
btn_arr->btn[btn_arr->size].font_size = font_size;
btn_arr->btn[btn_arr->size].text_color = text_color;
btn_arr->btn[btn_arr->size].is_hovered = false;
btn_arr->btn[btn_arr->size].is_pressed = false;

btn_arr->size++;

return true;
}

void button_draw(button *btn){

if (btn->is_hovered){
    DrawRectangle(btn->pos_x, btn->pos_y, btn->width, 
btn->height, btn->btn_hover_color);
}

else {
    DrawRectangle(btn->pos_x, btn->pos_y, btn->width, 
btn->height, btn->btn_color);
}

int text_width = MeasureText(btn->text, btn->font_size);

int text_pos_x = btn->pos_x + (btn->width - text_width) / 2;
int text_pos_y = btn->pos_y + (btn->height - btn->font_size) / 2;


DrawText(btn->text, text_pos_x,
 text_pos_y, btn->font_size, btn->text_color);

}

bool button_clicked(button *btn, Vector2 mpos){
Rectangle btn_rect = {btn->pos_x, btn->pos_y, btn->width, btn->height};

if (CheckCollisionPointRec(mpos, btn_rect)){
    btn->is_hovered = true;


    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
       btn->is_pressed = true;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && btn->is_pressed){
        btn->is_pressed = false;
        return true;
    }

}

else{
    btn->is_hovered = false;
    btn->is_pressed = false;
}
 return false;
}

button *button_allocate(int n, button_array *btn_arr){
    if (n < 1) return NULL;

    button *btn = calloc(n, sizeof(button));
    btn_arr->capacity = n;
    btn_arr->size = 0;
    return btn;
}

void button_deallocate(button_array *btn_arr){
    free(btn_arr->btn);
    free(btn_arr);
}

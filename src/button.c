#include "include/button.h"

#include "raylib.h"
#include <stdio.h>
#include <string.h>

bool button_create(button *btn, float pos_x, float pos_y, float width, float height,
 Color btn_color, Color btn_hover_color, char* text, int font_size, Color text_color)
{
int text_capacity = sizeof(btn->text);

if (btn == NULL || text == NULL)
    return false;

if (strlen(text) >= text_capacity) false;

btn->pos_x = pos_x;
btn->pos_y = pos_y;
btn->width = width;
btn->height = height;
btn->btn_color = btn_color;
btn->btn_hover_color = btn_hover_color;
snprintf(btn->text, text_capacity,"%s",text );
btn->font_size = font_size;
btn->text_color = text_color;
btn->is_hovered = false;
btn->is_pressed = false;

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
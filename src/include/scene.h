#pragma once

#include "init.h"

enum scenes_t {
   main_menu_scene,
   game_scene 
};

typedef struct scene_ctx_t {
int scene_num;
int subscene_num;
void (*update_scene)(app_ctx*);
void (*draw_scene)(app_ctx*);
bool is_first_frame;
} scene_ctx_t;

void scene_select(app_ctx *ctx);
void change_scene(int number, app_ctx *ctx);
#pragma once

#include "init.h"
enum scenes_t {
   main_menu_scene,
   game_scene 
};

void scene_select(app_ctx *ctx);
void change_scene(int number, app_ctx *ctx);
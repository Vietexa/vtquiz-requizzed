
#include "button.h"
#include "networking.h"
#include "scene.h"

typedef struct app_ctx {
init_ctx_t init_ctx;
scene_ctx_t scene_ctx;
networking_t networking_ctx;
Vector2 mouse_positions;
button_array *btn_arr_m_menu;
button_array *btn_arr_game;

} app_ctx;
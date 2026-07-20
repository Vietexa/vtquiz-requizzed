#pragma once

#define MAX_KEYS 10
#define MAX_VALUES 10

#include <stdbool.h>
typedef struct parsing_res_t{
    char *key_positions[MAX_KEYS];
    char *value_positions[MAX_VALUES];
    int pair_count;
} parsing_res_t;

bool parse_packet(char *buffer, int nread, parsing_res_t *res);
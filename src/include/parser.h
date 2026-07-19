#pragma once

typedef struct parsing_res_t{
    char *key_positions[10];
    char *value_positions[10];
} parsing_res_t;

void parse_packet(char *buffer, int nread, parsing_res_t *res);
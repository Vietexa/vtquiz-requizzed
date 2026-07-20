#include "include/parser.h"
#include <stdio.h>
#include <stdlib.h>

bool parse_packet(char *buffer, int nread, parsing_res_t *res){
    // Purpose: Parse the packet and store the position of the keys
    // and the values in their containers

    if (buffer == NULL || res == NULL || nread == 0) return false;


    char *start = buffer;
    res->pair_count = 0;
    int param_count = 0;
    int key_count = 0;
    int val_count = 0;

    for (int i = 0; i < nread; i++){
    
        if (buffer[i] == '|'){
            param_count++;
            buffer[i] = '\0';
        
            if (param_count % 2 == 0) {

                if (val_count >= MAX_VALUES){
                    fprintf(stderr, "Error: More values than space\n");
                    return false;
                }

                res->value_positions[val_count] = start;
                val_count++;
            }

            else{
                if (key_count >= MAX_KEYS){
                    fprintf(stderr, "Error: More keys than space\n");
                    return false;
                }
                res->key_positions[key_count] = start;
                key_count++;
            }
            start = &buffer[i + 1];
    }
}
    if (param_count % 2 == 0) {
        if (key_count >= MAX_KEYS){
            fprintf(stderr, "Error: More keys than space\n");
             return false;
        }
        res->key_positions[key_count++] = start;
    } 

    else {
        if (val_count >= MAX_VALUES){
            fprintf(stderr, "Error: More values than space\n");
            return false;
         }
        res->value_positions[val_count++] = start;
    }

     if (key_count != val_count) {
        fprintf(stderr, "Error: Key without a matching value\n");
        return false;
    }
    
    // store the pair count value as you might need it later
    res->pair_count = key_count;


    return true;
}
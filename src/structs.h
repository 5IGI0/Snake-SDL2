#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <stdint.h>

typedef struct {
    uint8_t x;
    uint8_t y;
} pos_t;

typedef enum {
    UP,
    DOWN,
    RIGHT,
    LEFT
} direction_t;

#endif
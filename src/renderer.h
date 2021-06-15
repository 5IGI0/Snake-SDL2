#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SDL2/SDL.h>

#include "structs.h"

void render(SDL_Renderer *renderer, pos_t *snake, uint16_t snakeSize, pos_t apple);

#endif
#include <SDL2/SDL.h>

#include "defines.h"
#include "structs.h"

void renderer_draw_entity(SDL_Renderer *renderer, pos_t pos, uint8_t r, uint8_t g, uint8_t b);

void render(SDL_Renderer *renderer, pos_t *snake, uint16_t snakeSize, pos_t apple) {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    renderer_draw_entity(renderer, apple, 255, 0, 0);

    for (size_t i = 0; i < snakeSize; i++) {
        renderer_draw_entity(renderer, snake[i], 0, (((float)(snakeSize-i)/snakeSize)*(255-SNAKE_MIN_INTENSITY))+SNAKE_MIN_INTENSITY, 0);
    }

    SDL_RenderPresent(renderer);

}

void renderer_draw_entity(SDL_Renderer *renderer, pos_t pos, uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

    SDL_Rect rect = {};

    rect.h = CELL_SIZE-BORDER_SIZE;
    rect.w = CELL_SIZE-BORDER_SIZE;
    rect.x = (pos.x*CELL_SIZE)+BORDER_SIZE;
    rect.y = (pos.y*CELL_SIZE)+BORDER_SIZE;

    SDL_RenderFillRect(renderer, &rect);
}
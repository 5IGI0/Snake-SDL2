#include <SDL2/SDL.h>

#include <time.h>

#include "defines.h"
#include "renderer.h"
#include "structs.h"
#include "process.h"

int main(int argc, char const *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint16_t snakeSize = 3;
    direction_t direction = RIGHT;
    pos_t snake[MAP_WIDTH*MAP_HEIGHT] = {
        {(MAP_WIDTH/2), (MAP_HEIGHT/2)},
        {(MAP_WIDTH/2)-1, (MAP_HEIGHT/2)},
        {(MAP_WIDTH/2)-2, (MAP_HEIGHT/2)},
    };

    srand(time(NULL));

    pos_t apple = {rand()%MAP_WIDTH, rand()%MAP_HEIGHT};

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Snake",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CELL_SIZE*MAP_WIDTH,
        CELL_SIZE*MAP_HEIGHT,
        0
    );


    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        printf("Could not create renderer: %s\n", SDL_GetError());
        return 1;
    }

    while(1) {
        render(renderer, snake, snakeSize, apple);
        SDL_Delay(FRAME_INTERVAL);
        if (update(window, snake, &snakeSize, &direction, &apple))
            break;
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "defines.h"
#include "structs.h"

void read_events(direction_t *direction);
void update_title(SDL_Window *window, int score);

int update(SDL_Window *window, pos_t *snake, uint16_t *snakeSize, direction_t *direction, pos_t *apple) {

    direction_t dirtmp = *direction;

    read_events(direction);

    for (int i = *snakeSize-2; i >= 0; i--)
        snake[i+1] = snake[i];

    switch (*direction) {
        case RIGHT: snake[0].x += 1; break;
        case LEFT:  snake[0].x -= 1; break;
        case UP:    snake[0].y -= 1; break;
        case DOWN:  snake[0].y += 1; break;
    }

    if (snake[0].y >= MAP_HEIGHT || snake[0].x >= MAP_WIDTH)
        return __LINE__;

    if (snake[0].x == apple[0].x && snake[0].y == apple[0].y) {
        *snakeSize += 1;
        snake[*snakeSize-1] = snake[*snakeSize-2];

        apple[0].x = rand()%MAP_WIDTH;
        apple[0].y = rand()%MAP_HEIGHT;

        update_title(window, *snakeSize-3);
    }

    for (size_t i = 1; i < *snakeSize; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return __LINE__;
    }
    
    return 0;
}

void read_events(direction_t *direction) {
    SDL_Event event;
    direction_t tmp = *direction;

    while (SDL_PollEvent(&event)) {

        if(event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:    tmp = (*direction == DOWN) ? DOWN : UP; break;
                case SDLK_DOWN:  tmp = (*direction == UP) ? UP : DOWN; break;
                case SDLK_RIGHT: tmp = (*direction == LEFT) ? LEFT : RIGHT; break;
                case SDLK_LEFT:  tmp = (*direction == RIGHT) ? RIGHT : LEFT; break;
            }
        } else if (event.type == SDL_QUIT) {
            exit(__LINE__);
        }

    }

    *direction = tmp;
}

void update_title(SDL_Window *window, int score) {
    char buff[50] = "";

    snprintf(buff, 50, "Snake (score: %d)", score);

    SDL_SetWindowTitle(window, buff);
}
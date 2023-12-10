#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/memory-manipulation.h"
#include "headers/front.h"

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font *font_header = NULL;
    TTF_Font *font_numbers = NULL;
    int completed_bars = 0;
    int number_bars = 120;
    int clock = 50;
    float q1, q2;

    srand(time(NULL));

    TTF_Init();

    font_header = TTF_OpenFont("fonts/Comprehension-SemiBold.ttf", 24);
    if (font_header == NULL) {
        fprintf(stderr, "Erro: fonte não encontrada.\n");
        exit(EXIT_FAILURE);
    }

    font_numbers = TTF_OpenFont("fonts/Comprehension-SemiBold.ttf", 24);
    if (font_numbers == NULL) {
        fprintf(stderr, "Erro: fonte não encontrada.\n");
        exit(EXIT_FAILURE);
    }
    

    if ( SDL_Init(SDL_INIT_VIDEO) == 0 ){
        window = SDL_CreateWindow("Heap usage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOWS_WIDTH, WINDOWS_HIGH, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    else
        SDL_Log("Erro na inicialização: %s", SDL_GetError());

    if ( window != NULL ){
        int i = 0;
        SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a); 
        SDL_RenderClear(renderer);
        while( !SDL_QuitRequested() ) {
            draw_headers("Reference Counting", "Mark-and-Sweep", renderer, font_header);
            
            if(i<=number_bars){
                manipulation2(&q1,&q2);
                draw_lines(renderer);
                draw_bar_ref(renderer, i, q1);
                draw_bar_mark(renderer, i, q2);
                completed_bars++;
                SDL_RenderPresent(renderer);
                i++;
                SDL_Delay(clock);
            }
        }
    }
    else
        SDL_Log("Erro na criação da janela: %s", SDL_GetError());

    TTF_CloseFont(font_header);
    TTF_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
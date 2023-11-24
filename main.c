#include <stdio.h>
#include <stdlib.h>
#include "headers/contagem-referencia.h"
#include "headers/front.h"
#include <time.h>

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* header_texture = NULL;
    SDL_Texture* time_texture;
    SDL_Rect header_rect;
    TTF_Font *font = NULL;
    int completed_bars = 0;
    int number_bars = 120;
    int time = 100;

    TTF_Init();

    font = TTF_OpenFont("fonts/Go-Bold.ttf", 24);
    if (font == NULL) {
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
        
        while( !SDL_QuitRequested() ) {
            SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a); 
            SDL_RenderClear(renderer);
            draw_headers("Contagem por referencia", "Mark-and-Sweep", renderer, font, &header_texture, &header_rect);
            
            if (completed_bars != number_bars){
                for(int i = 0; i<number_bars; i++){ 
                    if(i <= 100){
                        draw_bar_ref(renderer, i, i*0.01);
                        draw_lines(renderer);
                    }else{
                        draw_bar_ref(renderer, i, 1);
                        draw_lines(renderer);
                    }

                    completed_bars++;
                    SDL_RenderPresent(renderer);
                    SDL_Delay(time);
                }
            }
            
            
        }
    }
    else
        SDL_Log("Erro na criação da janela: %s", SDL_GetError());

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyTexture(header_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
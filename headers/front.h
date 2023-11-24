#ifndef __FRONT
#define __FRONT

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOWS_WIDTH 1280
#define WINDOWS_HIGH 600
#define BAR_WIDTH 10
#define MAX_BAR_HIGH 200

extern const SDL_Color background; 
extern const SDL_Color bar;
extern const SDL_Color line;
extern const SDL_Color grid;

    void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text, TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect);
    void draw_headers(char* header1, char* header2, SDL_Renderer *renderer, TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect);
    void draw_bar_ref(SDL_Renderer* renderer, int pos, float percent);
    void draw_bar_mark(SDL_Renderer* renderer, int pos, int percent);
    void draw_lines(SDL_Renderer *renderer);

#endif
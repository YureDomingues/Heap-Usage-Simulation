#include "headers/front.h"

const SDL_Color background = {.r = 38, .g = 35, .b = 34, .a = SDL_ALPHA_OPAQUE}; //Hexadecimal color: #7A96B8
const SDL_Color bar = {.r = 153, .g = 194, .b = 77, .a = SDL_ALPHA_OPAQUE}; //Hexadecimal color: #99C24D
const SDL_Color grid = {.r = 102, .g = 133, .b = 134, .a = SDL_ALPHA_OPAQUE}; //Hexadecimal color: #2F4B26
const SDL_Color line = {.r = 252, .g = 247, .b = 248, .a = SDL_ALPHA_OPAQUE}; //Hexadecimal color: ##FCF7F8

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text, TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {117, 221, 221, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

void draw_headers(char* header1, char* header2, SDL_Renderer *renderer, TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect){
    get_text_and_rect(renderer, 10,0, header1, font,  texture, rect);
    SDL_RenderCopy(renderer, *texture, NULL, rect);
    SDL_DestroyTexture(*texture);

    get_text_and_rect(renderer, 10, WINDOWS_HIGH/2+3, header2, font,  texture, rect);
    SDL_RenderCopy(renderer, *texture, NULL, rect);
    SDL_DestroyTexture(*texture);
}

void draw_bar(SDL_Renderer* renderer, int x, int y, float percent, int w){
    SDL_SetRenderDrawColor(renderer, bar.r, bar.g, bar.b, bar.a); 
    SDL_Rect rect = {.x = x, .y = y, .h = MAX_BAR_HIGH*percent, .w = w};
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, line.r, line.g, grid.b, line.a); 
    SDL_RenderDrawRect(renderer, &rect);
}

void draw_bar_ref(SDL_Renderer* renderer, int pos, float percent){
    int high = MAX_BAR_HIGH*percent;
    draw_bar(renderer, 80+pos*BAR_WIDTH, WINDOWS_HIGH/2-(high), percent, BAR_WIDTH);
}

void draw_bar_mark(SDL_Renderer* renderer, int pos, int percent){
    int high = MAX_BAR_HIGH*percent;
    draw_bar(renderer, 80+pos*BAR_WIDTH, WINDOWS_HIGH-high, high, BAR_WIDTH);
}

void draw_lines(SDL_Renderer* renderer){
    int xi = 80;
    int xf = WINDOWS_WIDTH;
    int h = MAX_BAR_HIGH;
    int div_part = 4;

    SDL_SetRenderDrawColor(renderer, line.r, line.g, line.b, line.a);
    for(int i=0; i<=div_part; i++){
        SDL_RenderDrawLine(renderer, xi, WINDOWS_HIGH/2 - (h/div_part)*i, xf, WINDOWS_HIGH/2 - (h/div_part)*i);
    }
    for(int i=0; i<=div_part; i++){
        SDL_RenderDrawLine(renderer, xi, WINDOWS_HIGH - (h/div_part)*i, xf, WINDOWS_HIGH - (h/div_part)*i);
    }
    

}
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

void draw_headers(char* header1, char* header2, SDL_Renderer *renderer, TTF_Font *font){
    SDL_Texture *t;
    SDL_Rect r;

    get_text_and_rect(renderer, 10,20, header1, font,  &t, &r);
    SDL_RenderCopy(renderer, t, NULL, &r);
    SDL_DestroyTexture(t);

    get_text_and_rect(renderer, 10, WINDOWS_HIGH/2+20, header2, font,  &t, &r);
    SDL_RenderCopy(renderer, t, NULL, &r);
    SDL_DestroyTexture(t);
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

void draw_bar_mark(SDL_Renderer* renderer, int pos, float percent){
    int high = MAX_BAR_HIGH*percent;
    draw_bar(renderer, 80+pos*BAR_WIDTH, WINDOWS_HIGH-high, high, BAR_WIDTH);
}

void draw_lines(SDL_Renderer* renderer){
    int xi = 80;
    int xf = WINDOWS_WIDTH;
    int h = MAX_BAR_HIGH;
    int div_part = 5;

    SDL_SetRenderDrawColor(renderer, line.r, line.g, line.b, line.a);
    for(int i=0; i<=div_part; i++){
        SDL_RenderDrawLine(renderer, xi, WINDOWS_HIGH/2 - (h/div_part)*i, xf, WINDOWS_HIGH/2 - (h/div_part)*i);
    }
    for(int i=0; i<=div_part; i++){
        SDL_RenderDrawLine(renderer, xi, WINDOWS_HIGH - (h/div_part)*i, xf, WINDOWS_HIGH - (h/div_part)*i);
    }
}

void startDisplay(int clock){
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font *font_header = NULL;
    TTF_Font *font_numbers = NULL;
    int completed_bars = 0;
    int number_bars = 120;
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
}
#include "headers/list.h"
#include "headers/memory-manipulation.h"

enum {CRIAR, ATRIBUIR};

int* variaveis_ref[MAX_HEAP*10];
int* variaveis_mark[MAX_HEAP*10];
int num_var = 0;

void manipulation(){
    int r = rand() % 2;

    switch (r)
    {
    case CRIAR:
        if(tamanho_ref()<MAX_HEAP){
            variaveis_ref[num_var%MAX_HEAP] = malloc_ref(sizeof(int));
            variaveis_mark[num_var%MAX_HEAP] = malloc_mark(sizeof(int));
        }
        num_var++;
        break;
    case ATRIBUIR:
        if( num_var > 1){
            int alet1 = rand()%num_var;
            int alet2 = rand()%num_var;
            while(alet1 == alet2){
                alet1=rand()%num_var;
            }
            
            atrib_ref((void**)(&variaveis_ref[alet1]), (void*) variaveis_ref[alet2]);
            atrib_mark((void**)(&variaveis_mark[alet1]), (void*) variaveis_mark[alet2],MAX_HEAP);
        }
        break;
    }

}

void manipulation2(float *x, float *y){
    for(int i=0; i<3; i++){
        manipulation();
    }
    
    *x = ((float)tamanho_ref()/MAX_HEAP);
    *y = ((float)tamanho_mark()/MAX_HEAP);

}

float man_mark(){

    return ((float)tamanho_mark()/MAX_HEAP);
}


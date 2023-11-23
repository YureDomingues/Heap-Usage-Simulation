#include <stdio.h>
#include <stdlib.h>
#include "headers/contagem-referencia.h"

int main(){
    int *v = (int*) malloc2(sizeof(int));
    *v = 10;
    int *w = (int*) malloc2(sizeof(int));
    *w = 20;
    atrib2(&v,w);
    atrib2(&w,NULL);
    heap_status();
    return 0;
};
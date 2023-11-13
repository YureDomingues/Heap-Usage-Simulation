#include <stdio.h>
#include <stdlib.h>
#include "headers/contagem-referencia.h"

int main(){
    int *v = (int*) malloc2(sizeof(int));
    *v = 10;
    int *w = (int*) malloc2(sizeof(int));
    dump();
    *w = 20;
    atrib2(&v,w);
    dump();
    dump();
    atrib2(&w,NULL);
    dump();
    print_lixo();
    return 0;
};
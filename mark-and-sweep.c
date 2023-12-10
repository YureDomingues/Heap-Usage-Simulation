#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"
#include "headers/mark-and-sweep.h"

#define USAGE_LIMIT_RATIO 0.9

lista *heap_mark = NULL;

void* malloc_mark(int tamanho){
    void *v = malloc(tamanho);
    inserir_elemento(&heap_mark, v);
    return v;
}

void atrib_mark(void** endereco1, void* endereco2, int max_heap_size) {
    if (*endereco1 != NULL) {
        lista *endBusca1 = buscar_elemento(heap_mark, *endereco1);
        endBusca1->qtdPtr--;

        dump_mark(&heap_mark, max_heap_size);
    }

    if (endereco2 != NULL) {
        lista *endBusca2 = buscar_elemento(heap_mark, endereco2);
        endBusca2->qtdPtr++;
    }

    *endereco1 = (endereco2 != NULL) ? endereco2 : NULL;
}

void dump_mark(lista **heap, int max_heap_size) {
    if (((float)tamanho_lista(*heap) / max_heap_size) > USAGE_LIMIT_RATIO) {
        remover(heap);
    }
}

int tamanho_mark(){
    return tamanho_lista(heap_mark);
}
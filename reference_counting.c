#include <stdio.h>
#include <stdlib.h>
#include "headers/reference_counting.h"

lista *heap_ref = NULL;

void* malloc_ref(int tamanho){
    void *v = malloc(tamanho);
    inserir_elemento(&heap_ref, v);
    return v;
}

//Função que atribui o endereco2 no endereco1 end2 = end1;
void atrib_ref(void** endereco1, void* endereco2) {
    if (*endereco1 != NULL) {void* malloc_ref(int tamanho);
void atrib(void** endereco1, void* endereco2);
        lista *endBusca1 = buscar_elemento(heap_ref, *endereco1);
        endBusca1->qtdPtr--;

        if (endBusca1->qtdPtr == 0)
            dump_ref(&heap_ref);
    }

    if (endereco2 != NULL) {
        lista *endBusca2 = buscar_elemento(heap_ref, endereco2);
        endBusca2->qtdPtr++;
    }

    *endereco1 = (endereco2 != NULL) ? endereco2 : NULL;
}

void dump_ref(lista **heap){
    remover(heap);
}

int tamanho_ref(){
    return tamanho_lista(heap_ref);
}
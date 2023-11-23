#include <stdio.h>
#include <stdlib.h>
#include "headers/lista.h"

lista *heap = NULL;

void* malloc2(int tamanho){
    void *v = malloc(tamanho);
    inserir_elemento(&heap, v);
    return v;
}

void dump(){
    remover_lixo(&heap);
}

//Função que atribui o endereco2 no endereco1 end2 = end1;
void atrib2(void* *endereco1, void* endereco2){

    /*
        end1 == NULL e end2 == NULL (Não fazer nada)
        end1 != NULL e end2 == NULL (Diminui 1 do contador do end1 e faz end1 = NULL)
        end1 == NULL e end2 != NULL (Aumenta 1 no contador do end2 e faz end1 = end2)
        end1 != NULL e end2 != NULL (Diminui 1 do contador do end 1, aumenta 1 do contador do end2 e end1=end2);
    */

    if(endereco1 != NULL){
        lista *endBusca1 = buscar_elemento(heap, *endereco1);
        endBusca1->qtdPtr--;

        if(endBusca1->qtdPtr == 0)
            dump();
    }
    
    if(endereco2 != NULL){
        lista *endBusca2 = buscar_elemento(heap, endereco2);
        endBusca2->qtdPtr++;
    }
    
    *endereco1 = endereco2;
}

void heap_status(){
    print_lista(heap);
}
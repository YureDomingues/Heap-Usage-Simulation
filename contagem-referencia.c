#include <stdio.h>
#include <stdlib.h>
#include "headers/lista.h"

lista *lixo = NULL;

void* malloc2(int tamanho){
    void *v = malloc(tamanho);
    inserir_elemento(&lixo, v);
    return v;
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
        lista *endBusca1 = buscar_elemento(lixo, *endereco1);
        endBusca1->qtdPtr--;
    }
    
    if(endereco2 != NULL){
        lista *endBusca2 = buscar_elemento(lixo, endereco2);
        endBusca2->qtdPtr++;
    }
    
    *endereco1 = endereco2;
}

void dump(){
    remover_lixo(&lixo);
}

void print_lixo(){
    print_lista(lixo);
}
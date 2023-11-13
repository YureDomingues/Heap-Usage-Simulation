#include <stdio.h>
#include <stdlib.h>
#include "headers/lista.h"


lista* buscar_elemento(lista *l, void* elemento){
    if(l != NULL){
        if(elemento == l->endereco){
            return l;
        }else{
            return buscar_elemento(l->prox, elemento);
        }
    }
    return NULL;
}

void inserir_elemento(lista **l, void* elemento){
    lista *novo = (lista*) malloc(sizeof(lista));

    novo->endereco = elemento;
    novo->qtdPtr = 1;
    novo->prox = *l;

    *l = novo;
}


void remover_lixo(lista** l){
	if(*l != NULL){
        remover_lixo((&(*l)->prox));
        
		if((*l)->qtdPtr == 0){

			lista *p = *l;
			*l = (*l)->prox;
			free(p);
        
		}  
	}
}

void print_lista(lista *l){
    if(l != NULL){
        printf("[%p,%d] ",l->endereco,l->qtdPtr);
        print_lista(l->prox);
    }else{
        printf("\n");
    };
}
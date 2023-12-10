#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"


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


void remover(lista** l){
	if(*l != NULL){
        remover((&(*l)->prox));
        
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

// Função para calcular o tamanho da lista
int tamanho_lista(lista *l) {
    int tamanho = 0;
    while (l != NULL) {
        tamanho++;
        l = l->prox;
    }
    return tamanho;
}

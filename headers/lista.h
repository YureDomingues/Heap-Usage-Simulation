#ifndef __LISTA_
#define __LISTA_

typedef struct lista{
    void* endereco;
    int qtdPtr;
    struct lista* prox;
}lista;

void inserir_elemento(lista **l, void* elemento);
lista* buscar_elemento(lista *l, void* elemento);
void remover_lixo(lista** l);
void print_lista(lista *l);

#endif
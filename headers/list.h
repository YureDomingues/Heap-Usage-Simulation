#ifndef __LIST_
#define __LIST_

typedef struct lista{
    void* endereco;
    int qtdPtr;
    struct lista* prox;
}lista;

void inserir_elemento(lista **l, void* elemento);
lista* buscar_elemento(lista *l, void* elemento);
void remover(lista** l);
void print_lista(lista *l);
int tamanho_lista(lista* l);

#endif
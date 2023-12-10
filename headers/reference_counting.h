#ifndef __REF_COUNT_
#define __REF_COUNT

#include "list.h"

void* malloc_ref(int tamanho);
void atrib_ref(void** endereco1, void* endereco2);
void dump_ref(lista **heap);
int tamanho_ref();

#endif
#ifndef __MARK_AND_SWEEP
#define __MARK_AND_SWEEP

#include "list.h"

void* malloc_mark(int tamanho);
void atrib_mark(void** endereco1, void* endereco2, int max_heap_size);
void dump_mark(lista **heap, int max_heap_size);
int tamanho_mark();

#endif
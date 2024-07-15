#ifndef abbgenerica_h
#define abbgenerica_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore tArvore;

typedef void (*imprime) (void*);
//typedef void* (*retorna) (void*);
typedef int (*compara) (void*, void*);
typedef void (*libera) (void*);

tArvore* abb_cria(void);

void abb_imprime(tArvore* a, imprime print);

tArvore *abb_busca(tArvore *r, void* dado, compara compare);

tArvore *abb_insere(tArvore *a, void* dado, compara compare);

tArvore *abb_retira(tArvore *r, void* dado, compara compare, libera freeData);

void liberaArvore(tArvore* r, libera freeData);

#endif
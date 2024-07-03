#ifndef abbgenerica_h
#define abbgenerica_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore tArvore;

typedef int (*imprime) (void* dado);

typedef void* (*retorna) (void* dado);

typedef int (*compara) (void* dado1, void* dado2);

typedef void (*libera) (void* dado);

tArvore* abb_cria(void);

void abb_imprime(tArvore* a, imprime print);

tArvore *abb_busca(tArvore *r, void* dado, retorna returnData, compara compare);

tArvore *abb_insere(tArvore *a, void* dado, compara compare);

tArvore *abb_retira(tArvore *r, void* dado, compara compare);

void liberaArvore(tArvore* r, libera freeData);

#endif
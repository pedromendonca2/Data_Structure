#ifndef fila_h
#define fila_h

#include "amostra.h"

typedef struct celula tCelula;
typedef struct fila tFila;

tCelula* retorna_prox(tCelula* cel);

void imprime_fila(tFila* f);

tFila* fila_cria ();

void fila_insere_inicio(tFila* f, Amostra* a);

void fila_insere_final(tFila* f, Amostra* a);

Amostra* fila_retira (tFila* f);

void fila_libera (tFila* f);

tCelula* retorna_prim(tFila* f);

Amostra* retorna_amostra(tCelula* cel);

#endif
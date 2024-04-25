#ifndef Lista_h
#define Lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Gato.h"
#include "Cachorro.h"

#define GATO 0
#define CACHORRO 1
#define v_cachorro 40
#define v_gato 30
#define v_agressivo 5

typedef struct celula tCelula;
typedef struct lista_heterogenea tListaHet;

tCelula* liberaCelula(tCelula* cel);

tListaHet* inicializaLista();

void insereAnimalNaLista(char* nome, int agressividade, int animal, tListaHet* lista);

int buscaItem(tListaHet* lista, char* nome);

void retiraItem(tListaHet* lista, char* nome);

float calculaValor(tListaHet* lista, int agressividade);

void imprimeLista(tListaHet* lista);

void liberaLista(tListaHet* lista);

#endif
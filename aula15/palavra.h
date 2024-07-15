#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPAL 64 

typedef struct palavra tPalavra;

tPalavra* inicPalavra(char* pal);

char* retornaString(tPalavra* pal, int posicao);

void atualizaOcorrencias(tPalavra* pal);

int retornaOcorrencias(tPalavra* pal);

tPalavra* buscaPalavra(tPalavra* pal, char* string);

tPalavra* inserePalavraLista(tPalavra* lista, tPalavra* pal);

int contaPalavrasLista(tPalavra* pal);

void imprimeLista(tPalavra* pal);

void liberaListaPalavras(tPalavra* pal);

#endif
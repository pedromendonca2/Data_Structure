#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPAL 64 

typedef struct palavra tPalavra;

tPalavra* inicPalavra(char* pal);

tPalavra* retornaProximo(tPalavra *pal);

int retornaFrequencia(tPalavra* pal);

char retornaCaracter(tPalavra* pal, int posicao);

static int compara (const void* v1, const void* v2);

void incrementaPalavra(tPalavra* pal);

void liberaPalavra (tPalavra* pal);

#endif
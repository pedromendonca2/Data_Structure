#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra tPalavra;

tPalavra* inicPalavra(char* p);

tPalavra* retornaPalavra(void* p);

unsigned int retornaSize();

char* retornaString(tPalavra* pal);

void atualizaOcorrencias(tPalavra* pal);

int retornaOcorrencias(tPalavra* pal);

int comparaPalavra(void* pal_1, void* pal_2);

int hashPalavra(void* pal, int tam);

void imprimePalavra(tPalavra* pal, FILE* file);

void liberaPalavra(tPalavra* pal);

#endif // PALAVRA_H

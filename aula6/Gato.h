#ifndef Gato_h
#define Gato_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVO 2
#define MANSO 3

typedef struct gato Gato;

Gato* inicGato(char* nome, int agressividade);

void atribuiNivelAgressividadeGato(Gato* cat, int agressividade);

void liberaGato(Gato* cat);

int catAgressivity(Gato* cat);

char* catsName(Gato* cat);

#endif
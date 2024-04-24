#ifndef Gato_h
#define Gato_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVO 0
#define MANSO 1

typedef struct gato Gato;

Gato* inicGato(char* nome, int agressividade);

void liberaGato(Gato* cat);

int catAgressivity(Gato* cat);

int catsName(Gato* cat);

#endif
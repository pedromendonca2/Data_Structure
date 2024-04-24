#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVO 0
#define MANSO 1

typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int agressividade);

void liberaCachorro(Cachorro* dog);

int dogAgressivity(Cachorro* dog);

int dogsName(Cachorro* dog);

#endif
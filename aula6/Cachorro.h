#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVO 2
#define MANSO 3

typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int agressividade);

void atribuiNivelAgressividadeCachorro(Cachorro* dog, int agressividade);

void liberaCachorro(Cachorro* dog);

int dogAgressivity(Cachorro* dog);

char* dogsName(Cachorro* dog);

#endif
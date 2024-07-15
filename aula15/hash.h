#ifndef HASH_H
#define HASH_H

#include "palavra.h"

#define NTAB 127

typedef struct hash Hash;

//typedef tPalavra* Hash[NTAB];

static int hash(char* s, int tam);

Hash* inicializa(int tam);

tPalavra* acessaHash(Hash* h, char* s);

int contaPalavras(Hash* h);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);

#endif
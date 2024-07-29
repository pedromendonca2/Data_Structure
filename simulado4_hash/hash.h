#ifndef HASH_H
#define HASH_H

#include "aluno.h"

#define NTAB 25

typedef struct hash tHash;

int functionHash(char* s, int tam);

tHash* inicializaHash(int tam);

tAluno* acessaHash(tHash* hash, char* s, char p);

void imprimeHashAqui(tHash* hash);

void imprimeHash(tHash* hash, FILE* file);

void liberaHash(tHash* hash);

#endif
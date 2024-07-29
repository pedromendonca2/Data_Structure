#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

typedef struct hash Hash;

Hash* cria(int tam, size_t tam_item);

void* busca(Hash* hash, void* key, int (*fhash)(void*, int), int (*comp)(void*, void*));

void* hash_insere(Hash* thash, void* key, void* objeto, int (*fhash)(void*, int), int (*comp)(void*, void*));

int contaPalavras(Hash* table);

void imprimeHash(Hash* table, FILE* file);

void libera(Hash* table);

#endif // HASH_H

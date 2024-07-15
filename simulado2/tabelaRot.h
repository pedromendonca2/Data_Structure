#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct roteador tRoteador;

typedef struct hash tHash;

struct roteador{
    int destination;
    int n;
    tRoteador* prox;
};

static int hash(int destination, int tam);

tRoteador* inicRoteador(int destination);

tHash* inicTab(int tam);

tRoteador* busca(tRoteador* rot, int destination);

tRoteador* acessaTab(tHash* tab, tRoteador* rot);

void imprimeTab(tHash* tab);

void liberaTab(tHash* tab);

#endif
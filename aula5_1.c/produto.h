#ifndef produto_h
#define produto_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto tProduto;

tProduto* criaProduto();

char* retornaNome(tProduto* p);

int retornaCodigo(tProduto* p);

int retornaPreco(tProduto* p);

void liberaProduto(tProduto* p);

#endif


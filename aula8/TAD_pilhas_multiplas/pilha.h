#define MaxTam 1000
#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoItem;

typedef struct{
    int Topo, Base;
} IndicePilha;

typedef struct {
    TipoItem* Item[MaxTam];
    IndicePilha Pilha[N];
} TipoPilhaMultipla;
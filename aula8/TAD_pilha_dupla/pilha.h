#define MaxTam 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoItem;

typedef struct{
    int Topo, Base;
} IndicePilha;

typedef struct {
    TipoItem* Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
} TipoPilhaDupla;

TipoPilhaDupla* inicPilhaDupla();

void EmpilhaPilha1 (TipoItem* x, TipoPilhaDupla* Pilhas);

void EmpilhaPilha2 (TipoItem* x, TipoPilhaDupla* Pilhas);

TipoItem* DesempilhaPilha1 (TipoPilhaDupla* Pilhas);

TipoItem* DesempilhaPilha2 (TipoPilhaDupla* Pilhas);

TipoItem* inicItem (TipoItem elemento);

void imprimePilhas(TipoPilhaDupla* Pilhas);
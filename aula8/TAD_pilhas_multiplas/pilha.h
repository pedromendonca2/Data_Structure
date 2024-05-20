#define MaxTam 1000
#define N 10
#define tamanho_pilha 100

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

TipoItem* inicItem (TipoItem elemento);

TipoPilhaMultipla* inicPilhaMultipla();

void EmpilhaPilhaQualquer(TipoItem* x, TipoPilhaMultipla* Pilhas, int indice);

TipoItem* DesempilhaPilhaQualquer(TipoPilhaMultipla* Pilhas, int indice);

void imprimePilhas(TipoPilhaMultipla* Pilhas);
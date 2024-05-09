#ifndef lista_h
#define lista_h

#include "produto.h"

typedef struct celula tCelula;
typedef tCelula tTipoLista;

tTipoLista* inicializaLista();

tTipoLista* insereProduto(tTipoLista* lista, tProduto* produto);

tCelula* busca(tTipoLista* lista, int preco);

tTipoLista* retira(tTipoLista* lista, int preco);

void destroiLista(tTipoLista* lista);

void imprimeLista(tTipoLista* lista);

#endif

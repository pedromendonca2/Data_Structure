#include "com_sentinela_dupla.h"

struct celula{
    tProduto* produto;
    tCelula* prox;
    tCelula* ant;
};

struct lista{
    tCelula* primeiro;
    tCelula* ultimo;
};

tCelula* liberaCelula(tCelula* cel){

    tCelula* prox = cel->prox;
    liberaProduto(cel->produto);
    free(cel);

    return prox;
}

tTipoLista* inicializaLista(){
    tTipoLista* lista = malloc(sizeof(tTipoLista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereProdutoNaLista(tProduto* produto, tTipoLista* lista){

    tCelula* novo = malloc(sizeof(tCelula));

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        novo->ant = lista->ultimo;
        lista->ultimo = lista->ultimo->prox;
    }

}

tTipoLista* retira(tTipoLista* lista, int preco){
    tCelula* p = lista->primeiro;

    while(p != NULL && retornaPreco(p->produto) != preco){
        p = p->prox;
    }

    if(p == NULL) return lista;

    if(p == lista->primeiro && p == lista->ultimo){
        lista->primeiro = lista->ultimo = NULL;
        liberaCelula(p);
        return lista; 
    }

    if(p == lista->primeiro){
        lista->primeiro = p->prox;
        p->prox->ant = NULL;
    } else if(p == lista->ultimo){
        lista->ultimo = p->ant;
        p->ant->prox = NULL;
    } else{
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
    }

    liberaCelula(p);
    return lista;
}

void liberaLista(tTipoLista* lista){
    tCelula *cel = lista->primeiro;

    while(cel != NULL){
        cel = liberaCelula(cel);
    }

    free(lista);
}
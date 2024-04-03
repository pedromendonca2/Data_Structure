#include "lista.h"

typedef struct{
    tProduto* produto;
    tCelula* prox;
} tCelula;

typedef struct{
    tCelula* primeiro;
    tCelula* ultimo;
} tTipoLista;

void liberaCelula(tCelula* cel){
    liberaProduto(cel->produto);
    free(cel->prox);
    free(cel);
}

tTipoLista* inicializaLista(){
    tTipoLista* lista = malloc(sizeof(tTipoLista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereCelulaNaLista(tProduto* produto, tTipoLista* lista){

    tCelula* novo = malloc(sizeof(tCelula));

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        lista->ultimo = lista->ultimo->prox;
    }

    lista->ultimo->produto = produto;
    lista->ultimo->prox = NULL;
}

void retiraItem(tTipoLista* lista, int v){
    tCelula* ant = NULL;
    tCelula* p = lista->primeiro;

    while(p != NULL && retornaPreco(p->produto)){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return;

    if(p == lista->primeiro && p == lista->ultimo){
        lista->primeiro = lista->ultimo = NULL;
        free(p);
        return; 
    }

    if(p == lista->ultimo){
        lista->ultimo = ant; 
        ant->prox = NULL; 
        free(p);
        return;
    }

    if(p == lista->primeiro) lista->primeiro = p->prox;
    else ant->prox = p->prox;

    free(p);
}

void imprimeLista(tTipoLista* lista){
    tCelula* aux;
    aux = lista->primeiro;

    while(aux != NULL){
        printf("Nome: %s, preco: %d e codigo: %d\n", retornaNome(aux->produto), retornaPreco(aux->produto), retornaCodigo(aux->produto));
        aux = aux->prox;
    }
}

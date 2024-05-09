#include "lista.h"

struct celula{
    tProduto* produto;
    tCelula* prox;
    tCelula* ant;
};

tTipoLista* inicializaLista(){
    tTipoLista* lista = NULL;
    return lista;
}

tTipoLista* insereProduto(tTipoLista* lista, tProduto* produto){
    tCelula* nova = malloc(sizeof(tCelula));

    nova->ant = NULL;
    nova->prox = lista;
    nova->produto = produto; 

    if(lista != NULL){
        lista->ant = nova; //deixou de ser a primeira e passa a ser a segunda posicao
    }

    return nova; //que eh agora a nova lista
}

tCelula* busca(tTipoLista* lista, int preco){
    tCelula* p = lista;

    for(p; p != NULL; p = p->prox){
        if(preco==retornaPreco(p->produto)){
            return p;
        }
    }

    return NULL;
}

tTipoLista* retira(tTipoLista* lista, int preco){
    tCelula* p = busca(lista, preco);

    if(p == NULL) return lista;

    if(p->ant != NULL) p->ant->prox = p->prox; //n eh o 1o

    if(p->prox != NULL){ //n eh o ultimo
        p->prox->ant = p->ant;
        if(p->ant == NULL) lista = p->prox; //eh o 1o
    }

    if(p->ant == NULL && p->prox == NULL) lista = NULL; //eh o unico

    free(p);
    return lista;
}

void destroiLista(tTipoLista* lista){
    tCelula* p = lista;

    while(p!=NULL){
        lista = lista->prox;
        free(p);
        p = lista;
    }
}

void imprimeLista(tTipoLista* lista){
    tCelula* p = lista;

    for(p; p != NULL; p=p->prox){
        printf("Nome: %s, preco: %d e codigo: %d\n", retornaNome(p->produto), retornaPreco(p->produto), retornaCodigo(p->produto));
    }
}
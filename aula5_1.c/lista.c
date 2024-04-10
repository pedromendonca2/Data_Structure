#include "lista.h"

struct celula{
    tProduto* produto;
    tCelula* prox;
    tCelula* ant;
};

tTipoLista* inicializaLista(){
    tTipoLista* lista = malloc(sizeof(tTipoLista));
    lista == NULL;
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

    for(p; preco!=retornaPreco(p->produto); p = p->prox){
        if(preco==retornaPreco(p->produto)){
            return p;
        }
    }

    //free(p);
    return NULL;
}

tTipoLista* retira(tTipoLista* lista, int preco){
    tCelula* p = busca(lista, preco);

    if(p == NULL) return lista;

    if(p == lista){ // eh o primeiro
        p = NULL;
    } else if(p->prox == NULL){ // eh o ultimo
        p->ant->prox = NULL;
    } else{ // esta no meio
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
    }

    return lista;
}

void destroiLista(tTipoLista* lista){
    tCelula* p = lista;

    for(p; p!=NULL; p = p->prox){
        free(p);
    }

    free(lista);
}
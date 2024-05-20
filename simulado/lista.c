#include "lista.h"

struct celula{
    void* elemento;
    tCelula* prox;
};

struct lista{
    tCelula* primeiro;
    tCelula* ultimo;
};

void liberaCelulaProduto(tCelula* cel){
    if(cel != NULL){
        DestroiProd(cel->elemento);
        free(cel);
    }
}

void liberaCelulaIngrediente(tCelula* cel){
    if(cel != NULL){
        free(cel->elemento);
        free(cel);
    }
}

tLista* inicLista(){
    tLista* lista = malloc(sizeof(tLista));

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

tLista* adicionaElemento(tLista* lista, void* elemento){
    tCelula* novo = malloc(sizeof(tCelula));

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        lista->ultimo = lista->ultimo->prox;
    }

    lista->ultimo->elemento = elemento;
    lista->ultimo->prox = NULL;

}

void retiraProdutoLista(tLista* lista, char* nome){ //se pr. e ul. forem iguais, se for ultimo e dois casos se for o primeiro
    tCelula* ant = NULL;
    tCelula* p = lista->primeiro;

    while(p != NULL || strcmp(p->elemento, nome) != 0){
        ant = p;
        p = p->prox;
    }

    if(p = NULL) return;

    if(p == lista->primeiro && p == lista->ultimo){
        lista->primeiro = lista->ultimo = NULL;
        DestroiProd(p);
        return;
    }

    if(p == lista->ultimo){
        lista->ultimo = ant;
        ant = NULL;
        DestroiProd(p);
        return;
    }

    if(p == lista->primeiro){
        lista->primeiro = p->prox;
    } else{
        ant->prox = p->prox;
    }

    DestroiProd(p);
}

void liberaListaProdutos(tLista* lista){
    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        tCelula* prox = aux->prox;
        liberaCelulaProduto(aux);
        aux = prox;
    }

    free(lista);
}

void liberaListaIngredientes(tLista* lista){
    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        tCelula* prox = aux->prox;
        liberaCelulaIngrediente(aux);
        aux = prox;
    }

    free(lista);
}

void imprimeIngredientes(tLista* lista){
    tCelula* cel = lista->primeiro;

    while(cel != NULL){
        printf("%s\n", cel->elemento);
        cel = cel->prox;
    }
}
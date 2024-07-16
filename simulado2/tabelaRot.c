#include "tabelaRot.h"

struct hash{
    tRoteador** vet;
    int tam;
};

static int hash(int destination, int tam){
    return destination % tam;
}

tRoteador* inicRoteador(int destination){
    tRoteador* rot = malloc(sizeof(tRoteador));

    rot->destination = destination;
    rot->n = 0;
    rot->prox = NULL;

    return rot;
}

tHash* inicTab(int tam){
    tHash* tab = malloc(sizeof(tHash));
    tab->vet = malloc(tam*sizeof(tRoteador));

    tab->tam = tam;

    for(int i=0; i<tab->tam; i++){
        tab->vet[i] = NULL;
    }

    return tab;
}

tRoteador* busca(tRoteador* rot, int destination){
    tRoteador* r;

    for(r = rot; r!=NULL; r = r->prox){
        if(r->destination == destination){
            r->n++;
            return r;
        }
    }

    return NULL;
}

tRoteador* acessaTab(tHash* tab, tRoteador* rot){
    int nextHop = hash(rot->destination, tab->tam);

    tRoteador* r = busca(tab->vet[nextHop], rot->destination);
    if(r) return r;

    tab->vet[nextHop] = rot;
    tab->vet[nextHop]->n++;

    return rot;
}

void imprimeLista(tRoteador* rot){
    tRoteador* r;

    for(r = rot; r!=NULL; r=r->prox){
        printf("destination = %d ", r->destination);
        printf("e frequencia = %d\n", r->n);
    }
}

void imprimeTab(tHash* tab){
    for(int i=0; i<tab->tam; i++){
        printf("Posicao vet[%d]: ", i);
        if(tab->vet[i] == NULL){
            printf("NULL\n");
        } else{
            imprimeLista(tab->vet[i]);
        }
    }
}

void liberaRoteador(tRoteador* rot){
    tRoteador* aux = rot;
    tRoteador* t;

    while(aux != NULL){
        t = aux->prox;
        free(aux);
        aux = t;
    }
}

void liberaTab(tHash* tab){
    for(int i=0; i<tab->tam; i++){
        liberaRoteador(tab->vet[i]);
    }
    free(tab->vet);
    free(tab);
}
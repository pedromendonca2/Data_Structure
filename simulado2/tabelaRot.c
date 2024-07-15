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

    for(r = rot; r==NULL; r = r->prox){
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

    return rot;
}

void imprimeTab(tHash* tab){
    for(int i=0; i<tab->tam; i++){
        printf("Posicao vet[%d]: destination = %d e frequencia = %d\n", i, tab->vet[i]->destination, tab->vet[i]->n);
    }
}

void liberaTab(tHash* tab){
    if(tab != NULL){

        for(int i=0; i<tab->tam; i++){

            tRoteador* aux;
            while(aux != NULL){
                aux = tab->vet[i]->prox;
                free(tab->vet[i]);
                tab->vet[i] = aux;
            }
        }

        free(tab->vet);
        free(tab);
    }
}
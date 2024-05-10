#include "fila.h"

struct celula{
    Amostra* amostra;
    tCelula* prox;
};

struct fila{
    tCelula* ini;
    tCelula* fim;
};

tCelula* retorna_prox(tCelula* cel){
    return cel->prox;
}

void imprime_fila(tFila* f){
    tCelula* c = f->ini;

    while(c != NULL){
        imprimeAmostra(c->amostra);
        c = c->prox;
    }
}

tFila* fila_cria(){    
    tFila* f = malloc(sizeof(tFila));
    f->ini = f->fim = NULL;

    return f;
}

void fila_insere_inicio(tFila* f, Amostra* a){
    tCelula* c = malloc(sizeof(tCelula));

    c->amostra = a;
    c->prox = f->ini;

    f->ini = c;
}

void fila_insere_final(tFila* f, Amostra* a){
    tCelula* c = malloc(sizeof(tCelula));

    c->amostra = a;
    c->prox = NULL;

    if(f->fim != NULL){
        f->fim->prox = c;
    } else{
        f->ini = c;
    }

    f->fim = c;
}

Amostra* fila_retira (tFila* f){
    tCelula* c;
    Amostra* a;

    if(f == NULL){
        printf("Deu ruim\n");
        exit(1);
    } 

    c = f->ini;
    a = c->amostra;
    f->ini = c->prox;

    if(f->ini == NULL) f->fim = NULL;

    free(c);
    return a;
}

void fila_libera (tFila* f){
    tCelula* c = f->ini;

    while(c != NULL){
        tCelula* aux = c->prox;
        liberaAmostra(c->amostra);
        free(c);
        c = aux;
    }

    free(f);
}

tCelula* retorna_prim(tFila* f){
    return f->ini;
}

Amostra* retorna_amostra(tCelula* cel){
    return cel->amostra;
}
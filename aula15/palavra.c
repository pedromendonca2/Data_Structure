#include "palavra.h"

struct palavra {
    char pal[NPAL];
    int n;
    struct palavra* prox;
};

tPalavra* inicPalavra(char* p){
    tPalavra* pal = malloc(sizeof(tPalavra));

    strdup(pal->pal, p);
    pal->n = 0;
    pal->prox = NULL;

    return p;
}

tPalavra* retornaProximo(tPalavra *pal){
    return pal->prox;
}

int retornaFrequencia(tPalavra* pal){
    return pal->n;
}

char retornaCaracter(tPalavra* pal, int posicao){
    return pal->pal[posicao];
}

static int compara (char* pal_1, char* pal_2){
    return strcmp(pal_1,pal_2);
}

void incrementaPalavra(tPalavra* pal){
    pal->n++;
}

void liberaPalavra (tPalavra* pal){
    if(pal != NULL){

        free(pal->pal);
        
        for(tPalavra* p; p!=NULL; p=p->prox){
            liberaPalavra(p);
        }

        free(pal);
    }
}
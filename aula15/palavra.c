#include "palavra.h"

struct palavra { //celula da lista encadeada
    char* pal;
    int n;
    tPalavra* prox;
};

tPalavra* inicPalavra(char* p){
    tPalavra* pal = malloc(sizeof(tPalavra));

    pal->pal = strdup(p);
    pal->n = 0;
    pal->prox = NULL;

    return pal;
}

char* retornaString(tPalavra* pal, int posicao){
    return pal->pal;
}

void atualizaOcorrencias(tPalavra* pal){
    pal->n++;
}

int retornaOcorrencias(tPalavra* pal){
    return pal->n;
}

int compara (char* pal_1, char* pal_2){
    return strcmp(pal_1, pal_2);
}

tPalavra* buscaPalavra(tPalavra* pal, char* string){
    tPalavra* p;

    for(p = pal; p!=NULL; p=p->prox){
        if(strcmp(pal->pal, string) == 0){
            return p;
        }
    }

    return NULL;
}

tPalavra* inserePalavraLista(tPalavra* lista, tPalavra* pal){
    pal->prox = lista;

    return pal;
}

int contaPalavrasLista(tPalavra* pal){
    tPalavra* p;

    int i=0;

    for(pal = p; pal!=NULL; pal = pal->prox){
        i++;
    }

    return i;
}

void imprimeLista(tPalavra* pal){
    tPalavra* aux;

    for(aux=pal; aux!=NULL; aux=aux->prox){
        printf("String: %s - Ocorrencia: %d\n", aux->pal, aux->n);
    }
}

void liberaListaPalavras(tPalavra* pal){
    tPalavra* aux = pal;
    tPalavra* t;

    while(aux != NULL){
        t = aux->prox;
        free(aux->pal);
        free(aux);
        aux = t;
    }
}
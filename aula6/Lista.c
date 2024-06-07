#include "Lista.h"

struct celula{
    char* nome;
    int agressividade;
    int animal;
    tCelula* prox;
};

struct lista_heterogenea{
    tCelula* primeiro;
    tCelula* ultimo;
};

tCelula* liberaCelula(tCelula* cel){
    tCelula* prox = cel->prox;
    free(cel->nome);
    free(cel);

    return prox;
}

tListaHet* inicializaLista(){
    tListaHet* lista = malloc(sizeof(tListaHet));
    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

void insereAnimalNaLista(char* nome, int agressividade, int animal, tListaHet* lista){
    tCelula* novo = malloc(sizeof(tCelula));
    novo->nome = malloc(strlen(nome)+1);

    if(lista->ultimo == NULL){
        lista->primeiro = lista->ultimo = novo;
    } else{
        lista->ultimo->prox = novo;
        lista->ultimo = lista->ultimo->prox;
    }

    lista->ultimo->animal = animal;
    lista->ultimo->agressividade = agressividade;
    strcpy(lista->ultimo->nome, nome);
    lista->ultimo->prox = NULL;
}

int buscaItem(tListaHet* lista, char* nome){
    //tCelula* ant = NULL;
    tCelula* p = lista->primeiro;

    while(p != NULL && strcmp(p->nome, nome) != 0){
        //ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return 0; 
    } else{
        return 1;
    }
}

void retiraItem(tListaHet* lista, char* nome){
    tCelula* ant = NULL;
    tCelula* p = lista->primeiro;

    while(p != NULL && strcmp(p->nome, nome) != 0){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return;

    if(p == lista->primeiro && p == lista->ultimo){
        lista->primeiro = lista->ultimo = NULL;
        liberaCelula(p);
        return; 
    }

    if(p == lista->ultimo){
        lista->ultimo = ant; 
        ant->prox = NULL; 
        liberaCelula(p);
        return;
    }

    if(p == lista->primeiro){
        lista->primeiro = p->prox;    
    } else{
        ant->prox = p->prox;
    } 

    liberaCelula(p);
}

float calculaValor(tListaHet* lista, int agressividade){
    float valor=0;
    tCelula* p = lista->primeiro;

    if(lista->primeiro == NULL) return 0;

    if(agressividade == BRAVO){
        while(p != NULL){   
            if(p->animal == GATO){
                valor += v_gato;
            } else{
                valor += v_cachorro;
            } 
            valor += v_agressivo;
            p = p->prox;
        }
    } else if(agressividade == MANSO){
        while(p != NULL){
            if(p->animal == GATO){
                valor += v_gato;
            } else{
                valor += v_cachorro;
            } 
            p = p->prox;
        }
    }

    return valor;
}

void imprimeLista(tListaHet* lista){
    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        printf("Nome: %s\n", aux->nome);
        aux = aux->prox;
    }

}

void liberaLista(tListaHet* lista){
    tCelula* aux = lista->primeiro;

    while(aux != NULL){
        aux = liberaCelula(aux);
    }

    free(lista);
}
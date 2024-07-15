#include "hash.h"

struct hash{
    tPalavra** vet;
    int tam;
};

static int hash(char* s, int tam){
    int total = 0;

    for(int i=0; s[i] != '\0'; i++) total += s[i];

    return total % tam;
}

Hash* inicializa(int tam){
    Hash* h = malloc(sizeof(Hash));

    h->tam = tam;
    h->vet = malloc(tam*sizeof(tPalavra*));

    for(int i=0; i<tam; i++){
        h->vet[i] = NULL;
    }

    return h;
}

tPalavra* acessaHash(Hash* h, char* s){
    int indice = hash(s, h->tam);

    tPalavra* p = buscaPalavra(h->vet[indice], s);

    if(p) return p;

    p = inicPalavra(s); 

    h->vet[indice] = inserePalavraLista(h->vet[indice], p);

    return p;
}

int contaPalavras(Hash* h){
    int soma=0;

    for(int i=0; i<h->tam; i++){
        soma = soma + contaPalavrasLista(h->vet[i]);
    }

    return soma;
}

void imprimeHash(Hash* h){
    for(int i=0; i<h->tam; i++){
        printf("\nPosição do vetor[%d]: \n ", i);
        imprimeLista(h->vet[i]);
    }
}

void liberaHash(Hash* h){
    for(int i=0; i<h->tam; i++){
        liberaListaPalavras(h->vet[i]);
    }

    free(h->vet);
    free(h);
}
#include "Gato.h"

struct gato{
    char* nome;
    int agressividade;
};

Gato* inicGato(char* nome, int agressividade){
    Gato* cat = malloc(sizeof(Gato));

    strcpy(cat->nome, nome);
    cat->agressividade = agressividade;

    return cat;
}

void liberaGato(Gato* cat){
    if(cat != NULL){
        free(cat->nome);
        free(cat);
    }
}

int catAgressivity(Gato* cat){
    cat->agressividade;
}

int catsName(Gato* cat){
    cat->nome;
}

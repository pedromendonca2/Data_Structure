#include "Gato.h"

struct gato{
    char* nome;
    int agressividade;
};

Gato* inicGato(char* nome, int agressividade){
    Gato* cat = malloc(sizeof(Gato));
    cat->nome = malloc(strlen(nome)+1);

    strcpy(cat->nome, nome);
    cat->agressividade = agressividade;

    return cat;
}

void atribuiNivelAgressividadeGato(Gato* cat, int agressividade){
    cat->agressividade = agressividade;
}

void liberaGato(Gato* cat){
    if(cat != NULL){
        free(cat->nome);
        free(cat);
    }
}

int catAgressivity(Gato* cat){
    return cat->agressividade;
}

char* catsName(Gato* cat){
    return cat->nome;
}

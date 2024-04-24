#include "Cachorro.h"

struct cachorro{
    char* nome;
    int agressividade;
};

Cachorro* inicCachorro(char* nome, int agressividade){
    Cachorro* dog = malloc(sizeof(Cachorro));

    strcpy(dog->nome, nome);
    dog->agressividade = agressividade;

    return dog;
}

void liberaCachorro(Cachorro* dog){
    if(dog != NULL){
        free(dog->nome);
        free(dog);
    }
}

int dogAgressivity(Cachorro* dog){
    return dog->agressividade;
}

int dogsName(Cachorro* dog){
    return dog->nome;
}
#include "Cachorro.h"

struct cachorro{
    char* nome;
    int agressividade;
};

Cachorro* inicCachorro(char* nome, int agressividade){
    Cachorro* dog = malloc(sizeof(Cachorro));
    dog->nome = malloc(strlen(nome)+1);

    strcpy(dog->nome, nome);
    dog->agressividade = agressividade;

    return dog;
}

void atribuiNivelAgressividadeCachorro(Cachorro* dog, int agressividade){
    dog->agressividade = agressividade;
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

char* dogsName(Cachorro* dog){
    return dog->nome;
}
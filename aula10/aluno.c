#include "aluno.h"

struct aluno{
    char* nome;
    int agressividade;
};

tAluno* inicAluno(char* nome, int agressividade){
    tAluno* a = malloc(sizeof(tAluno));

    a->nome = strdup(nome);
    a->agressividade = agressividade;

    return a;
}


void imprimeAluno(tAluno* a){
    printf("O aluno %s possui agressividade nivel %d\n", a->nome, a->agressividade);
}

char* retornaNome(tAluno* a){
    return a->nome;
}

void liberaAluno(tAluno* a){
    if(a != NULL){
        free(a->nome);
        free(a);
    }
}
#include "aluno.h"

struct aluno{
    char* nome;
    int matricula;
};

tAluno* inicAluno(char* nome, int matricula){
    tAluno* a = malloc(sizeof(tAluno));

    a->nome = strdup(nome);
    a->matricula = matricula;

    return a;
}


void imprimeAluno(tAluno* a){
    printf("O aluno %s possui matricula %d\n", a->nome, a->matricula);
}

char* retornaNome(tAluno* a){
    return a->nome;
}

int retornaMatricula(tAluno* a){
    return a->matricula;
}

void liberaAluno(tAluno* a){
    if(a != NULL){
        free(a->nome);
        free(a);
    }
}
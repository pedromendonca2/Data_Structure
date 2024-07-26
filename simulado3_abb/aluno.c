#include "aluno.h"

struct aluno{
    char* nome;
    int presencas;
    int faltas;
};

tAluno* criaAluno(char* nome){
    tAluno* a = malloc(sizeof(tAluno));

    a->nome = strdup(nome);
    a->faltas = 0;
    a->presencas = 0;

    return a;
}

int retornaPresencas(tAluno* aluno){
    return aluno->presencas;
}

int retornaFaltas(tAluno* aluno){
    return aluno->faltas;
}

char* retornaNome(tAluno* aluno){
    return aluno->nome;
}

void imprimeAluno(tAluno* aluno){
    printf("%s %dP %dF\n", aluno->nome, aluno->presencas, aluno->faltas);
}

void incrementaAluno(tAluno* a, char p){
    if(p == 'P') a->presencas++;
    else a->faltas++;
}

void liberaAluno(tAluno* aluno){
    free(aluno->nome);
    free(aluno);
}
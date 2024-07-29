#include "aluno.h"

struct aluno{
    char* nome;
    int presencas;
    int faltas;
    tAluno* prox;
};

tAluno* criaAluno(char* nome){
    tAluno* a = malloc(sizeof(tAluno));

    a->nome = strdup(nome);
    a->faltas = 0;
    a->presencas = 0;
    a->prox = NULL;

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

void imprimeAlunos(tAluno* aluno, FILE* file){
    tAluno* aux;

    for(aux = aluno; aux != NULL; aux = aux->prox){
        fprintf(file, "%s %dP %dF\n", aux->nome, aux->presencas, aux->faltas);
    }
}

void incrementaAluno(tAluno* a, char p){
    if(p == 'P') a->presencas++;
    else a->faltas++;
}

tAluno* buscaAlunoLista(tAluno* aluno, char* s){
    tAluno* aux;

    for(aux = aluno; aux != NULL; aux = aux->prox){
        if(strcmp(s, aux->nome) == 0) return aux;
    }

    return NULL;
}

tAluno* insereAlunoLista(tAluno* lista, tAluno* aluno){
    aluno->prox = lista;

    return aluno;
}

void liberaAluno(tAluno* aluno){
    if (aluno != NULL) {
        liberaAluno(aluno->prox);  // Libera recursivamente
        free(aluno->nome);
        free(aluno);
    }
}
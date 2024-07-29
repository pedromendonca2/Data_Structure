#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno tAluno;

tAluno* criaAluno(char* nome);

int retornaPresencas(tAluno* aluno);

int retornaFaltas(tAluno* aluno);

char* retornaNome(tAluno* aluno);

tAluno* buscaAlunoLista(tAluno* aluno, char* s);

tAluno* insereAlunoLista(tAluno* lista, tAluno* aluno);

void imprimeAqui(tAluno* aluno);

void imprimeAluno(tAluno* aluno, FILE* file);

void incrementaAluno(tAluno* a, char p);

void liberaAluno(tAluno* aluno);

#endif
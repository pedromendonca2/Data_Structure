#ifndef aluno_h
#define aluno_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno tAluno;

tAluno* inicAluno(char* nome, int agressividade);

void imprimeAluno(tAluno* a);

char* retornaNome(tAluno* a);

void liberaAluno(tAluno* cat);

#endif
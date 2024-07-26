#ifndef ABB_H
#define ABB_H

#include "aluno.h"

typedef struct abb tArvore;

tArvore* iniciaArv(void);

tArvore* buscaArvore(tArvore* r, char* nome, char presenca);

tArvore* insereAluno(tArvore* r, tAluno* aluno);

tArvore* retiraAluno(tArvore* r, tAluno* aluno);

void imprimeArvore(tArvore* r);

void liberaArvore(tArvore* r);

#endif
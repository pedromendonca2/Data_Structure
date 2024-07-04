#ifndef arvalunogen_h
#define arvalunogen_h

#include "aluno.h"
#include "abbGenerica.h"

void imprimeCallBack(void* aluno);

void liberaCallBack(void* aluno);

int comparaCallBack(void* dado_1, void* dado_2);

void imprimeArvoreAluno(tArvore* arv);

void liberaArvoreAluno(tArvore* arv);

tArvore* buscaArvoreAluno(tArvore* arv, void* dado);

tArvore* insereArvoreAluno(tArvore* arv, void* dado);

tArvore* retiraArvoreAluno(tArvore* arv, void* dado);

#endif
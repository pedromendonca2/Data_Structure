#include "arvAlunoGen.h"

void imprimeCallBack(void* aluno){
    imprimeAluno((tAluno*) aluno);
}

void imprimeArvoreAluno(tArvore* arv)
{
    imprime(imprimeCallback(arv));
}
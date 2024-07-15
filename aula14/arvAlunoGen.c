#include "arvAlunoGen.h"

void imprimeCallBack(void* aluno){
    imprimeAluno((tAluno*) aluno);
}

void liberaCallBack(void* aluno){
    liberaAluno((tAluno*) aluno);
}

int comparaCallBack(void* dado_1, void* dado_2){
    return strcmp(retornaNome(((tAluno*)dado_1)), retornaNome(((tAluno*)dado_2)));
}

void imprimeArvoreAluno(tArvore* arv){
    abb_imprime(arv, imprimeCallBack);
}

void liberaArvoreAluno(tArvore* arv){
    liberaArvore(arv, liberaCallBack);
}

tArvore* buscaArvoreAluno(tArvore* arv, void* dado){
    return abb_busca(arv, dado, comparaCallBack);
}

tArvore* insereArvoreAluno(tArvore* arv, void* dado){
    return abb_insere(arv, dado, comparaCallBack);
}

tArvore* retiraArvoreAluno(tArvore* arv, void* dado){
    return abb_retira(arv, dado, comparaCallBack, liberaCallBack);
}

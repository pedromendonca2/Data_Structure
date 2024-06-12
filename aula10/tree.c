#include "tree.h"

struct arvore{
    tAluno* aluno;
    Arv* sae;
    Arv* sad;
};

int arvoreVazia(Arv* a){
    return a==NULL;
}

Arv* inicArvore(tAluno* a, Arv* sae, Arv* sad){
    Arv* tree = malloc(sizeof(Arv));

    tree->aluno = a;
    tree->sad = sad;
    tree->sae = sae;

    return tree;
}

int pertenceArvore(Arv* tree, tAluno* a){
    if(arvoreVazia(tree)) return 0;
    else return tree->aluno==a || pertenceArvore(tree->sae, a) || pertenceArvore(tree->sad, a);
}

void imprimeArvore(Arv* a){
    if(!arvoreVazia(a)){
        imprimeAluno(a->aluno);
        imprimeArvore(a->sae);
        imprimeArvore(a->sad);
    }
}

int folhas (Arv* a){
    if(!arvoreVazia(a)){
        if(a->sae == NULL && a->sad == NULL) return 1;
        return folhas(a->sae) + folhas(a->sad);
    }

    return 0;
} //retorna o número de folhas da árvore

int ocorrencias (Arv* a , char* nome){
    if(!arvoreVazia(a)){
        if(strcmp(retornaNome(a->aluno), nome) == 0) return 1 + ocorrencias(a->sae, nome) + ocorrencias(a->sad, nome);
        return ocorrencias(a->sae, nome) + ocorrencias(a->sad, nome);
    }

    return 0;
} //retorna o número de vezes que o aluno aparece na árvore

int altura (Arv* a){

    if(!arvoreVazia(a)){
        if(a->sae == NULL && a->sad == NULL) return 0;

        int tamEsq = altura(a->sae) + 1;
        int tamDir = altura(a->sad) + 1;

        if(tamEsq > tamDir) return tamEsq;
        else return tamDir;
    }

    return -1;
} //retorna a altura da árvore

Arv* liberaArvore(Arv* a){
    if(!arvoreVazia(a)){
        liberaArvore(a->sae);
        liberaArvore(a->sad);
        liberaAluno(a->aluno);
        free(a);
    }
    return NULL;
}


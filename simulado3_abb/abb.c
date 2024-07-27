#include "abb.h"

struct abb{
    tAluno* aluno;
    tArvore* esq;
    tArvore* dir;
};

tArvore* iniciaArv(void){
    return NULL;
}

tArvore* buscaArvore(tArvore* r, char* nome, char presenca){

    if(r == NULL){
        return NULL;
    } else if(strcmp(retornaNome(r->aluno), nome) > 0){
        return buscaArvore(r->esq, nome, presenca); //volta como return !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    } else if(strcmp(retornaNome(r->aluno), nome) < 0){
        return buscaArvore(r->dir, nome, presenca);
    } else{
        incrementaAluno(r->aluno, presenca);
        return r;
    }
}

tArvore* insereAluno(tArvore* r, tAluno* aluno){
    if(r == NULL){

        r = malloc(sizeof(tArvore)); //nao precisa de tArvore*
        r->aluno = aluno;
        r->dir = NULL;
        r->esq = NULL;
    } else if(strcmp(retornaNome(aluno), retornaNome(r->aluno)) < 0){
        r->esq = insereAluno(r->esq, aluno); //r->esq que recebe !!!!!!!!!!!!!!!
    } else{
        r->dir = insereAluno(r->dir, aluno);
    }

    return r;
}

tArvore* retiraAluno(tArvore* r, tAluno* aluno){
    if(r == NULL){
        return NULL;
    } else if(strcmp(retornaNome(aluno), retornaNome(r->aluno)) < 0){
        r->esq = retiraAluno(r->esq, aluno); //r->esq que recebe !!!!!!!!!!!!!!!!!!!!!
    } else if(strcmp(retornaNome(aluno), retornaNome(r->aluno)) > 0){
        r->dir = retiraAluno(r->dir, aluno);
    } else{
        if(r->dir == NULL && r->esq == NULL){
            tArvore* t = r;
            liberaAluno(t->aluno);
            free(t);
            r = NULL; //r = NULL
        } else if(r->dir == NULL){
            tArvore* t = r;
            r = r->esq;
            liberaAluno(t->aluno);
            free(t);
        } else if(r->esq == NULL){
            tArvore* t = r;
            r = r->dir;
            liberaAluno(t->aluno);
            free(t);
        } else{
            tArvore* t = r->esq;
            while(t->dir != NULL){ //t->dir !!!!!!!!!!!!!!!!!!!
                t = t->dir;
            }
            r->aluno = t->aluno; //nessa ordem !!!!!!!!!!!!
            t->aluno = aluno;
            r->esq = retiraAluno(r->esq, aluno);
        }
    }

    return r;
}

void imprimeArvore(tArvore* r, FILE* file){
    if(r != NULL){
        imprimeArvore(r->dir, file);
        imprimeArvore(r->esq, file);
        imprimeAluno(r->aluno, file);
    }
}

void liberaArvore(tArvore* r){
    if(r != NULL){
        liberaArvore(r->dir);
        liberaArvore(r->esq);
        liberaAluno(r->aluno);
        free(r);
    }
}



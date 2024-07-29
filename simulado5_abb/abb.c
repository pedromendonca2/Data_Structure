#include "abb.h"

struct abb{
    char* palavra;
    int frequencia;
    tArvore* esq;
    tArvore* dir;
};

tArvore* criaABB(void){
    return NULL;
}

tArvore* insereArvore(tArvore* arv, char* s){
    if(arv == NULL){
        arv = malloc(sizeof(tArvore)); //NAO ESQUECE DO MALLOC
        arv->palavra = strdup(s);
        arv->frequencia = 1;
        arv->dir = NULL;
        arv->esq = NULL;
    } else{
        if(strcmp(s, arv->palavra) < 0){
            arv->esq = insereArvore(arv->esq, s); //TEM QUE TER FUNCAO INSERE
        } else if(strcmp(s, arv->palavra) > 0){
            arv->dir = insereArvore(arv->dir, s);
        } else{
            arv->frequencia++;
        }
    }

    return arv;
}

tArvore* retiraArvore(tArvore* arv, char* s){
    if(arv == NULL){
        return NULL;
    } else if(strcmp(s, arv->palavra) < 0){
        arv->esq = retiraArvore(arv->esq, s);
    } else if(strcmp(s, arv->palavra) > 0){
        arv->dir = retiraArvore(arv->dir, s);
    } else{
        if(arv->esq == NULL && arv->dir == NULL){
            free(arv->palavra);
            free(arv);
            arv = NULL;
        } else if(arv->esq == NULL){
            tArvore* t = arv; //RECEBE ARV, NAO ARV->DIR
            arv = arv->dir;
            free(t->palavra);
            free(t);
        } else if(arv->dir == NULL){
            tArvore* t = arv;
            arv = arv->esq;
            free(t->palavra);
            free(t);
        } else{
            tArvore* t = arv->esq;
            while(t->dir != NULL){
                t = t->dir;
            }
            arv->palavra = strdup(t->palavra);
            t->palavra = s;
            arv->esq = retiraArvore(arv->esq, s);
        }
    }

    return arv;
}

void preencheVetor(tArvore* arv, tPalavraFreq* vetor, int* indice){
    if(arv != NULL){
        preencheVetor(arv->dir, vetor, indice);
        preencheVetor(arv->esq, vetor, indice);
        vetor[*indice].palavra = strdup(arv->palavra);
        vetor[*indice].frequencia = arv->frequencia;
        (*indice)++;
    }
}

int compara(const void* a, const void* b){
    tPalavraFreq* pa = (tPalavraFreq*)a;
    tPalavraFreq* pb = (tPalavraFreq*)b;
    return pa->frequencia - pb->frequencia;
}

void contaPalavras(tArvore* arv, int* total, int* distintas, tArvore** maiorFreq){
    if(arv != NULL){
        contaPalavras(arv->dir, total, distintas, maiorFreq);
        contaPalavras(arv->esq, total, distintas, maiorFreq);
        (*total) += arv->frequencia;
        (*distintas)++;
        if(*maiorFreq == NULL || arv->frequencia > (*maiorFreq)->frequencia){
            *maiorFreq = arv;
        }
    }
}

char* retornaPalavra(tPalavraFreq p){
    return p.palavra;
}

int retornaFrequencia(tPalavraFreq p){
    return p.frequencia;
}

char* retornaPalavraArv(tArvore* a){
    return a->palavra;
}

int retornaFrequenciaArv(tArvore* a){
    return a->frequencia;
}

void liberaArvore(tArvore* arv){
    if(arv != NULL){
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv->palavra);
        free(arv);
    }
}
#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct abb tArvore;

typedef struct palavrafreq tPalavraFreq;

struct palavrafreq{
    char* palavra;
    int frequencia;
};

tArvore* criaABB(void);

tArvore* insereArvore(tArvore* arv, char* s);

tArvore* retiraArvore(tArvore* arv, char* s);

void preencheVetor(tArvore* arv, tPalavraFreq* vetor, int* indice);

int compara(const void* a, const void* b);

void contaPalavras(tArvore* arv, int* total, int* distintas, tArvore** maiorFreq);

char* retornaPalavra(tPalavraFreq p);

int retornaFrequencia(tPalavraFreq p);

char* retornaPalavraArv(tArvore* a);

int retornaFrequenciaArv(tArvore* a);

void liberaArvore(tArvore* arv);

#endif 
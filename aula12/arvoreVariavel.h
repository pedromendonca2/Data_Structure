#ifndef arvoreVariavel_h
#define arvoreVariavel_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv tArvore;

tArvore* arvoreCria (char c);

void arvoreInsere (tArvore* a, tArvore* sa);

void arvoreImprime (tArvore* a);

int arvorePertence (tArvore* a, char c);

void arvoreLibera (tArvore* a);

int arvoreAltura(tArvore* a);

int numFolhas(tArvore* a);

int numNosComUmFilho(tArvore* a);

#endif
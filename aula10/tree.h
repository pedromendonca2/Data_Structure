#ifndef tree_h
#define tree_h

#include "aluno.h"

typedef struct arvore Arv;

int arvoreVazia(Arv* a);

Arv* inicArvore(tAluno* a, Arv* sae, Arv* sad);

int pertenceArvore(Arv* tree, tAluno* a);

void imprimeArvore(Arv* a);

int folhas (Arv* a); //retorna o número de folhas da árvore

int ocorrencias (Arv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore

int altura (Arv* a); //retorna a altura da árvore

Arv* liberaArvore(Arv* a);

#endif
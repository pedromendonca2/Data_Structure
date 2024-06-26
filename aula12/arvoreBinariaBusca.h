#include "aluno.h"

typedef struct arv tArvore;

tArvore *abb_cria(void);

void abb_imprime(tArvore *a);

tArvore *abb_busca(tArvore *r, int v);

tArvore *abb_insere(tArvore *a, tAluno* aluno);

tArvore *abb_retira(tArvore *r, tAluno* aluno);

void liberaArvore(tArvore* r);
#include "arvoreBinariaBusca.h"

struct arv
{
    tAluno* a; // matricula
    tArvore *esq;
    tArvore *dir;
};

tArvore *abb_cria(void)
{
    return NULL;
}

void abb_imprime(tArvore *a)
{
    if (a != NULL)
    {
        abb_imprime(a->esq);
        imprimeAluno(a->a);
        abb_imprime(a->dir);
    }
}

tArvore *abb_busca(tArvore *r, int v)
{
    if (r == NULL)
        return NULL;
    else if (retornaMatricula(r->a) > v)
        return abb_busca(r->esq, v);
    else if (retornaMatricula(r->a) < v)
        return abb_busca(r->dir, v);
    else
        return r;
}

tArvore *abb_insere(tArvore *a, tAluno* aluno)
{
    if (a == NULL)
    {
        a = (tArvore *)malloc(sizeof(tArvore));
        a->a = aluno;
        a->esq = a->dir = NULL;
    }

    else if (retornaMatricula(aluno) < retornaMatricula(a->a))
        a->esq = abb_insere(a->esq, aluno);
    else
        a->dir = abb_insere(a->dir, aluno);

    return a;
}

tArvore *abb_retira(tArvore *r, tAluno* aluno)
{
    if (r == NULL)
        return NULL;
    else if (retornaMatricula(r->a) > retornaMatricula(aluno))
        r->esq = abb_retira(r->esq, aluno);
    else if (retornaMatricula(r->a) < retornaMatricula(aluno))
        r->dir = abb_retira(r->dir, aluno);

    else
    { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL)
        {
            tArvore* t = r;
            liberaAluno(t->a);
            free(t);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL)
        {
            tArvore *t = r;
            r = r->dir;
            liberaAluno(t->a);
            free(t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL)
        {
            tArvore *t = r;
            r = r->esq;
            liberaAluno(t->a);
            free(t);
        }
        /* nó tem os dois filhos */
        else
        {
            tArvore *f = r->esq;
            while (f->dir != NULL)
            {
                f = f->dir;
            }
            r->a = f->a; /* troca as informações */
            f->a = aluno;
            r->esq = abb_retira(r->esq, aluno);
        }
    }
    return r;
}

void liberaArvore(tArvore* r)
{
    if(r!=NULL){
        liberaArvore(r->esq);
        liberaArvore(r->dir);
        liberaAluno(r->a);
        free(r);
    }
}
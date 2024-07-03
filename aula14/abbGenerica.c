#include "abbGenerica.h"

struct arvore{
    void* dado;
    tArvore* esq;
    tArvore* dir;
};

tArvore* abb_cria(void)
{
    return NULL;
}

void abb_imprime(tArvore* a, imprime print)
{
    if (a != NULL)
    {
        abb_imprime(a->esq, print);
        print(a->dado);
        abb_imprime(a->dir, print);
    }
}

tArvore *abb_busca(tArvore *r, void* dado, retorna returnData, compara compare) //dado pode ser nome ou matricula
{
    if (r == NULL)
        return NULL;
    else if (compare(returnData(r->dado), dado) == 1) //returnData(r->dado) > v
        return abb_busca(r->esq, dado, returnData, compare);
    else if (compare(returnData(r->dado), dado) == -1)
        return abb_busca(r->dir, dado, returnData, compare);
    else
        return r;
}

tArvore *abb_insere(tArvore *a, void* dado, compara compare)
{
    if (a == NULL)
    {
        a = (tArvore *)malloc(sizeof(tArvore));
        a->dado = dado;
        a->esq = a->dir = NULL;
    }

    else if (compare(dado, a->dado))
        a->esq = abb_insere(a->esq, dado, compare);
    else
        a->dir = abb_insere(a->dir, dado, compare);

    return a;
}

tArvore *abb_retira(tArvore *r, void* dado, compara compare)
{
    if (r == NULL)
        return NULL;
    else if (compare(r->dado, dado) == 1)
        r->esq = abb_retira(r->esq, dado, compare);
    else if (compare(r->dado, dado) == -1)
        r->dir = abb_retira(r->dir, dado, compare);

    else
    { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL)
        {
            tArvore *t = r;
            r = r->dir;
            free(t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL)
        {
            tArvore *t = r;
            r = r->esq;
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
            r->dado = f->dado; /* troca as informações */
            f->dado = dado;
            r->esq = abb_retira(r->esq, dado, compare);
        }
    }
    return r;
}

void liberaArvore(tArvore* r, libera freeData)
{
    if(r!=NULL){
        liberaArvore(r->esq, freeData);
        liberaArvore(r->dir, freeData);

        lfreeData(r->dado);
        free(r);
    }
}
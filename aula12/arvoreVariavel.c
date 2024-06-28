#include "arvoreVariavel.h"

struct arv{
    char info;
    tArvore* prim; //primeiro filho
    tArvore* prox; //eventual irmao
};

tArvore* arvoreCria (char c){
    tArvore* a = malloc(sizeof(tArvore));

    a->info = c;
    a->prim = NULL;
    a->prox = NULL;

    return a;
}

//Seu filho virou meu irmao e agora eu sou seu filho
void arvoreInsere (tArvore* a, tArvore* sa){
    sa->prox = a->prim; //o antigo filho da arvore vira o irmao da sub-arvore
    a->prim = sa; //filho da arvore recebe sub-arvore
}

void arvoreImprime (tArvore* a){
    tArvore* p;

    printf("<%c", a->info);

    for(p=a->prim; p!=NULL; p=p->prox){
        arvoreImprime(p);
    }
    printf(">");
}

int arvorePertence (tArvore* a, char c){
    tArvore* p;

    if(a->info == c) return 1;

    for(p=a->prim; p!=NULL; p=p->prox){
        if(arvorePertence(p, c)) return 1;
    }
    
    return 0;
}

void arvoreLibera (tArvore* a){ //p recebe o filho, aux recebe o irmao do filho, liberando todos os irmaos e, no final, o filho
    tArvore* p = a->prim;

    while(p!=NULL){
        tArvore* aux = p->prox;
        arvoreLibera(p);
        p = aux;
    }

    free(a);
}

int arvoreAltura(tArvore* a){
    int hMax=-1;
    tArvore* p;

    for(p=a->prim; p!=NULL; p=p->prox){
        int h = arvoreAltura(p);
        if(h > hMax) hMax = h;
    }

    return hMax+1;
}

int numFolhas(tArvore* a){
    tArvore* p;
    int n=0;

    if(a->prim == NULL) return 1;

    for(p=a->prim; p!=NULL; p=p->prox){
        n = n + numFolhas(p);
    }

    return n;
}

int numNosComUmFilho(tArvore* a){
    tArvore* p;
    int n=0;

    if(a->prim != NULL && a->prim->prox == NULL) n = 1;

    for(p=a->prim; p!=NULL; p=p->prox){
        n += numNosComUmFilho(p);
    }

    return n;
}
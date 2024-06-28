#include "arvoreBinariaBusca.h"


int main(){

    tAluno* a1 = inicAluno("Sodras", 111);
    tAluno* a2 = inicAluno("Frank Sinatra", 222);
    tAluno* a3 = inicAluno("Bento XVI", 333);

    tArvore* arv = abb_cria();

    arv = abb_insere(arv, a1);
    arv = abb_insere(arv, a2);
    arv = abb_insere(arv, a3);
    abb_imprime(arv);
    printf("\n");

    arv = abb_retira(arv, a3);
    abb_imprime(arv);

    liberaArvore(arv);

    return 0;
}
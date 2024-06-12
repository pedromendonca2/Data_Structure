#include "tree.h"

int main(){

    tAluno* al1 = inicAluno("Pedro", 200);
    tAluno* al2 = inicAluno("Joss", 0); 
    tAluno* al3 = inicAluno("Sodras", 1000000);

    Arv* a = inicArvore(al1, NULL, NULL);
    Arv* b = inicArvore(al2, NULL, NULL);
    Arv* c = inicArvore(al3, a, b);

    printf("Ocorrencias: %d\n", ocorrencias(c, "Pedro"));
    printf("Altura: %d\n", altura(c));
    printf("Folhas: %d\n", folhas(c));

    imprimeArvore(c);

    liberaArvore(c);

    return 0;
}
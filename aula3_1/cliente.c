#include "matriz.h"

int main(){

    int nlinhas1, ncolunas1, nlinhas2, ncolunas2;

    printf("Digite o numero de linhas e colunas da primeira e da segunda matriz: \n");
    scanf("%d %d %d %d", &nlinhas1, &ncolunas1, &nlinhas2, &ncolunas2);

    Matriz* mat1 = inicializaMatriz(nlinhas1, ncolunas1);
    Matriz* mat2 = inicializaMatriz(nlinhas2, ncolunas2);

    printf("Digite os elementos da matriz 1: \n");
    for(int i=0; i<nlinhas1; i++){
        for(int j=0; j<ncolunas1; j++){
            int elem;
            scanf("%d", &elem);
            modificaElemento(mat1, i, j, elem);
        }
    }

    printf("Digite os elementos da matriz 2: \n");
    for(int i=0; i<nlinhas2; i++){
        for(int j=0; j<ncolunas2; j++){
            int elem;
            scanf("%d", &elem);
            modificaElemento(mat2, i, j, elem);
        }
    }

    imprimeMatriz(mat1);
    imprimeMatriz(mat2);

    Matriz* matriz_trans = transposta(mat1);
    printf("Matriz transposta: \n");
    imprimeMatriz(matriz_trans);

    Matriz* matriz_mult = multiplicacao(mat1, mat2);
    printf("Matriz multiplicacao: \n");
    imprimeMatriz(matriz_mult);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(matriz_trans);
    destroiMatriz(matriz_mult);

    return 0;
}


#include "matriz.h"

struct matriz{
    int linhas;
    int colunas;
    int** mat;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    if(ncolunas == 0 || nlinhas == 0) exit(0);

    Matriz* matriz = malloc(sizeof(Matriz));

    matriz->colunas = ncolunas;
    matriz->linhas = nlinhas;

    matriz->mat = malloc(nlinhas*sizeof(int*));

    for(int i=0; i<nlinhas; i++){
        matriz->mat[i] = malloc(ncolunas*sizeof(int));
    }    

    return matriz;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(mat == NULL) exit(1);

    mat->mat[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: mat n„o È modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna){
    if(mat == NULL){
        exit(1);
    }

    return mat->mat[linha][coluna]; 
}

/*Retorna o n˙mero de colunas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNColunas (Matriz* mat){
    if(mat == NULL) exit(1);

    return mat->colunas;
}

/*Retorna o n˙mero de linhas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNLinhas (Matriz* mat){
    if(mat == NULL) exit(1);

    return mat->linhas;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){
    if(mat == NULL) exit(1);

    Matriz* mat_trans = inicializaMatriz(mat->colunas, mat->linhas);

    for(int i=0; i<mat->colunas; i++){
        for(int j=0; j<mat->linhas; j++){
            mat_trans->mat[i][j] = recuperaElemento(mat, j, i);
        }
    }

    return mat_trans;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicaÁ„o
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 n„o s„o modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1 == NULL || mat2 == NULL || mat1->colunas != mat2->linhas) exit(1);

    Matriz* mat_mult = inicializaMatriz(mat1->linhas, mat2->colunas);

    for(int i=0; i<mat1->linhas; i++){
        for(int j=0; j<mat2->colunas; j++){
            int aux=0;
            for(int k=0; k<mat1->colunas; k++){ //ou mat2->linhas
                aux += recuperaElemento(mat1, i, k)*recuperaElemento(mat2, k, j);
            }
            modificaElemento(mat_mult, i, j, aux);
        }
    }

    return mat_mult;
}

/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat){
    if(mat == NULL) exit(1);

    for(int i=0; i<mat->linhas; i++){
        for(int j=0; j<mat->colunas; j++){
            printf("%d ", recuperaElemento(mat, i, j));
        }
        printf("\n");
    }

    printf("\n");
}

void destroiMatriz(Matriz* mat){
    for(int i=0; i<mat->linhas; i++){
        //for(int j=0; j<mat->colunas; j++){
            free(mat->mat[i]);
        //}
    }
    free(mat->mat);
    free(mat);
}
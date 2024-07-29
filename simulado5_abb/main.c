#include "abb.h"

int main(){

    tArvore* arv = criaABB();

    FILE* file_pointer_1 = fopen("entrada.txt", "r");
    if(file_pointer_1 == NULL) exit(1);

    char pal[100];

    while(fscanf(file_pointer_1, "%s", pal) == 1){
        arv = insereArvore(arv, pal);
    }

    int totalPalavras = 0, distintasPalavras = 0;
    tArvore* maiorFreq = NULL; //guarda uma arvore

    contaPalavras(arv, &totalPalavras, &distintasPalavras, &maiorFreq);

    tPalavraFreq* vetor = malloc(distintasPalavras * sizeof(tPalavraFreq));
    int indice = 0;
    preencheVetor(arv, vetor, &indice);

    qsort(vetor, distintasPalavras, sizeof(tPalavraFreq), compara);

    for(int i = 0; i < distintasPalavras; i++){
        printf("%s %d\n", retornaPalavra(vetor[i]), retornaFrequencia(vetor[i]));
    }

    printf("------------------------\n");
    printf("%d palavras distintas encontradas\n", distintasPalavras);
    printf("%d palavras no total\n", totalPalavras);
    printf("%s é a palavra de maior frequência (%d)\n", retornaPalavraArv(maiorFreq), retornaFrequenciaArv(maiorFreq));

    liberaArvore(arv);
    for(int i=0; i<distintasPalavras; i++){
        free(vetor[i].palavra);
    }
    free(vetor);
    fclose(file_pointer_1);

    return 0;
}
#include "abb.h"

int main(){

    FILE* file_pointer = fopen("entrada.txt", "r");
    if(file_pointer == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    int n_arq;
    fscanf(file_pointer, "N %d", &n_arq);

    tArvore* arv = iniciaArv();

    char nome[100];
    while(fscanf(file_pointer, "%s", nome) == 1){
        tAluno* a = criaAluno(nome);
        arv = insereAluno(arv, a);
    }

    for(int i=1; i<=n_arq; i++){
        char nomeArquivo[30];
        sprintf(nomeArquivo, "entrada%d.txt", i);

        FILE* file_pointer_2 = fopen(nomeArquivo, "r");

        char nome[30], presenca;
        while(fscanf(file_pointer_2, "%s %c", nome, &presenca) == 2){
            buscaArvore(arv, nome, presenca);
        }

        fclose(file_pointer_2);
    }

    FILE* file_pointer_3 = fopen("saida.txt", "a");
    if(file_pointer_3 == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    imprimeArvore(arv, file_pointer_3);

    liberaArvore(arv);

    fclose(file_pointer);
    fclose(file_pointer_3);

    return 0;
}
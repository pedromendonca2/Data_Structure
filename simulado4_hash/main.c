#include "hash.h"

int main(){

    tHash* hash = inicializaHash(NTAB); //EH ASSIM OH

    FILE* file_pointer_1 = fopen("entrada.txt", "r");
    if(file_pointer_1 == NULL){
        printf("Deu ruim no 1");
        exit(1);
    }

    int n;
    fscanf(file_pointer_1, "N %d", &n);

    char nome_aluno[30];
    while(fscanf(file_pointer_1, "%s", nome_aluno) == 1){
        acessaHash(hash, nome_aluno, ' ');
    }

    for(int i=1; i<=n; i++){

        char nome_arquivo[100];
        sprintf(nome_arquivo, "entrada%d.txt", i);

        FILE* file_pointer_2 = fopen(nome_arquivo, "r");
        if(file_pointer_2 == NULL){
            printf("Deu ruim no 2");
            exit(1);
        } 

        char nome[30], p;

        while(fscanf(file_pointer_2, "%s %c", nome, &p) == 2){
            acessaHash(hash, nome, p);
        }

        fclose(file_pointer_2);
    }

    FILE* file_pointer_3 = fopen("saida.txt", "a");
    if(file_pointer_3 == NULL){
        printf("Deu ruim no 3");
        exit(1);
    }

    //imprimeHashAqui(hash);
    imprimeHash(hash, file_pointer_3);

    liberaHash(hash);
    fclose(file_pointer_1);
    fclose(file_pointer_3);

    return 0;
}
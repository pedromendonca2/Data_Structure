#include "hash.h"

int main(){

    FILE *file_pointer = fopen("./texto.txt", "r");
    if (file_pointer == NULL)
    {
        printf("Arquivo nao foi aberto corretamente\n");
        exit(1);
    }

    char n[NPAL];
    Hash* tab;
    tab = inicializa(NTAB);

    while(fscanf(file_pointer, "%s", n) == 1){
        tPalavra* p = acessaHash(tab, n);
        atualizaOcorrencias(p);
    }

    imprimeHash(tab);
    liberaHash(tab);

    fclose(file_pointer);

    return 0;
}
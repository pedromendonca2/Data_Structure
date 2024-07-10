#include "hash.h"

int main(){

    FILE *file_pointer = fopen("./texto.txt", "r");
    if (file_pointer == NULL)
    {
        printf("Arquivo nao foi aberto corretamente\n");
        exit(1);
    }

    char n[NPAL];

    while(fscanf(file_pointer, "%[^ ]", &n) == 1){
        // for(int i=0; i<MAX_CHAR; i++){
        //     if(i == n) V[i]++;
        // }
    }

    return 0;
}
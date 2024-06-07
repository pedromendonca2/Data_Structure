#include <stdio.h>
#include <stdlib.h>

int** inverte2 (int n, int* vet){
    int **vet2 = malloc(n*sizeof(int*));

    for(int i=0; i<n; i++){
        vet2[i] = &vet[i];
    }

    return vet2;
}

int main(){
    
    int n;
    scanf("%d", &n);

    int *vetor = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]); //POR QUE O '&' AQUI?
    }

    int *aux = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        aux[i] = vetor[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if (aux[i] > aux[j]){
                int temp = aux[i];
                aux[i] = aux[j];
                aux[j] = temp;
            }
        }
    }

    int **vet2 = inverte2(n, aux);
    for(int i=0; i<n; i++){
        printf("Endereco: %p\n", vet2[i]);
    }

    free(aux);
    free(vet2);
    free(vetor);

    return 0;
}

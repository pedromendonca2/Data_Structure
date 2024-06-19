// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h> 

// int main(){

//     int n = 1000000000;
//     int chave;

//     int *vet = malloc(sizeof(int)*n);

//     time_t t1 = time(0), t2;

//     srand(time(NULL));

//     for(int i=0; i<n; i++){
//         vet[i] = rand();

//         if(i==n-1) chave = vet[i];
//     }

//     for(int i=0; i<n; i++){
//         if(vet[i] == chave){
//             printf("END\n\n");
//             t2 = time(0);
//             printf("tempo: %ld\n", t2-t1);
//         }
//     }

//     free(vet);

//     return 0;
// }
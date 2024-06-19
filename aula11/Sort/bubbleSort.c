// #include <stdio.h>
// #include <stdlib.h>

// int main(){

//     int n = 100000;
//     int vet[n];

//     for(int i=0; i<n; i++){
//         vet[i] = rand();
//     }

//     for(int i=0; i<n; i++){
//         for(int j=0; j<(n-i-1); j++){
//             if(vet[j]>vet[j+1]){
//                 int temp = vet[j];
//                 vet[j] = vet[j+1];
//                 vet[j+1] = temp;  
//             }
//         }
//     }

//     printf("END\n");

//     return 0;
// }
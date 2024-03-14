#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

void calc_esfera(float r, float* area, float* volume){
    *area = 4*pi*pow(r, 2);

    *volume = (4*pi*pow(r, 3))/3;
}

int raizes(float a, float b, float c, float* x1, float* x2){
    float delta = pow(b, 2) - 4*a*c;

    if(delta < 0){
        return 0;
    }

    *x1 = ((-1)*b + sqrt(delta)) / 2*a;
    *x2 = ((-1)*b - sqrt(delta)) / 2*a;

    return 1;
}

int pares (int n, int* vet){
    int qtd=0;

    for(int i=0; i<n; i++){
        if(vet[i]%2 == 0){
            qtd++;
        }
    }

    return qtd;
}

void inverte (int n, int* vet){
    for(int i=0; i<n/2; i++){
        int aux = vet[i];
        vet[i] = vet[n-i-1];
        vet[n-i-1] = aux;
    }
}

double avalia (double* poli, int grau, double x){
    double result=0;

    for(int i=0; i<=grau; i++){
        result += poli[i]*pow(x, i);
    }

    return result;
}

int main(){

    float raio = 2;
    float *area = malloc(sizeof(float));
    float *volume = malloc (sizeof(float));

    calc_esfera(raio, area, volume);
    printf("Area: %.2f e volume: %.2f\n", *area, *volume);

    free(area);
    free(volume);

    return 0;
}

// int main(){

//     float a=1, b=6, c=4;
//     float *x1 = malloc(sizeof(float));
//     float *x2 = malloc(sizeof(float));

//     raizes(a, b, c, x1, x2);
//     printf("Raizes: %.2f e %.2f", *x1, *x2);

//     free(x1);
//     free(x2);

//     return 0;
// }

// int main(){

//     float n=3;
//     int *vet = malloc(3*sizeof(float));
    
//     vet[0] = 8;
//     vet[1] = 4;
//     vet[2] = 6;

//     printf("Num de pares: %d\n", pares(n, vet));

//     free(vet);

//     return 0;
// }

// int main(){

//     float n=4;
//     int *vet = malloc(4*sizeof(float));
    
//     vet[0] = 2;
//     vet[1] = 4;
//     vet[2] = 6;
//     vet[3] = 8;

//     inverte(n, vet);

//     printf("vetores trocados: %d %d %d %d\n", vet[0], vet[1], vet[2], vet[3]);

//     free(vet);

//     return 0;
// }

// int main(){

//     int grau;
//     scanf("%d", &grau);

//     double x;
//     scanf("%lf", &x);

//     double *poli = malloc((grau+1)*sizeof(double));

//     for(int i=0; i<=grau; i++){
//         scanf("%lf", &poli[i]);
//     }

//     printf("Resultado: %lf\n", avalia(poli, grau, x));

//     free(poli);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

int buscaBinaria (int x, int n, int v[]) { 
    int e = -1, d = n; // atenção!

    while (e < d-1) {  
        int m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m; 
    }

    return d;
}

int main(){

    int n = 10000000;
    int chave;

    int *vet = malloc(sizeof(int)*n);

    srand(time(NULL));

    for(int i=0; i<n; i++){
        vet[i] = rand();

        if(i==n-1) chave = vet[i];
    }

    quick_sort(vet, 0, n - 1);

    time_t t1 = time(0);

    buscaBinaria(chave, n, vet);

    time_t t2 = time(0);

    printf("tempo: %ld\n", t2 - t1);

    free(vet);

    return 0;
}
#include "pilha_multipla.h"

TipoItem* inicItem (TipoItem elemento){

    TipoItem* item = malloc(sizeof(TipoItem));
    *(item) = elemento;

    return item;
}

TipoPilhaMultipla* inicPilhaMultipla(){
    TipoPilhaMultipla* p = malloc(sizeof(TipoPilhaMultipla));

    for(int i=0; i<N; i++){
        p->Pilha[i].Base = (i*tamanho_pilha) - 1;
        p->Pilha[i].Topo = p->Pilha[i].Base; 
    }

    return p;
}

void EmpilhaPilhaQualquer(TipoItem* x, TipoPilhaMultipla* Pilhas, int indice){
    (Pilhas->Pilha[indice].Topo)++;

    if(Pilhas->Pilha[indice].Topo > (tamanho_pilha*(indice+1)) - 1){
        printf("Erro: pilha esta cheia\n");
        (Pilhas->Pilha[indice].Topo)--;
    } else{
        Pilhas->Item[Pilhas->Pilha[indice].Topo] = x;
        printf("\n%d\n", *x);
    }
} 

TipoItem* DesempilhaPilhaQualquer(TipoPilhaMultipla* Pilhas, int indice){
    if(Pilhas->Pilha[indice].Base == Pilhas->Pilha[indice].Topo){
        printf("Pilha esta vazia\n");
        return NULL;
    } else{
        TipoItem* item = Pilhas->Item[Pilhas->Pilha[indice].Topo];
        (Pilhas->Pilha[indice].Topo)--;
    }
}

void imprimePilhas(TipoPilhaMultipla* Pilhas){

    for(int i=0; i<N; i++){
        printf("\nElementos da pilha %d: ", i);
        for(int j=(Pilhas->Pilha[i].Base)+1; j<=Pilhas->Pilha[i].Topo; j++){
            printf("%d ", *(Pilhas->Item[j]));
        }
        printf("\n");
    }
}
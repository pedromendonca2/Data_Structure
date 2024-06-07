#include "pilha_dupla.h"

TipoPilhaDupla* inicPilhaDupla(){
    TipoPilhaDupla* p = (TipoPilhaDupla*) malloc (sizeof (TipoPilhaDupla));

    p->Pilha1.Base = 0;
    p->Pilha1.Topo = -1; /* cresce para a direita */
    p->Pilha2.Base = MaxTam -1;
    p->Pilha2.Topo = MaxTam; /* cresce para a esquerda */

    return p;       
}

void EmpilhaPilha1 (TipoItem* x, TipoPilhaDupla* Pilhas) {
    
    (Pilhas->Pilha1.Topo)++;

    if (Pilhas->Pilha1.Topo >= (Pilhas->Pilha2.Topo)){
        printf ("Erro: pilha esta cheia\n");
        (Pilhas->Pilha1.Topo)--;
    } else {
        Pilhas->Item[Pilhas->Pilha1.Topo] = x;
    }
}

void EmpilhaPilha2 (TipoItem* x, TipoPilhaDupla* Pilhas) {

    (Pilhas->Pilha2.Topo)--;

    if (Pilhas->Pilha2.Topo <= (Pilhas->Pilha1.Topo)){
        printf ("Erro: pilha esta cheia\n");
        (Pilhas->Pilha2.Topo)++;
    } else{
        Pilhas->Item[Pilhas->Pilha2.Topo] = x;
    }
}

TipoItem* DesempilhaPilha1 (TipoPilhaDupla* Pilhas){

    if(Pilhas->Pilha1.Topo < Pilhas->Pilha1.Base){
        printf("Pilha esta vazia\n");
        return NULL;
    } else{
        TipoItem* item = Pilhas->Item[Pilhas->Pilha1.Topo];
        (Pilhas->Pilha1.Topo)--;
        return item;
    }
}

TipoItem* DesempilhaPilha2 (TipoPilhaDupla* Pilhas){

    if(Pilhas->Pilha2.Topo > Pilhas->Pilha2.Base){
        printf("Pilha esta vazia\n");
        return NULL;
    } else{
        TipoItem* item = Pilhas->Item[Pilhas->Pilha2.Topo];
        (Pilhas->Pilha2.Topo)++;
        return item;
    }
}

// void liberaPilhas(TipoPilhaDupla* Pilhas){
//     while(1){
//         TipoItem* item = DesempilhaPilha1(Pilhas);
//         if(item == NULL) break;
//     }
//      while(1){
//         TipoItem* item = DesempilhaPilha1(Pilhas);
//         if(item == NULL) break;
//     }
// }

TipoItem* inicItem (TipoItem elemento){

    TipoItem* item = malloc(sizeof(TipoItem));
    *(item) = elemento;

    return item;
}

void imprimePilhas(TipoPilhaDupla* Pilhas){

    printf("\nPilha 1:\n\n");

    for(int i=Pilhas->Pilha1.Base; i<=Pilhas->Pilha1.Topo; i++){
        printf("%d ", *(Pilhas->Item[i]));
    }
    printf("\n\n");

    printf("Pilha 2:\n\n");

    for(int i=(Pilhas->Pilha2.Base); i>=Pilhas->Pilha2.Topo; i--){
        printf("%d ", *(Pilhas->Item[i]));
    }
    printf("\n\n");
}


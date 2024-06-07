#include "sem_sentinela_dupla.h"

int main(){

    tProduto* p1 = criaProduto();
    tProduto* p2 = criaProduto();

    tTipoLista* lista = inicializaLista();

    lista = insereProduto(lista, p1);
    lista = insereProduto(lista, p2);

    //tCelula* c = lista;
    imprimeLista(lista);

    retira(lista, 10);

    //c = lista;
    imprimeLista(lista);

    destroiLista(lista);
    liberaProduto(p1);
    liberaProduto(p2);

    return 0;
}

#include "lista.h"

int main(){

    tTipoLista* lista = inicializaLista();

    tProduto* produto_1 = criaProduto();
    lista = insereProduto(lista, produto_1);
    tProduto* produto_2 = criaProduto();
    lista = insereProduto(lista, produto_2);

    imprimeLista(lista);

    lista = retira(lista, 5);

    imprimeLista(lista);

    destroiLista(lista);
    liberaProduto(produto_1);
    liberaProduto(produto_2);

    return 0;
}
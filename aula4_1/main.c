#include "lista.h"

int main(){

    tTipoLista* lista = inicializaLista();

    tProduto* produto_1 = criaProduto();
    insereCelulaNaLista(produto_1, lista);
    tProduto* produto_2 = criaProduto();
    insereCelulaNaLista(produto_2, lista);

    imprimeLista(lista);

    retiraItem(lista, 5);

    imprimeLista(lista);

    liberaLista(lista);

    return 0;
}
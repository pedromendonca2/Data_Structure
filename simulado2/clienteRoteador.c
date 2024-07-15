#include "tabelaRot.h"

int main(){

    tHash* tabela = inicTab(10);

    tRoteador* roteador_1 = inicRoteador(14);
    tRoteador* roteador_2 = inicRoteador(16);

    acessaTab(tabela, roteador_1);
    acessaTab(tabela, roteador_2);

    imprimeTab(tabela);
    liberaTab(tabela);

    return 0;
}
#include "pilha_dupla.h"

int main(){

    TipoPilhaDupla* Pilhas = inicPilhaDupla();

    TipoItem* a = inicItem(1);
    TipoItem* b = inicItem(2);
    TipoItem* c = inicItem(3);
    TipoItem* d = inicItem(4);
    TipoItem* e = inicItem(5);

    EmpilhaPilha1(a, Pilhas);
    EmpilhaPilha1(e, Pilhas);
    EmpilhaPilha1(d, Pilhas);

    EmpilhaPilha2(c, Pilhas);
    EmpilhaPilha2(b, Pilhas);

    imprimePilhas(Pilhas);

    DesempilhaPilha1(Pilhas);
    DesempilhaPilha2(Pilhas);

    imprimePilhas(Pilhas);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);

    free(Pilhas);

    return 0;
}
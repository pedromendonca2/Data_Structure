#include "pilha.h"

int main(){

    TipoPilhaMultipla* Pilhas = inicPilhaMultipla();

    TipoItem* a = inicItem(1);
    TipoItem* b = inicItem(2);
    TipoItem* c = inicItem(3);
    TipoItem* d = inicItem(4);
    TipoItem* e = inicItem(5);
    TipoItem* f = inicItem(6);

    EmpilhaPilhaQualquer(a, Pilhas, 1);
    EmpilhaPilhaQualquer(e, Pilhas, 1);
    EmpilhaPilhaQualquer(d, Pilhas, 1);

    EmpilhaPilhaQualquer(c, Pilhas, 4);
    EmpilhaPilhaQualquer(b, Pilhas, 4);

    imprimePilhas(Pilhas);

    DesempilhaPilhaQualquer(Pilhas, 1);
    DesempilhaPilhaQualquer(Pilhas, 4);

    imprimePilhas(Pilhas);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    free(Pilhas);

    return 0;
}
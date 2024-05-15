#include "pilha.h"

int main(){

    int a=1, b=2, c=3, d=4;

    TipoPilhaDupla* Pilhas = inicPilhaDupla();

    EmpilhaPilha1(a, Pilhas);

    EmpilhaPilha2(c, Pilhas);

    return 0;
}
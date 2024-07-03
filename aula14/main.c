#include "aluno.h"
#include "abbGenerica.h"

int main(){

    tAluno* aluno_1 = inicAluno("Pedro", 111);
    tAluno* aluno_2 = inicAluno("Henrique", 222);
    tAluno* aluno_3 = inicAluno("Mendonça", 333);

    tArvore* arvore = abb_cria();

    return 0;
}
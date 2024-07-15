#include "aluno.h"
#include "abbGenerica.h"
#include "arvAlunoGen.h"

int main(){

    tAluno* aluno_1 = inicAluno("Pedro", 111);
    tAluno* aluno_2 = inicAluno("Henrique", 222);
    tAluno* aluno_3 = inicAluno("Mendonça", 333);

    tArvore* a = abb_cria();

    a = insereArvoreAluno(a, aluno_1);
    a = insereArvoreAluno(a, aluno_2);
    a = insereArvoreAluno(a, aluno_3);

    imprimeArvoreAluno(a);
    printf("\n");

    a = retiraArvoreAluno(a, aluno_2);

    imprimeArvoreAluno(a);

    liberaArvoreAluno(a);

    // liberaAluno(aluno_1);
    // liberaAluno(aluno_2);
    // liberaAluno(aluno_3);

    return 0;
}
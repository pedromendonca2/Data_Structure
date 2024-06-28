#include "arvoreVariavel.h"

int main() {
    // Criação de nós
    tArvore* raiz = arvoreCria('A');
    tArvore* noB = arvoreCria('B');
    tArvore* noC = arvoreCria('C');
    tArvore* noD = arvoreCria('D');
    tArvore* noE = arvoreCria('E');
    tArvore* noF = arvoreCria('F');
    tArvore* noG = arvoreCria('G');
    tArvore* noH = arvoreCria('H');
    
    // Construção da árvore
    arvoreInsere(raiz, noB); // B é filho de A
    arvoreInsere(raiz, noC); // C é filho de A, e B se torna irmão de C
    arvoreInsere(noB, noD);  // D é filho de B
    arvoreInsere(noB, noE);  // E é filho de B, e D se torna irmão de E
    arvoreInsere(noC, noF);  // F é filho de C
    arvoreInsere(noF, noG);  // G é filho de F
    arvoreInsere(noB, noH);  // H é filho de B, e E se torna irmão de H

    // Impressão da árvore
    printf("Impressão da árvore:\n");
    arvoreImprime(raiz);
    printf("\n");

    // Verificação de pertencimento
    printf("Verificação de pertencimento:\n");
    printf("A pertence à árvore? %s\n", arvorePertence(raiz, 'A') ? "Sim" : "Não");
    printf("B pertence à árvore? %s\n", arvorePertence(raiz, 'B') ? "Sim" : "Não");
    printf("C pertence à árvore? %s\n", arvorePertence(raiz, 'C') ? "Sim" : "Não");
    printf("D pertence à árvore? %s\n", arvorePertence(raiz, 'D') ? "Sim" : "Não");
    printf("E pertence à árvore? %s\n", arvorePertence(raiz, 'E') ? "Sim" : "Não");
    printf("F pertence à árvore? %s\n", arvorePertence(raiz, 'Z') ? "Sim" : "Não");
    printf("G pertence à árvore? %s\n", arvorePertence(raiz, 'P') ? "Sim" : "Não");

    printf("\nAltura da árvore: %d", arvoreAltura(raiz));
    printf("\nNúmero de folhas da árvore: %d", numFolhas(raiz));
    printf("\nNúmero de nós com um filho: %d\n", numNosComUmFilho(raiz));

    // Liberação da memória
    arvoreLibera(raiz);

    return 0;
}
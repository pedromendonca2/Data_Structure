#include "hash.h"
#include "palavra.h"

#define NTAB 100
#define NPAL 100

int main() {
    FILE *file_pointer = fopen("./texto.txt", "r");
    if (file_pointer == NULL) {
        printf("Arquivo nao foi aberto corretamente\n");
        exit(1);
    }

    char n[NPAL];
    Hash* tab = cria(NTAB, retornaSize());

    while (fscanf(file_pointer, "%s", n) == 1) {
        tPalavra* pTemp = inicPalavra(n);
        tPalavra* p = busca(tab, &pTemp, hashPalavra, comparaPalavra);
        if (p == NULL) {
            tPalavra* novaPalavra = inicPalavra(n);
            p = hash_insere(tab, novaPalavra, novaPalavra, hashPalavra, comparaPalavra);
        }
        atualizaOcorrencias(p);
    }

    printf("Conta palavras: %d\n\n", contaPalavras(tab));

    imprimeHash(tab, stdout);
    libera(tab);

    fclose(file_pointer);

    return 0;
}

#include "palavra.h"

struct palavra {
    char* pal;
    int n;
};

tPalavra* inicPalavra(char* p) {
    tPalavra* pal = (tPalavra*)malloc(sizeof(tPalavra));
    pal->pal = strdup(p);
    pal->n = 1;
    return pal;
}

tPalavra* retornaPalavra(void* p){
    return (tPalavra*)p;
}

unsigned int retornaSize() {
    return sizeof(tPalavra);
}

char* retornaString(tPalavra* pal) {
    return pal->pal;
}

void atualizaOcorrencias(tPalavra* pal) {
    pal->n++;
}

int retornaOcorrencias(tPalavra* pal) {
    return pal->n;
}

int comparaPalavra(void* pal_1, void* pal_2) {
    return strcmp(((tPalavra*)pal_1)->pal, ((tPalavra*)pal_2)->pal);
}

int hashPalavra(void* pal, int tam) {
    char* s = ((tPalavra*)pal)->pal;
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) total += s[i];
    return total % tam;
}

void imprimePalavra(tPalavra* pal, FILE* file) {
    fprintf(file, "String: %s - Ocorrencia: %d\n", pal->pal, pal->n);
}

void liberaPalavra(tPalavra* pal) {
    free(pal->pal);
    free(pal);
}

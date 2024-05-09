#include "produto.h"

struct produto{
    int codigo;
    char* nome;
    int preco;
};

tProduto* criaProduto(){

    tProduto* p = calloc(1, sizeof(tProduto));

    char nome[100];
    printf("Digite nome do produto\n");
    scanf(" %[^\n]%*c", nome);
    p->nome =  malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(p->nome, nome);

    printf("Digite codigo e preco do produto\n");
    scanf("%d %d", &p->codigo, &p->preco);

    return p;
}

char* retornaNome(tProduto* p){
    return p->nome;
}

int retornaCodigo(tProduto* p){
    return p->codigo;
}

int retornaPreco(tProduto* p){
    return p->preco;
}

void liberaProduto(tProduto* p){
    free(p->nome);
    free(p);
}
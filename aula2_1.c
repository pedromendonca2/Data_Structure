#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* nome;
    int valor;
} tProduto;

typedef struct{
    int qtd;
    tProduto tipo;
} tItem;

typedef struct{
    int valor;
    tItem* itens;
} tEstoque;

typedef struct{
    char* nome;
    tEstoque estoque;
} tFilial;

typedef struct{
    char* nome;
    tFilial* filiais;
    int valor_total;
} tSupermercado;

int calculaEstoqueAux(tEstoque estoque){
    return estoque.valor;
}

int calculaEstoque(tFilial filial){
    return calculaEstoqueAux(filial.estoque);
}

int calculaQtd(tItem item){
    return item.qtd;
}

int calculaValorAux(tProduto produto){
    return produto.valor;
}

int calculaValor(tItem item){
    return calculaValorAux(item.tipo);
}

tItem cadastrarItem(tProduto* produtos, int num_produtos){
    tItem item;
    char nome[100];

    printf("Digite quantidade e produto:\n");
    scanf("%d", item.qtd);

    scanf(" %[^\n]%*c", nome);
    for(int i=0; i<num_produtos; i++){
        if(strcmp(nome, produtos[i].nome) == 0){
            item.tipo = produtos[i];
        }
    }

    return item;
}

tEstoque cadastrarEstoque(tProduto* produtos, int num_produtos){
    tEstoque estoque;
    int qtd_items;

    scanf("%d", qtd_items);

    estoque.itens = malloc(qtd_items*sizeof(tItem));

    for(int i=0; i<qtd_items; i++){
        estoque.itens[i] = cadastrarItem(produtos, num_produtos);
    }

    for(int i=0; i<qtd_items; i++){
        estoque.valor += calculaQtd(estoque.itens[i])*calculaValor(estoque.itens[i]);
    }
    
    return estoque;
}

tFilial cadastrarFilial(tProduto* produtos, int num_produtos){
    tFilial filial;

    char nome[100];

    scanf(" %[^\n]%*c", nome);
    filial.nome = malloc(strlen(nome)+1);
    strcpy(filial.nome, nome);

    filial.estoque = cadastrarEstoque(produtos, num_produtos);

    return filial;
}

tProduto* cadastrarProdutos(int num_produtos){
    char nome[100];

    tProduto* produtos = malloc(num_produtos*sizeof(tProduto));

    for(int i=0; i<num_produtos; i++){
        scanf(" %[^\n]%*c", nome);
        produtos[i].nome = malloc(strlen(nome)+1);
        strcpy(produtos[i].nome, nome);
        scanf("%d", &produtos[i].valor);
    }

    return produtos;
}

void desalocaProdutos(tProduto* produtos, int num_produtos){
    for(int i=0; i<num_produtos; i++){
        free(produtos[i].nome);    
    }
    free(produtos);
}

int main(){

    int num_produtos, num_filiais;

    printf("Digite o num de produtos:\n");
    scanf("%d", &num_produtos);
    printf("Digite o nome e o valor de cada produto\n");
    tProduto* produtos = cadastrarProdutos(num_produtos);

    tSupermercado supermercado;
    scanf(" %[^\n]%*c", supermercado.nome);

    scanf("%d", num_filiais);
    supermercado.filiais = malloc(num_filiais*sizeof(tFilial));
    for(int i=0; i<num_filiais; i++){
        supermercado.filiais[i] = cadastrarFilial(produtos, num_produtos);
    }

    for(int i=0; i<num_filiais; i++){
        supermercado.valor_total += calculaEstoque(supermercado.filiais[i]);
    }

    desalocaProdutos(produtos, num_produtos);

    return 0;
}
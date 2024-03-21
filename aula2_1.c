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
    int qtd_itens;
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
    scanf("%d", &item.qtd);

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

    printf("Digite a quantidade de itens:\n");
    scanf("%d", &estoque.qtd_itens);

    estoque.itens = malloc(estoque.qtd_itens*sizeof(tItem));

    for(int i=0; i<estoque.qtd_itens; i++){
        estoque.itens[i] = cadastrarItem(produtos, num_produtos);
    }

    estoque.valor = 0;
    for(int i=0; i<estoque.qtd_itens; i++){
        estoque.valor += calculaQtd(estoque.itens[i])*calculaValor(estoque.itens[i]);
    }
    
    return estoque;
}

tFilial cadastrarFilial(tProduto* produtos, int num_produtos){
    tFilial filial;
    char nome[100];

    printf("Digite o nome da filial:\n");
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

void desalocaEstoque(tEstoque estoque){
    // for(int i=0; i<estoque.qtd_itens; i++){
    //     desalocaItem(estoque.itens[i]);
    // }
    free(estoque.itens);
}

void desalocaFilial(tFilial filial){
    free(filial.nome);
    desalocaEstoque(filial.estoque);
}

void desalocaSupermercado(tSupermercado supermercado, int num_filiais){
    free(supermercado.nome);
    for(int i=0; i<num_filiais; i++){
        desalocaFilial(supermercado.filiais[i]);
    }
    free(supermercado.filiais);
}

void desalocaProdutos(tProduto* produtos, int num_produtos){
    for(int i=0; i<num_produtos; i++){
        free(produtos[i].nome);    
    }
    free(produtos);
}

int main(){
    int num_produtos, num_filiais;
    char nome[100];

    printf("Digite o num de produtos:\n");
    scanf("%d", &num_produtos);
    printf("Digite o nome e o valor de cada produto\n");
    tProduto* produtos = cadastrarProdutos(num_produtos);

    tSupermercado supermercado;

    printf("Digite o nome do supermercado:\n");
    scanf(" %[^\n]%*c", nome);
    supermercado.nome = malloc(strlen(nome)+1);
    strcpy(supermercado.nome, nome);
    //printf("O nome do mercado foi registrado\n");

    printf("Digite o numero de filiais:\n");
    scanf("%d", &num_filiais);
    supermercado.filiais = malloc(num_filiais*sizeof(tFilial));
    for(int i=0; i<num_filiais; i++){
        supermercado.filiais[i] = cadastrarFilial(produtos, num_produtos);
    }

    supermercado.valor_total = 0;
    for(int i=0; i<num_filiais; i++){
        supermercado.valor_total += calculaEstoque(supermercado.filiais[i]);
    }

    printf("Nome: %s, Estoque Total: %d\n", supermercado.nome, supermercado.valor_total);
    for(int i=0; i<num_filiais; i++){
        printf("Filial: %s\nEstoque: %d\n  ", supermercado.filiais[i].nome, calculaEstoque(supermercado.filiais[i]));
        for(int j=0; j<supermercado.filiais[i].estoque.qtd_itens; j++){
            printf("Item: %s, valor unitario: %d, quantidade: %d\n  ", supermercado.filiais[i].estoque.itens[j].tipo.nome, supermercado.filiais[i].estoque.itens[j].tipo.valor, supermercado.filiais[i].estoque.itens[j].qtd);
        }
    }

    desalocaProdutos(produtos, num_produtos);
    desalocaSupermercado(supermercado, num_filiais);

    return 0;
}
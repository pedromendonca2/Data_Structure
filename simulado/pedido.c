#include "pedido.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    TProduto* produto;
    tCelula* prox;
} tCelula;

struct pedido{
    char* nome_dono;
    tCelula* primeiro;
    tCelula* ultimo;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono){

    if(dono == NULL) exit(1);

    TPedido* pedido = malloc(sizeof(pedido));

    pedido->nome_dono = strdup(dono);
    pedido->primeiro = NULL;
    pedido->ultimo = NULL;

    return pedido;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod){
    if(pedido == NULL || prod == NULL) exit(1);

    tCelula* ant = NULL;
    tCelula* p = pedido->primeiro;

    while(p != NULL || (p->produto != prod)){
        ant = p;
        p = p->prox;
    }

    if(p->produto == prod){
        printf("Produto já existe no pedido\n");
        return;
    }

    tCelula* novo = malloc(sizeof(tCelula));

    if(pedido->ultimo == NULL){
        pedido->primeiro = pedido->ultimo = novo;
    } else{
        pedido->ultimo->prox = novo;
        pedido->ultimo = pedido->ultimo->prox;
    }

    pedido->ultimo->produto = prod;
    pedido->ultimo->prox = NULL;
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido){

    if(pedido == NULL) return;

    printf("Dono: %s\n\n", pedido->nome_dono);
    
    tCelula* cel = pedido->primeiro;

    if(cel == pedido->primeiro && cel == pedido->ultimo){
        printf("Nao ha produtos neste pedido!\n");
        return;
    }

    while(cel != NULL){
        printf("Nome: %s\n", RetornaNome(cel->produto));
        imprimeIngredientes(cel->produto);
        printf("\n");
        cel = cel->prox;
    }

}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod){
    if(pedido == NULL || prod == NULL) exit(1);

    tCelula* ant = NULL;
    tCelula* p = pedido->primeiro;

    while(p != NULL || (p->produto != prod)){
        ant = p;
        p = p->prox;
    }

    if(p = NULL) return;

    if(p == pedido->primeiro && p == pedido->ultimo){
        pedido->primeiro = pedido->ultimo = NULL;
        return;
    }

    if(p == pedido->ultimo){
        pedido->ultimo = ant;
        ant = NULL;
        return;
    }

    if(p == pedido->primeiro){
        pedido->primeiro = p->prox;
    } else{
        ant->prox = p->prox;
    }
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: Pedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    if(pedido == NULL || restricao_alimentar == NULL) exit(1);

    int soma_calorias = 0, flag = 0;

    tCelula* cel = pedido->primeiro;

    while(cel != NULL){
        soma_calorias += Calorias(cel->produto);
        cel = cel->prox;
    }

    if(soma_calorias > restricao_calorica){
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!");
        flag = 1;
    }

    tCelula* cel = pedido->primeiro;

    while(cel != NULL){
        if(strcmp(restricao_alimentar, RetornaNome(cel->produto)) == 0){
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(cel->produto));
            flag = 1;
        }
        cel = cel->prox;
    }
}
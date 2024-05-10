#include "posto.h"
#include "fila.h"
#include "amostra.h"

struct posto{
    char* nome;
    tFila* exNaoProcessados;
    tFila* exPositivos;
    tFila* exNegativos;
};

Posto* inicPosto(char* nome){
    Posto* p = malloc(sizeof(Posto));

    p->nome = strdup(nome);

    p->exNaoProcessados = fila_cria();
    p->exNegativos = fila_cria();
    p->exPositivos = fila_cria();

    return p;
}

void imprimePosto(Posto* posto){
    printf("Dados do Posto: %s\n", posto->nome);

    printf("Amostras não processadas\n");
    imprime_fila(posto->exNaoProcessados);

    printf("Amostras com resultados positivos\n");
    imprime_fila(posto->exPositivos);

    printf("Amostras com resultados negativos\n");
    imprime_fila(posto->exNegativos);
}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
* inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
* output: nenhum
* pre-condicao: posto válido, nome da pessoa válido
* pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto* posto, char* pessoa, int idade){

    if(posto == NULL || pessoa == NULL){
        printf("Deu ruim\n");
        exit(1);
    } 
    
    Amostra* a = inicAmostra(pessoa, idade);

    if(idade >= 60){
        fila_insere_inicio(posto->exNaoProcessados, a);
    } else{
        fila_insere_final(posto->exNaoProcessados, a);
    }

}


/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; 
fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto* posto){
    if(posto == NULL){
        printf("Deu ruim\n");
        exit(1);
    }

    tCelula* c = retorna_prim(posto->exNaoProcessados);

    while(c != NULL){
        if(retornaCargaViral(retorna_amostra(c)) >= LIMITE_CARGA_VIRAL){
            registraResultado(retorna_amostra(c), 1);
            c = retorna_prox(c);
            fila_insere_final(posto->exPositivos, fila_retira(posto->exNaoProcessados));
        } else{
            c = retorna_prox(c);
            fila_insere_final(posto->exNegativos, fila_retira(posto->exNaoProcessados));
        }
    }
}

/* Libera toda a memória alocada para o posto de saúde
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: Memória para a string nome liberada; memória para as 3 filas liberada, memoria do posto liberada
 */
void liberaPosto(Posto* posto){
    if(posto != NULL){
        free(posto->nome);
        fila_libera(posto->exNaoProcessados);
        fila_libera(posto->exNegativos);
        fila_libera(posto->exPositivos);
        free(posto);
    }
}
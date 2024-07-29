#include "arv_exp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tipo que define a arvore(tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. */
struct arv{
  Arv* esq;
  Arv* dir;
  char operador;
  int operando;
};

/*Cria uma arvore vazia, ou seja, retorna NULL
* inputs: nenhum
* output: NULL
*/
Arv* CriaVazia(void){
  return NULL;
}

/*cria um nó raiz de operador dados o operador e as duas sub-árvores, a da esquerda e a da direita
* inputs: o operador, as sub-arvores da esquerda e da direita
* output: o endereço do nó raiz criado
*/
Arv* CriaOperador(char c, Arv* esq, Arv* dir){
  Arv* arv = malloc(sizeof(Arv));

  arv->dir = dir;
  arv->esq = esq;
  arv->operador = c;
  arv->operando = 0;

  return arv;
}

/*cria um nó operando dado o valor do no (como o operando é um nó folha, as sub-arvores da esquerda e da direita são nulas
* inputs: o operando
* output: o endereço do nó raiz criado
*/
Arv* CriaOperando(int valor){
  Arv* arv = malloc(sizeof(Arv));

  arv->dir = NULL;
  arv->esq = NULL;
  arv->operador = ' ';
  arv->operando = valor;

  return arv;
}

/*Imprime a árvore em notação InOrder (esq, raiz, direita)
* inputs: o endereço da raiz da árvore
* output: nenhum
*/
void Imprime(Arv* arv){

  if(arv != NULL){
    Imprime(arv->esq);
    if(arv->operador == ' '){
      printf("%d ", arv->operando);
    } else{
      printf("%c ", arv->operador);
    } 
    Imprime(arv->dir);
  }
}

/* Libera memória alocada pela estrutura da árvore
as sub-árvores devem ser liberadas antes de se liberar o nó raiz
* inputs: o endereço da raiz da árvore
* output: uma árvore vazia, representada por NULL
*/
Arv* Libera (Arv* arv){
  if(arv != NULL){
    arv->esq = Libera(arv->esq);
    arv->dir = Libera(arv->dir);
    free(arv);
  }
  return NULL;
}


/* Retorna o valor correspondente à avaliação da expressão representada na árvore
* inputs: o endereço da raiz da árvore
* output: o valor da expressão
*/
float Avalia(Arv* arv) {
  if (arv == NULL) {
    return 0;
  }
  if (arv->operador == ' ') {
    return arv->operando;
  }

  float valEsq = Avalia(arv->esq);
  float valDir = Avalia(arv->dir);

  switch (arv->operador) {
    case '+': return valEsq + valDir;
    case '-': return valEsq - valDir;
    case '*': return valEsq * valDir;
    case '/': return valEsq / valDir;
    default: return 0;
  }
}


/* Retorna o número de folhas da árvore
* inputs: o endereço da raiz da árvore
* output: o número de folhas
*/
int Folhas(Arv* arv){
  if (arv == NULL) {
    return 0;
  } else if (arv->esq == NULL && arv->dir == NULL) {
    return 1;
  }

  return Folhas(arv->esq) + Folhas(arv->dir);
}

/* Retorna a altura da árvore
* inputs: o endereço da raiz da árvore
* output: a altura da árvore
*/
int Altura(Arv* arv){
  if(arv == NULL){
    return 0;
  } 

  int altEsq = Altura(arv->esq);
  int altDir = Altura(arv->dir);

  if (altEsq > altDir) {
    return 1 + altEsq;
  } else {
    return 1 + altDir;
  }
}
#include "hash.h"

struct hash{
    tAluno** aluno;
    int tamanho;
};

int functionHash(char* s, int tam){
    int tam_nome = 0;

    for(int i=0; s[i] != '\0'; i++) tam_nome += s[i];

    return tam_nome % tam;
}

tHash* inicializaHash(int tam){
    tHash* hash = malloc(sizeof(tHash));

    hash->tamanho = tam;
    hash->aluno = malloc(tam*sizeof(tAluno*));

    for(int i=0; i<tam; i++){
        hash->aluno[i] = NULL;
    }

    return hash;
}

tAluno* acessaHash(tHash* hash, char* s, char p){
    int indice = functionHash(s, hash->tamanho);

    tAluno* a = buscaAlunoLista(hash->aluno[indice], s);

    // Procura na lista encadeada
    if(a){
        incrementaAluno(a, p);
        return a;
    }

    // Cria um novo aluno e insere na lista encadeada
    a = criaAluno(s);
    hash->aluno[indice] = insereAlunoLista(hash->aluno[indice], a);

    return a;
}

void imprimeHash(tHash* hash, FILE* file){
    if(hash != NULL){
        for(int i=0; i<hash->tamanho; i++){
            imprimeAlunos(hash->aluno[i], file);
        }
    }
}

void liberaHash(tHash* hash){
    if(hash != NULL){
        for(int i=0; i<hash->tamanho; i++){
            liberaAluno(hash->aluno[i]);
        }
        free(hash->aluno);
        free(hash);
    }
}
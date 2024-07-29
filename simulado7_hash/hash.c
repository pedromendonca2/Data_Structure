#include "hash.h"

typedef struct node {
    void* data;
    struct node* prox;
} Node;

struct hash {
    Node** vet;
    int tam;
    size_t tam_item;
};

Hash* cria(int tam, size_t tam_item) {
    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->tam = tam;
    h->tam_item = tam_item;
    h->vet = (Node**)malloc(tam * sizeof(Node*));
    for (int i = 0; i < tam; i++) {
        h->vet[i] = NULL;
    }
    return h;
}

static Node* cria_no(void* data, size_t tam_item) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = malloc(tam_item);
    memcpy(novo->data, data, tam_item);
    novo->prox = NULL;
    return novo;
}

void* busca(Hash* hash, void* key, int (*fhash)(void*, int), int (*comp)(void*, void*)) {
    int indice = fhash(key, hash->tam);
    Node* atual = hash->vet[indice];
    while (atual) {
        if (comp(atual->data, key) == 0) {
            return atual->data;
        }
        atual = atual->prox;
    }
    return NULL;
}

void* hash_insere(Hash* thash, void* key, void* objeto, int (*fhash)(void*, int), int (*comp)(void*, void*)) {
    int indice = fhash(key, thash->tam);
    Node* atual = thash->vet[indice];
    while (atual) {
        if (comp(atual->data, key) == 0) {
            memcpy(atual->data, objeto, thash->tam_item);
            return atual->data;
        }
        atual = atual->prox;
    }
    Node* novo = cria_no(objeto, thash->tam_item);
    novo->prox = thash->vet[indice];
    thash->vet[indice] = novo;
    return novo->data;
}

int contaPalavras(Hash* table) {
    int total = 0;
    for (int i = 0; i < table->tam; i++) {
        Node* atual = table->vet[i];
        while (atual) {
            total++;
            atual = atual->prox;
        }
    }
    return total;
}

void imprimeHash(Hash* table, FILE* file) {
    for (int i = 0; i < table->tam; i++) {
        Node* atual = table->vet[i];
        while (atual) {
            imprimePalavra(retornaPalavra(atual->data), file);
            atual = atual->prox;
        }
    }
}

void libera(Hash* table) {
    for (int i = 0; i < table->tam; i++) {
        Node* atual = table->vet[i];
        while (atual) {
            Node* temp = atual->prox;
            free(atual->data);
            free(atual);
            atual = temp;
        }
    }
    free(table->vet);
    free(table);
}

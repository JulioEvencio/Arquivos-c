#include <stdlib.h>
#include "pilha.h"

typedef struct Nodo Nodo;
struct Nodo {
    Elemento elemento;
    Nodo *proximo;
};

struct Pilha {
    int tamanho;
    Nodo *inicio;
};

int pilha_criar(Pilha **pilha) {
    *pilha = malloc(sizeof **pilha);

    if (*pilha == NULL) return PILHA_SEM_MEMORIA;

    (*pilha)->tamanho = 0;
    (*pilha)->inicio = NULL;

    return PILHA_SUCESSO;
}

void pilha_liberar(Pilha **pilha) {
    while ((*pilha)->inicio != NULL) {
        Nodo *nodo = (*pilha)->inicio;
        (*pilha)->inicio = (*pilha)->inicio->proximo;
        free(nodo);
    }

    free(*pilha);
}

int pilha_tamanho(Pilha **pilha) {
    return (*pilha)->tamanho;
}

int pilha_vazia(Pilha **pilha) {
    return (*pilha)->inicio == NULL;
}

int pilha_empilhar(Pilha **pilha, Elemento *elemento) {
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return PILHA_SEM_MEMORIA;

    nodo->elemento = *elemento;
    nodo->proximo = (*pilha)->inicio;
    (*pilha)->inicio = nodo;
    (*pilha)->tamanho++;

    return PILHA_SUCESSO;
}

int pilha_desempilhar(Pilha **pilha, Elemento *elemento) {
    if (pilha_vazia(pilha)) return PILHA_VAZIA;

    Nodo *nodo = (*pilha)->inicio;

    (*pilha)->inicio = (*pilha)->inicio->proximo;
    (*pilha)->tamanho--;

    if (elemento != NULL) *elemento = nodo->elemento;

    free(nodo);

    return PILHA_SUCESSO;
}

int pilha_obter(Pilha **pilha, Elemento *elemento) {
    if (pilha_vazia(pilha)) return PILHA_VAZIA;

    *elemento = (*pilha)->inicio->elemento;

    return PILHA_SUCESSO;
}

int pilha_alterar(Pilha **pilha, Elemento *elemento) {
    if (pilha_vazia(pilha)) return PILHA_VAZIA;

    (*pilha)->inicio->elemento = *elemento;

    return PILHA_SUCESSO;
}

void pilha_formatar(Pilha **pilha) {
    (*pilha)->tamanho = 0;

    while ((*pilha)->inicio != NULL) {
        Nodo *nodo = (*pilha)->inicio;
        (*pilha)->inicio = (*pilha)->inicio->proximo;
        free(nodo);
    }
}
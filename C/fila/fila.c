#include <stdlib.h>
#include "fila.h"

typedef struct Nodo Nodo;
struct Nodo {
    Elemento elemento;
    Nodo *proximo;
};

struct Fila {
    int tamanho;
    Nodo *inicio;
    Nodo *fim;
};

int fila_criar(Fila **fila) {
    *fila = malloc(sizeof **fila);

    if (*fila == NULL) return FILA_SEM_MEMORIA;

    (*fila)->tamanho = 0;
    (*fila)->inicio = NULL;
    (*fila)->fim = NULL;

    return FILA_SUCESSO;
}

void fila_liberar(Fila **fila) {
    while ((*fila)->inicio != NULL) {
        Nodo *nodo = (*fila)->inicio;
        (*fila)->inicio = (*fila)->inicio->proximo;
        free(nodo);
    }

    free(*fila);
}

int fila_tamanho(Fila **fila) {
    return (*fila)->tamanho;
}

int fila_vazia(Fila **fila) {
    return (*fila)->inicio == NULL;
}

int fila_adicionar(Fila **fila, Elemento *elemento) {
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return FILA_SEM_MEMORIA;

    nodo->elemento = *elemento;
    nodo->proximo = NULL;

    if (fila_vazia(fila)) (*fila)->inicio = nodo;
    else (*fila)->fim->proximo = nodo;

    (*fila)->fim = nodo;
    (*fila)->tamanho++;

    return FILA_SUCESSO;
}

int fila_remover(Fila **fila, Elemento *elemento) {
    if (fila_vazia(fila)) return FILA_VAZIA;

    Nodo *nodo = (*fila)->inicio;

    (*fila)->inicio = (*fila)->inicio->proximo;
    (*fila)->tamanho--;

    if (elemento != NULL) *elemento = nodo->elemento;

    free(nodo);

    if (fila_vazia(fila)) (*fila)->fim = NULL;

    return FILA_SUCESSO;
}

int fila_obter(Fila **fila, Elemento *elemento) {
    if (fila_vazia(fila)) return FILA_VAZIA;

    *elemento = (*fila)->inicio->elemento;

    return FILA_SUCESSO;
}

int fila_alterar(Fila **fila, Elemento *elemento) {
    if (fila_vazia(fila)) return FILA_VAZIA;

    (*fila)->inicio->elemento = *elemento;

    return FILA_SUCESSO;
}

void fila_formatar(Fila **fila) {
    (*fila)->tamanho = 0;
    (*fila)->fim = NULL;

    while ((*fila)->inicio != NULL) {
        Nodo *nodo = (*fila)->inicio;
        (*fila)->inicio = (*fila)->inicio->proximo;
        free(nodo);
    }
}
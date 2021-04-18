#include <stdlib.h>
#include "fila.h"

#define FILA_INICIO 1

struct Fila {
    int tamanho;
    int tamanho_max;
    int inicio;
    int fim;
    Elemento *elemento;
};

int fila_inicializar(Fila **fila, int tamanho) {
    if (tamanho < FILA_INICIO) return FILA_TAMANHO_INVALIDO;
    
    *fila = malloc(sizeof **fila);

    if (*fila == NULL) return FILA_SEM_MEMORIA;

    (*fila)->elemento = malloc(sizeof((*fila)->elemento) * tamanho);

    if ((*fila)->elemento == NULL) {
        free(*fila);
        return FILA_SEM_MEMORIA;
    }

    (*fila)->tamanho = 0;
    (*fila)->inicio = 0;
    (*fila)->fim = 0;
    (*fila)->tamanho_max = tamanho;

    return FILA_SUCESSO;
}

void fila_liberar(Fila **fila) {
    free((*fila)->elemento);
    free(*fila);
}

int fila_tamanho(Fila **fila) {
    return (*fila)->tamanho;
}

int fila_vazia(Fila **fila) {
    return (*fila)->tamanho == 0;
}

int fila_cheia(Fila **fila) {
    return (*fila)->tamanho == (*fila)->tamanho_max;
}

int fila_adicionar(Fila **fila, Elemento *elemento) {
    if (fila_cheia(fila)) return FILA_CHEIA;

    (*fila)->elemento[(*fila)->fim] = *elemento;
    (*fila)->fim = ((*fila)->fim + 1) % (*fila)->tamanho_max;
    (*fila)->tamanho++;

    return FILA_SUCESSO;
}

int fila_remover(Fila **fila) {
    if (fila_vazia(fila)) return FILA_VAZIA;

    (*fila)->inicio = ((*fila)->inicio + 1) % (*fila)->tamanho_max;
    (*fila)->tamanho--;

    return FILA_SUCESSO;
}

int fila_alterar(Fila **fila, Elemento *elemento) {
    if (fila_vazia(fila)) return FILA_VAZIA;

    (*fila)->elemento[(*fila)->inicio] = *elemento;

    return FILA_SUCESSO;
}

int fila_obter(Fila **fila, Elemento *elemento) {
    if (fila_vazia(fila)) return FILA_VAZIA;

    *elemento = (*fila)->elemento[(*fila)->inicio];

    return FILA_SUCESSO;
}
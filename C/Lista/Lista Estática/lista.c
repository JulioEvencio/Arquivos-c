#include <stdlib.h>
#include "lista.h"

#define LISTA_INICIO 1

struct Lista
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};

int lista_inicializar(Lista **lista, int tamanho) {
    *lista = malloc(sizeof **lista);

    if (*lista == NULL) return LISTA_SEM_MEMORIA;

    (*lista)->elemento = malloc(sizeof((*lista)->elemento) * tamanho);

    if ((*lista)->elemento == NULL) {
        free(*lista);
        return LISTA_SEM_MEMORIA;
    }

    (*lista)->tamanho = 0;
    (*lista)->tamanho_max = tamanho;

    return LISTA_SUCESSO;
}

void lista_liberar(Lista **lista) {
    free((*lista)->elemento);
    free(*lista);
}
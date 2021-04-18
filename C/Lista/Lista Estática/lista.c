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
    if (tamanho < LISTA_INICIO) return LISTA_TAMANHO_INVALIDO;
    
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

int lista_obter_tamanho(Lista **lista) {
    return (*lista)->tamanho;
}

int lista_esta_vazia(Lista **lista) {
    return (*lista)->tamanho == 0;
}

int lista_esta_cheia(Lista **lista) {
    return (*lista)->tamanho == (*lista)->tamanho_max;
}

int lista_adicionar_elemento_inicio(Lista **lista, Elemento *elemento) {
    if (lista_esta_cheia(lista)) return LISTA_CHEIA;

    for (int i = (*lista)->tamanho; i >= LISTA_INICIO; i--) {
        (*lista)->elemento[i] = (*lista)->elemento[i - 1];
    }

    (*lista)->elemento[0] = *elemento;
    (*lista)->tamanho++;

    return LISTA_SUCESSO;
}

int lista_adicionar_elemento_posicao(Lista **lista, Elemento *elemento, int posicao) {
    if (lista_esta_cheia(lista)) return LISTA_CHEIA;

    if (posicao < LISTA_INICIO || posicao > (*lista)->tamanho) return LISTA_POSICAO_INEXISTENTE;

    for (int i = (*lista)->tamanho; i > (posicao - 1); i--) {
        (*lista)->elemento[i] = (*lista)->elemento[i - 1];
    }

    (*lista)->elemento[posicao - 1] = *elemento;
    (*lista)->tamanho++;

    return LISTA_SUCESSO;
}

int lista_adicionar_elemento_final(Lista **lista, Elemento *elemento) {
    if (lista_esta_cheia(lista)) return LISTA_CHEIA;

    (*lista)->elemento[(*lista)->tamanho] = *elemento;
    (*lista)->tamanho++;

    return LISTA_SUCESSO;
}
#include <stdlib.h>
#include "lista.h"

typedef struct Nodo Nodo;
struct Nodo {
    int chave;
    Elemento elemento;
    Nodo *proximo;
};

struct Lista {
    int tamanho;
    Nodo *inicio;
    Nodo *controle;
};

int lista_criar(Lista **lista) {
    *lista = malloc(sizeof **lista);

    if (*lista == NULL) return LISTA_SEM_MEMORIA;

    (*lista)->tamanho = 0;
    (*lista)->inicio = NULL;
    (*lista)->controle = NULL;

    return LISTA_SUCESSO;
}

void lista_liberar(Lista **lista) {
    while ((*lista)->inicio != NULL) {
        Nodo *nodo = (*lista)->inicio;
        (*lista)->inicio = (*lista)->inicio->proximo;
        free(nodo);
    }

    free(*lista);
}

int lista_tamanho(Lista **lista) {
    return (*lista)->tamanho;
}

int lista_vazia(Lista **lista) {
    return (*lista)->inicio == NULL;
}

int lista_contem(Lista **lista, int chave) {
    Nodo *nodo = (*lista)->inicio;

    while (nodo != NULL) {
        if (nodo->chave == chave) return 1;

        nodo = nodo->proximo;
    }

    return 0;
}

int lista_adicionar(Lista **lista, int chave, Elemento *elemento) {
    if (lista_contem(lista, chave)) return LISTA_CHAVE_INVALIDA;

    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return LISTA_SEM_MEMORIA;

    nodo->chave = chave;
    nodo->elemento = *elemento;
    nodo->proximo = (*lista)->inicio;

    (*lista)->inicio = nodo;
    (*lista)->tamanho++;
    (*lista)->controle = (*lista)->inicio;

    return LISTA_SUCESSO;
}

int lista_remover(Lista **lista, int chave, Elemento *elemento) {
    if (lista_vazia(lista)) return LISTA_VAZIA;

    Nodo *nodo = (*lista)->inicio;

    if ((*lista)->inicio->chave == chave) {
        if (elemento != NULL) *elemento = nodo->elemento;

        (*lista)->inicio = (*lista)->inicio->proximo;
        (*lista)->tamanho--;
        (*lista)->controle = (*lista)->inicio;

        free(nodo);

        return LISTA_SUCESSO;
    } else {
        Nodo *nodo_anterior;

        while (nodo != NULL) {
            if (nodo->chave == chave) {
                if (elemento != NULL) *elemento = nodo->elemento;

                nodo_anterior->proximo = nodo->proximo;
                (*lista)->tamanho--;

                free(nodo);

                return LISTA_SUCESSO;
            }

            nodo_anterior = nodo;
            nodo = nodo->proximo;
        }
    }

    return LISTA_CHAVE_INVALIDA;
}

int lista_obter(Lista **lista, int chave, Elemento *elemento) {
    if (lista_vazia(lista)) return LISTA_VAZIA;

    Nodo *nodo = (*lista)->inicio;

    while (nodo != NULL) {
        if (nodo->chave == chave) {
            *elemento = nodo->elemento;
            return LISTA_SUCESSO;
        }

        nodo = nodo->proximo;
    }

    return LISTA_CHAVE_INVALIDA;
}

int lista_alterar(Lista **lista, int chave, Elemento *elemento) {
    if (lista_vazia(lista)) return LISTA_VAZIA;

    Nodo *nodo = (*lista)->inicio;

    while (nodo != NULL) {
        if (nodo->chave == chave) {
            nodo->elemento = *elemento;
            return LISTA_SUCESSO;
        }

        nodo = nodo->proximo;
    }

    return LISTA_CHAVE_INVALIDA;
}

int lista_for(Lista **lista, Elemento *elemento) {
    if (lista_vazia(lista)) return 0;

    if ((*lista)->controle == NULL) {
        (*lista)->controle = (*lista)->inicio;
        return 0;
    }

    *elemento = (*lista)->controle->elemento;
    (*lista)->controle = (*lista)->controle->proximo;

    return 1;
}

void lista_formatar(Lista **lista) {
    (*lista)->tamanho = 0;
    (*lista)->controle = NULL;

    while ((*lista)->inicio != NULL) {
        Nodo *nodo = (*lista)->inicio;
        (*lista)->inicio = (*lista)->inicio->proximo;
        free(nodo);
    }
}
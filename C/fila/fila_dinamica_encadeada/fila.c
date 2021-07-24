#include <stdlib.h>
#include "fila.h"

typedef struct Fila Nodo;
struct Fila
{
    Elemento elemento;
    Nodo *proximo;
};

void fila_inicializar(Fila **fila)
{
    *fila == NULL;
}

void fila_liberar(Fila **fila)
{
    Nodo *nodo = NULL;

    while (*fila != NULL)
    {
        nodo = *fila;
        *fila = (*fila)->proximo;
        free(nodo);
    }
}

int fila_obter_tamanho(Fila **fila)
{
    int tamanho = 0;
    Nodo *nodo = *fila;

    while (nodo != NULL)
    {
        nodo = nodo->proximo;
        tamanho++;
    }

    return tamanho;
}

int fila_vazia(Fila **fila)
{
    return *fila == NULL;
}

int fila_adicionar(Fila **fila, Elemento *elemento)
{
    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return FILA_SEM_MEMORIA;

    nodo->elemento = *elemento;

    if (*fila == NULL)
    {
        nodo->proximo = *fila;
        *fila = nodo;
    }
    else
    {
        Nodo *auxiliar = *fila;

        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }

        nodo->proximo = auxiliar->proximo;
        auxiliar->proximo = nodo;
    }

    return FILA_SUCESSO;
}

int fila_remover(Fila **fila, Elemento *elemento)
{
    if (fila_vazia(fila)) return FILA_VAZIA;

    Nodo *nodo = *fila;

    *elemento = (*fila)->elemento;
    *fila = (*fila)->proximo;
    free(nodo);

    return FILA_SUCESSO;
}

int fila_alterar(Fila **fila, Elemento *elemento)
{
    if (fila_vazia(fila)) return FILA_VAZIA;

    (*fila)->elemento = *elemento;

    return FILA_SUCESSO;
}

int fila_obter(Fila **fila, Elemento *elemento)
{
    if (fila_vazia(fila)) return FILA_VAZIA;

    *elemento = (*fila)->elemento;

    return FILA_SUCESSO;
}
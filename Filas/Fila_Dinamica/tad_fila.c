#include <stdlib.h>
#include "tad_fila.h"

/*  Estruturas */
struct tipo_nodo
{
    Elemento elemento;
    struct tipo_nodo *prox;
};
typedef struct tipo_nodo Nodo;

struct tipo_fila
{
    int tamanho;
    Nodo *inicio;
    Nodo *fim;
};

/*  Funcoes */
Fila *FILA_CriarFila(void)
{
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL)
    {
        fila->tamanho = 0;
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

int FILA_LiberarFila(Fila *fila)
{
    if(fila == NULL) return -1;
    Nodo *nodo;
    while(fila->inicio != NULL)
    {
        nodo = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(nodo);
    }
    free(fila);
    return 0;
}

int FILA_VerificarTamanhoFila(Fila *fila)
{
    if(fila == NULL) return -1;
    return fila->tamanho;
}

int FILA_VerificarFilaCheia(Fila *fila)
{
    if(fila == NULL) return -1;
    int fila_cheia;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    if(nodo == NULL)
    {
        fila_cheia = 1;
    }
    else
    {
        free(nodo);
        fila_cheia = 0;
    }
    return fila_cheia;
}

int FILA_VerificarFilaVazia(Fila *fila)
{
    if(fila == NULL) return -1;
    return (fila->inicio == NULL);
}

int FILA_IncluirElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return -1;
    if(FILA_VerificarFilaCheia(fila)) return -1;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->elemento = *elemento;
    nodo->prox = NULL;
    if(fila->inicio == NULL)
    {
        fila->inicio = nodo;
    }
    if(fila->fim != NULL)
    {
        fila->fim->prox = nodo;
    }
    fila->fim = nodo;
    fila->tamanho++;
    return 0;
}

int FILA_ExcluirElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL) return -1;
    if(FILA_VerificarFilaVazia(fila)) return -1;
    Nodo *nodo = fila->inicio;
    fila->inicio = fila->inicio->prox;
    *elemento = nodo->elemento;
    free(nodo);
    if(fila->inicio == NULL)
    {
        fila->fim = NULL;
    }
    fila->tamanho--;
    return 0;
}

int FILA_ObterElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return -1;
    if(FILA_VerificarFilaVazia(fila)) return -1;
    *elemento = fila->inicio->elemento;
    return 0;
}

int FILA_FormatarFila(Fila *fila)
{
    if(fila == NULL) return -1;
    Nodo *nodo;
    while(fila->inicio != NULL)
    {
        nodo = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(nodo);
    }
    fila->fim = NULL;
    fila->tamanho = 0;
    return 0;
}

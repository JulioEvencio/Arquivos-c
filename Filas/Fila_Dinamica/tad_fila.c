#include <stdlib.h>
#include "tad_fila.h"

/*  Constantes */
#define _TAD_FILA_INICIO 0
#define _TAD_FILA_FINAL 0
#define _TAD_FILA_TAMANHO_INICIO 0

/*  Estruturas */
struct tipo_nodo
{
    Elemento elemento;
    struct tipo_nodo *prox;
};
typedef struct tipo_nodo Nodo;

struct tipo_fila
{
    Nodo *inicio;
    Nodo *final;
};

/*  Funcoes */
Fila *TAD_CriarFila(void)
{
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL)
    {
        fila->inicio = NULL;
        fila->final = NULL;
    }
    return fila;
}

int TAD_LiberarFila(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    Nodo *nodo;
    while(fila->inicio != NULL)
    {
        nodo = fila->inicio;
        fila->inicio = nodo->prox;
        free(nodo);
    }
    fila->inicio = NULL;
    fila->final = NULL;
    free(fila);
    return TAD_FILA_SUCESSO;
}

int TAD_VerificarFilaTamanho(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    int tamanho = _TAD_FILA_INICIO;
    Nodo *nodo = fila->inicio;;
    while(nodo != NULL)
    {
        nodo = nodo->prox;
        tamanho++;
    }
    return tamanho;
}

int TAD_VerificarFilaCheia(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    int cheia;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    if(nodo == NULL)
    {
        cheia = 1;
    }
    else
    {
        cheia = 0;
    }
    free(nodo);
    return cheia;
}

int TAD_VerificarFilaVazia(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    return fila->inicio == NULL;
}

int TAD_IncluirElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    if(elemento == NULL) return TAD_ELEMENTO_INEXISTENTE;
    Nodo *no = (Nodo*) malloc(sizeof(Nodo));
    if(no == NULL) return TAD_FILA_INEXISTENTE;
    no->elemento = *elemento;
    no->prox = NULL;
    if(TAD_VerificarFilaVazia(fila))
    {
        fila->inicio = no;
    }
    else
    {
        fila->final->prox = no;
    }
    fila->final = no;
    return TAD_FILA_SUCESSO;
}

int TAD_ExcluirElemento(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    if(TAD_VerificarFilaVazia(fila)) return TAD_FILA_VAZIA;
    Nodo *nodo = fila->inicio;
    fila->inicio = nodo->prox;
    free(nodo);
    if(TAD_VerificarFilaVazia(fila)) fila->final = NULL;
    return TAD_FILA_SUCESSO;
}

int TAD_ObterElementoInicio(Fila *fila, Elemento *elemento)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    if(elemento == NULL) return TAD_ELEMENTO_INEXISTENTE;
    if(TAD_VerificarFilaVazia(fila)) return TAD_FILA_VAZIA;
    *elemento = fila->inicio->elemento;
    return TAD_FILA_SUCESSO;
}

int TAD_FormatarFila(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    Nodo *nodo;
    while(fila->inicio != NULL)
    {
        nodo = fila->inicio;
        fila->inicio = nodo->prox;
        free(nodo);
    }
    fila->inicio = NULL;
    fila->final = NULL;
    return TAD_FILA_SUCESSO;
}
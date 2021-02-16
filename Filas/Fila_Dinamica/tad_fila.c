#include <stdlib.h>
#include "tad_fila.h"

/*  Constantes */
#define _TAD_FILA_INICIO 0
#define _TAD_FILA_FINAL 0
#define _TAD_FILA_TAMANHO_INICIO 0

/*  Estruturas */
struct tipo_nodo
{
    Elemento *elemento;
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
    //  Code
}

int TAD_VerificarFilaCheia(Fila *fila)
{
    //  Code
}

int TAD_VerificarFilaVazia(Fila *fila)
{
    //  Code
}

int TAD_IncluirElemento(Fila *fila, Elemento *elemento)
{
    //  Code
}

int TAD_ExcluirElemento(Fila *fila)
{
    //  Code
}

int TAD_ObterElementoInicio(Fila *fila, Elemento *elemento)
{
    //  Code
}

int TAD_FormatarFila(Fila *fila)
{
    //  Code
}
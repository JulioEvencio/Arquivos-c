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
    //  Code
}

int TAD_LiberarFila(Fila *fila)
{
    //  Code
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
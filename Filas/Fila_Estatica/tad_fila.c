#include <stdlib.h>
#include "tad_fila.h"

/*  Constantes */
#define _TAD_FILA_INICIO 0
#define _TAD_FILA_FINAL 0
#define _TAD_FILA_TAMANHO_INICIO 0

/*  Estruturas */
struct tipo_fila
{
    int tamanho;
    int inicio;
    int final;
    Elemento elemento[TAD_FILA_TAMANHO_MAX];
};

/*  Funcoes */
Fila *TAD_CriarFila(void)
{
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL)
    {
        fila->tamanho = _TAD_FILA_TAMANHO_INICIO;
        fila->inicio = _TAD_FILA_INICIO;
        fila->final = _TAD_FILA_FINAL;
    }
    return fila;
}

int TAD_LiberarFila(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    free(fila);
    return TAD_FILA_SUCESSO;
}

int TAD_VerificarFilaTamanho(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    return fila->tamanho;
}

int TAD_VerificarFilaCheia(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    return fila->tamanho == TAD_FILA_TAMANHO_MAX;
}

int TAD_VerificarFilaVazia(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    return fila->tamanho == _TAD_FILA_TAMANHO_INICIO;
}

int TAD_IncluirElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    if(TAD_VerificarFilaCheia(fila)) return TAD_FILA_CHEIA;
    fila->elemento[fila->final] = *elemento;
    fila->final = (fila->final + 1) % TAD_FILA_TAMANHO_MAX;
    fila->tamanho++;
    return TAD_FILA_SUCESSO;
}

int TAD_ExcluirElemento(Fila *fila)
{
    if(fila == NULL) return TAD_FILA_INEXISTENTE;
    if(TAD_VerificarFilaVazia(fila)) return TAD_FILA_VAZIA;
    fila->inicio = (fila->inicio + 1) % TAD_FILA_TAMANHO_MAX;
    fila->tamanho++;
    return TAD_FILA_SUCESSO;
}
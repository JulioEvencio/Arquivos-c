#include <stdlib.h>
#include "tad_pilha.h"

/*  Estruturas */
struct tipo_nodo
{
    Elemento elemento;
    struct tipo_nodo *prox;
};
typedef struct tipo_nodo Nodo;

struct tipo_pilha
{
    int tamanho;
    Nodo *inicio;
};

/*  Funcoes */
Pilha *FILA_CriarFila(void)
{
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha != NULL)
    {
        pilha->tamanho = 0;
        pilha->inicio = NULL;
    }
    return pilha;
}

int PILHA_LiberarPilha(Pilha *pilha)
{
    if(pilha == NULL) return -1;
    Nodo *nodo;
    while(pilha->inicio != NULL)
    {
        nodo = pilha->inicio;
        pilha->inicio = pilha->inicio->prox;
        free(nodo);
    }
    free(pilha);
    return 0;
}

int PILHA_VerificarTamanhoPilha(Pilha *pilha)
{
    if(pilha == NULL) return -1;
    return pilha->tamanho;
}

int PILHA_VerificarPilhaCheia(Pilha *pilha)
{
    if(pilha == NULL) return -1;
    int pilha_cheia;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    if(nodo == NULL)
    {
        pilha_cheia = 1;
    }
    else
    {
        free(nodo);
        pilha_cheia = 0;
    }
    return pilha_cheia;
}

int PILHA_VerificarPilhaVazia(Pilha *pilha)
{
    if(pilha == NULL) return -1;
    return (pilha->inicio == NULL);
}

int PILHA_IncluirElemento(Pilha *pilha, Elemento *elemento)
{
    if(pilha == NULL || elemento == NULL) return -1;
    if(PILHA_VerificarPilhaCheia(pilha)) return -1;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->elemento = *elemento;
    nodo->prox = pilha->inicio;
    pilha->inicio = nodo;
    pilha->tamanho++;
    return 0;
}

int PILHA_ExcluirElemento(Pilha *pilha, Elemento *elemento)
{
    if(pilha == NULL) return -1;
    if(PILHA_VerificarPilhaVazia(pilha)) return -1;
    Nodo *nodo = pilha->inicio;
    pilha->inicio = pilha->inicio->prox;
    *elemento = nodo->elemento;
    free(nodo);
    pilha->tamanho--;
    return 0;
}

int PILHA_ObterElemento(Pilha *pilha, Elemento *elemento)
{
    if(pilha == NULL || elemento == NULL) return -1;
    if(PILHA_VerificarPilhaVazia(pilha)) return -1;
    *elemento = pilha->inicio->elemento;
    return 0;
}

int PILHA_FormatarPilha(Pilha *pilha)
{
    if(pilha == NULL) return -1;
    Nodo *nodo;
    while(pilha->inicio != NULL)
    {
        nodo = pilha->inicio;
        pilha->inicio = pilha->inicio->prox;
        free(nodo);
    }
    return 0;
}
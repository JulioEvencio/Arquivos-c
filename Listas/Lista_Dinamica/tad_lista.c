#include <stdlib.h>
#include "tad_lista.h"

/*  Estruturas */
struct tipo_nodo
{
    Elemento elemento;
    struct tipo_nodo *prox;
};
typedef struct tipo_nodo Nodo;

struct tipo_lista
{
    Nodo *inicio;
};

/*  Funcoes */
Lista *LISTA_CriarLista(void)
{
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL)
    {
        lista->inicio = NULL;
    }
    return lista;
}

int LISTA_LiberarLista(Lista *lista)
{
    if(lista == NULL) return -1;
    Nodo *nodo;
    while(lista->inicio != NULL)
    {
        nodo = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(nodo);
    }
    free(lista);
    return 0;
}

int LISTA_VerificarTamanho(Lista *lista)
{
    if(lista == NULL) return -1;
    int tamanho = 0;
    Nodo *nodo = lista->inicio;
    while(nodo != NULL)
    {
        nodo = nodo->prox;
        tamanho++;
    }
    return tamanho;
}

int LISTA_VerificarListaCheia(Lista *lista)
{
    if(lista == NULL) return -1;
    int lista_cheia;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    if(nodo == NULL)
    {
        lista_cheia = 1;
    }
    else
    {
        lista_cheia = 0;
    }
    free(nodo);
    return lista_cheia;
}

int LISTA_VerificarListaVazia(Lista *lista)
{
    if(lista == NULL) return -1;
    return (lista->inicio == NULL);
}

int LISTA_IncluirElemento(Lista *lista, Elemento *elemento)
{
    if(lista == NULL || elemento == NULL) return -1;
    if(LISTA_VerificarListaCheia(lista)) return -1;
    Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->elemento = *elemento;
    nodo->prox = lista->inicio;
    lista->inicio = nodo;
    return 0;
}

int LISTA_ExcluirElemento(Lista *lista, int posicao)
{
    if(lista == NULL) return -1;
    if(posicao < 1 || posicao > LISTA_VerificarTamanho(lista)) return -1;
    Nodo *nodo_atual = lista->inicio;
    if(posicao == 1)
    {
        lista->inicio = lista->inicio->prox;
        free(nodo_atual);
    }
    else
    {
        Nodo *nodo_anterior;
        for(int i = 1; i < posicao; i++)
        {
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->prox;
        }
        nodo_anterior->prox = nodo_atual->prox;
        free(nodo_atual);
    }
    return 0;
}

int LISTA_AlterarElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return -1;
    if(posicao < 1 || posicao > LISTA_VerificarTamanho(lista)) return -1;
    Nodo *nodo = lista->inicio;
    for(int i = 1; i < posicao; i++)
    {
        nodo = nodo->prox;
    }
    nodo->elemento = *elemento;
    return 0;
}

int LISTA_ObterElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return -1;
    if(posicao < 1 || posicao > LISTA_VerificarTamanho(lista)) return -1;
    Nodo *nodo = lista->inicio;
    for(int i = 1; i < posicao; i++)
    {
        nodo = nodo->prox;
    }
    *elemento = nodo->elemento;
    return 0;
}

int LISTA_FormatarLista(Lista *lista)
{
    if(lista == NULL) return -1;
    Nodo *nodo;
    while(lista->inicio != NULL)
    {
        nodo = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(nodo);
    }
    return 0;
}
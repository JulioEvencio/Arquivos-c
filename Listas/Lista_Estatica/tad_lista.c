#include <stdlib.h>
#include "tad_lista.h"

/*  Estruturas */
struct tipo_lista
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};

/*  Funcoes */
Lista *LISTA_CriarLista(int tamanho_max)
{
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL)
    {
        lista->tamanho = 0;
        lista->tamanho_max = tamanho_max;
        lista->elemento = (Elemento*) malloc(sizeof(Elemento) * lista->tamanho_max);
        if(lista->elemento == NULL)
        {
            free(lista);
            lista = NULL;
        }
    }
    return lista;
}

int LISTA_LiberarLista(Lista *lista)
{
    if(lista == NULL) return -1;
    free(lista->elemento);
    free(lista);
    return 0;
}

int LISTA_VerificarTamanho(Lista *lista)
{
    if(lista == NULL) return -1;
    return lista->tamanho;
}

int LISTA_VerificarListaCheia(Lista *lista)
{
    if(lista == NULL) return -1;
    return (lista->tamanho == lista->tamanho_max);
}

int LISTA_VerificarListaVazia(Lista *lista)
{
    if(lista == NULL) return -1;
    return (lista->tamanho == 0);
}

int LISTA_IncluirElemento(Lista *lista, Elemento *elemento)
{
    if(lista == NULL || elemento == NULL) return -1;
    if(LISTA_VerificarListaCheia(lista)) return -1;
    lista->elemento[lista->tamanho] = *elemento;
    lista->tamanho++;
    return 0;
}

int LISTA_ExcluirElemento(Lista *lista, int posicao)
{
    if(lista == NULL) return -1;
    if(posicao < 1 || posicao > lista->tamanho) return -1;
    for(int i = posicao; i < lista->tamanho; i++)
    {
        lista->elemento[i - 1] = lista->elemento[i];
    }
    lista->tamanho--;
    return 0;
}

int LISTA_AlterarElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return -1;
    if(posicao < 1 || posicao > lista->tamanho) return -1;
    lista->elemento[posicao - 1] = *elemento;
    return 0;
}

int LISTA_ObterElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return -1;
    if(posicao < 1 || posicao > lista->tamanho) return -1;
    *elemento = lista->elemento[posicao - 1];
    return 0;
}

int LISTA_FormatarLista(Lista *lista)
{
    if(lista == NULL) return -1;
    lista->tamanho = 0;
    return 0;
}
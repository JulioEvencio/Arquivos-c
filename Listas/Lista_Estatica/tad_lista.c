#include <stdlib.h>
#include "tad_lista.h"

/*	Estruturas */
struct tipo_lista
{
	int elementos;
	Cliente cliente[TAD_LISTA_TAMANHO_MAX];
};

/*	Funcoes */
Lista *TAD_CriarLista(void)
{
	Lista *lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL)
	{
		lista->elementos = TAD_LISTA_INICIO;
	}
	return lista;
}

int TAD_LiberarLista(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	free(lista);
	return TAD_LISTA_SUCESSO;
}

int TAD_VerificarListaTamanho(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	return lista->elementos;
}

int TAD_VerificarListaCheia(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	return lista->elementos == TAD_LISTA_TAMANHO_MAX;
}

int TAD_VerificarListaVazia(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	return lista->elementos == TAD_LISTA_INICIO;
}

int TAD_IncluirElementoInicio(Lista *lista, Cliente cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaCheia(lista)) return TAD_LISTA_CHEIA;
	for(int i = lista->elementos-1; i >= TAD_LISTA_INICIO; i--)
	{
		lista->cliente[i+1] = lista->cliente[i];
	}
	lista->cliente[TAD_LISTA_INICIO] = cliente;
	lista->elementos++;
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoFinal(Lista *lista, Cliente cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaCheia(lista)) return TAD_LISTA_CHEIA;
	lista->cliente[lista->elementos] = cliente;
	lista->elementos++;
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoOrdenada(Lista *lista, Cliente cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaCheia(lista)) return TAD_LISTA_CHEIA;
	int k, i = TAD_LISTA_INICIO;
	while(i < lista->elementos && lista->cliente[i].codigo < cliente.codigo)
	{
		i++
	}
	for(k = lista->elementos-1; k >= i; k--)
	{
		lista->cliente[k+1] = lista->cliente[k];
	}
	lista->cliente[i] = cliente;
	lista->elementos++;
	return TAD_LISTA_SUCESSO;
}
#include <stdlib.h>
#include "tad_lista.h"

/*	Estruturas */
struct tipo_nodo
{
	Cliente cliente;
	struct tipo_nodo *prox;
};
typedef struct tipo_nodo Nodo;

struct tipo_lista
{
	Nodo *inicio;
};

/*	Funcoes */
Lista *TAD_CriarLista(void)
{
	Lista *lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL)
	{
		lista->inicio = NULL;
	}
	return lista;
}

int TAD_LiberarLista(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	Nodo *nodo = NULL;
	while(lista->inicio != NULL)
	{
		nodo = lista->inicio;
		lista->inicio = nodo->prox;
		free(nodo);
	}
	free(lista);
	lista = NULL;
	return TAD_LISTA_SUCESSO;
}

int TAD_VerificarListaTamanho(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	int tamanho = TAD_LISTA_INICIO;
	Nodo *nodo = lista->inicio;
	while(nodo != NULL)
	{
		tamanho++;
		nodo = nodo->prox;
	}
	return tamanho;
}

int TAD_VerificarListaCheia(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	return 0;
}

int TAD_VerificarListaVazia(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(lista->inicio == NULL)
	{
		return 1;
	}
	return 0;
}

int TAD_IncluirElementoInicio(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	if(nodo == NULL) return TAD_LISTA_INEXISTENTE;
	nodo->cliente = *cliente;
	nodo->prox = lista->inicio;
	lista->inicio = nodo;
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoFinal(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoOrdenada(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoInicio(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoFinal(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoCodigo(Lista *lista, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_ObterElementoPosicao(Lista *lista, Cliente *cliente, int posicao)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_ObterElementoCodigo(Lista *lista, Cliente *cliente, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_AlterarElementoPosicao(Lista *lista, Cliente *cliente, int posicao)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_AlterarElementoCodigo(Lista *lista, Cliente *cliente, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}

int TAD_FormatarLista(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	//	Code
	return TAD_LISTA_SUCESSO;
}
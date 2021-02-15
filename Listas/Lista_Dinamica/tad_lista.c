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
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	if(nodo == NULL) return TAD_LISTA_INEXISTENTE;
	nodo->cliente = *cliente;
	nodo->prox = NULL;
	if(TAD_VerificarListaVazia(lista))
	{
		lista->inicio = nodo;
	}
	else
	{
		Nodo *no = lista->inicio;
		while(no->prox != NULL)
		{
			no = no->prox;
		}
		no->prox = nodo;
	}
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoOrdenada(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	if(nodo == NULL) return TAD_LISTA_INEXISTENTE;
	nodo->cliente = *cliente;
	nodo->prox = NULL;
	Nodo *no_anterior = NULL, *no_atual = lista->inicio;
	while(no_atual != NULL && no_atual->cliente.codigo < cliente->codigo)
	{
		no_anterior = no_atual;
		no_atual = no_atual->prox;
	}
	if(TAD_VerificarListaVazia(lista))
	{
		lista->inicio = nodo;
	}
	else
	{
		no_anterior->prox = nodo;
		nodo->prox = no_atual;
	}
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoInicio(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo = lista->inicio;
	lista->inicio = nodo->prox;
	free(nodo);
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoFinal(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo_anterior = NULL, *nodo = lista->inicio;
	while(nodo->prox != NULL)
	{
		nodo_anterior = nodo;
		nodo = nodo->prox;
	}
	if(nodo == lista->inicio)
	{
		lista->inicio = NULL;
	}
	else
	{
		nodo_anterior->prox = NULL;
	}
	free(nodo);
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoCodigo(Lista *lista, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo_anterior = NULL, *nodo = lista->inicio;
	while(nodo->prox != NULL && nodo->cliente.codigo != codigo)
	{
		nodo_anterior = nodo;
		nodo = nodo->prox;
	}
	if(nodo == NULL)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	if(nodo == lista->inicio)
	{
		lista->inicio = NULL;
	}
	else
	{
		nodo_anterior->prox = nodo->prox;
	}
	free(nodo);
	return TAD_LISTA_SUCESSO;
}

int TAD_ObterElementoPosicao(Lista *lista, Cliente *cliente, int posicao)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(posicao < TAD_LISTA_INICIO) return TAD_ELEMENTO_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo = lista->inicio;
	int i = TAD_LISTA_INICIO;
	while(nodo != NULL && i < posicao)
	{
		nodo = nodo->prox;
		i++;
	}
	if(nodo == NULL)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	else
	{
		*cliente = nodo->cliente;
	}
	return TAD_LISTA_SUCESSO;
}

int TAD_ObterElementoCodigo(Lista *lista, Cliente *cliente, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo = lista->inicio;
	while(nodo != NULL && nodo->cliente.codigo != codigo)
	{
		nodo = nodo->prox;
	}
	if(nodo == NULL)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	else
	{
		*cliente = nodo->cliente;
	}
	return TAD_LISTA_SUCESSO;
}

int TAD_AlterarElementoPosicao(Lista *lista, Cliente *cliente, int posicao)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(posicao < TAD_LISTA_INICIO) return TAD_ELEMENTO_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo = lista->inicio;
	int i = TAD_LISTA_INICIO + 1;
	while(nodo != NULL && i < posicao)
	{
		nodo = nodo->prox;
		i++;
	}
	if(nodo == NULL)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	else
	{
		nodo->cliente = *cliente;
	}
	return TAD_LISTA_SUCESSO;
}

int TAD_AlterarElementoCodigo(Lista *lista, Cliente *cliente, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	Nodo *nodo = lista->inicio;
	while(nodo != NULL && nodo->cliente.codigo != codigo)
	{
		nodo = nodo->prox;
	}
	if(nodo == NULL)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	else
	{
		nodo->cliente = *cliente;
	}
	return TAD_LISTA_SUCESSO;
}

int TAD_FormatarLista(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	Nodo *nodo = NULL;
	while(lista->inicio != NULL)
	{
		nodo = lista->inicio;
		lista->inicio = nodo->prox;
		free(nodo);
	}
	return TAD_LISTA_SUCESSO;
}
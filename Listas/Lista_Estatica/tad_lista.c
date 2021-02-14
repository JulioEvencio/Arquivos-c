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

int TAD_IncluirElementoInicio(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaCheia(lista)) return TAD_LISTA_CHEIA;
	for(int i = lista->elementos; i >= TAD_LISTA_INICIO; i--)
	{
		lista->cliente[i] = lista->cliente[i - 1];
	}
	lista->cliente[TAD_LISTA_INICIO] = *cliente;
	lista->elementos++;
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoFinal(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaCheia(lista)) return TAD_LISTA_CHEIA;
	lista->cliente[lista->elementos] = *cliente;
	lista->elementos++;
	return TAD_LISTA_SUCESSO;
}

int TAD_IncluirElementoOrdenada(Lista *lista, Cliente *cliente)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaCheia(lista)) return TAD_LISTA_CHEIA;
	int k, i = TAD_LISTA_INICIO;
	while(i < lista->elementos && lista->cliente[i].codigo < cliente->codigo)
	{
		i++;
	}
	for(k = lista->elementos; k >= i; k--)
	{
		lista->cliente[k] = lista->cliente[k - 1];
	}
	lista->cliente[i] = *cliente;
	lista->elementos++;
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoInicio(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	for(int i = TAD_LISTA_INICIO; i < lista->elementos; i++)
	{
		lista->cliente[i] = lista->cliente[i + 1];
	}
	lista->elementos--;
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoFinal(Lista *lista)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	lista->elementos--;
	return TAD_LISTA_SUCESSO;
}

int TAD_ExcluirElementoCodigo(Lista *lista, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(TAD_VerificarListaVazia(lista)) return TAD_LISTA_VAZIA;
	int k, i = TAD_LISTA_INICIO;
	while(i < lista->elementos && lista->cliente[i].codigo != codigo)
	{
		i++;
	}
	if(i == lista->elementos)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	for(k = i; k < lista->elementos; k++)
	{
		lista->cliente[k] = lista->cliente[k + 1];
	}
	lista->elementos--;
	return TAD_LISTA_SUCESSO;
}

int TAD_ObterElementoPosicao(Lista *lista, Cliente *cliente, int posicao)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(posicao < TAD_LISTA_INICIO || posicao > lista->elementos) return TAD_POSICAO_INVALIDA;
	*cliente = lista->cliente[posicao];
	return TAD_LISTA_SUCESSO;
}

int TAD_ObterElementoCodigo(Lista *lista, Cliente *cliente, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	int i = TAD_LISTA_INICIO;
	while(i < lista->elementos && lista->cliente[i].codigo != codigo)
	{
		i++;
	}
	if(i == lista->elementos)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	*cliente = lista->cliente[i];
	return TAD_LISTA_SUCESSO;
}

int TAD_AlterarElementoPosicao(Lista *lista, Cliente *cliente, int posicao)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	if(posicao < TAD_LISTA_INICIO || posicao > lista->elementos) return TAD_POSICAO_INVALIDA;
	lista->cliente[posicao] = *cliente;
	return TAD_LISTA_SUCESSO;
}

int TAD_AlterarElementoCodigo(Lista *lista, Cliente *cliente, int codigo)
{
	if(lista == NULL) return TAD_LISTA_INEXISTENTE;
	int i = TAD_LISTA_INICIO;
	while(i < lista->elementos && lista->cliente[i].codigo != codigo)
	{
		i++;
	}
	if(i == lista->elementos)
	{
		return TAD_ELEMENTO_INEXISTENTE;
	}
	lista->cliente[i] = *cliente;
	return TAD_LISTA_SUCESSO;
}
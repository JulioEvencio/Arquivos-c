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
		lista->elementos = TAD_LISTA_VAZIA;
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
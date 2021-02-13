#ifndef TAD_LISTA_H_INCLUDED
#define TAD_LISTA_H_INCLUDED

/*	Constantes */
#define TAD_LISTA_TAMANHO_MAX 100
#define TAD_LISTA_INICIO 0
//	Erros
#define TAD_LISTA_SUCESSO 0
#define TAD_LISTA_INEXISTENTE -1
#define TAD_LISTA_CHEIA -2
#define TAD_LISTA_VAZIA -3
#define TAD_ELEMENTO_INEXISTENTE -4

/*	Estruturas */
struct tipo_cliente
{
	int codigo;
	char nome[80];
};

/*	Ponteiros */
typedef struct tipo_cliente Cliente;
typedef struct tipo_lista Lista;

/*	Funcoes */
Lista *TAD_CriarLista(void);
int TAD_LiberarLista(Lista *lista);
int TAD_VerificarListaTamanho(Lista *lista);
int TAD_VerificarListaCheia(Lista *lista);
int TAD_VerificarListaVazia(Lista *lista);
int TAD_IncluirElementoInicio(Lista *lista, Cliente cliente);
int TAD_IncluirElementoFinal(Lista *lista, Cliente cliente);
int TAD_IncluirElementoOrdenada(Lista *lista, Cliente cliente);
int TAD_ExcluirElementoInicio(Lista *lista);
int TAD_ExcluirElementoFinal(Lista *lista);
int TAD_ExcluirElementoCodigo(Lista *lista, int codigo);

#endif
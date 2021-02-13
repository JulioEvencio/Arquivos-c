#ifndef TAD_LISTA_H_INCLUDED
#define TAD_LISTA_H_INCLUDED

/*	Constantes */
#define TAD_LISTA_TAMANHO_MAX 100
#define TAD_LISTA_VAZIA 0
#define TAD_LISTA_INICIO 0
//	Erros
#define TAD_LISTA_SUCESSO 0
#define TAD_LISTA_INEXISTENTE -1

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

#endif
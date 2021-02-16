#ifndef TAD_FILA_H_INCLUDED
#define TAD_FILA_H_INCLUDED

/*  Constantes */
#define NOME_TAMANHO 80
#define TAD_FILA_TAMANHO_MAX 100
//	Erros
#define TAD_FILA_SUCESSO 0
#define TAD_FILA_INEXISTENTE -1
#define TAD_FILA_CHEIA -2
#define TAD_FILA_VAZIA -3
#define TAD_ELEMENTO_INEXISTENTE -4
#define TAD_POSICAO_INVALIDA -5

/*  Estruturas */
struct tipo_elemento
{
    int n;
};

/*  Typedef */
typedef struct tipo_fila Fila;
typedef struct tipo_elemento Elemento;

/*  Funcoes */
Fila *TAD_CriarFila(void);
int TAD_LiberarFila(Fila *fila);
int TAD_VerificarFilaTamanho(Fila *fila);
int TAD_VerificarFilaCheia(Fila *fila);
int TAD_VerificarFilaVazia(Fila *fila);
int TAD_IncluirElemento(Fila *fila, Elemento *elemento);
int TAD_ExcluirElemento(Fila *fila);
int TAD_ObterElementoInicio(Fila *fila, Elemento *elemento);

#endif
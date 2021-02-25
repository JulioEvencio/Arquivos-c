#ifndef TAD_LISTA_INCLUDED
#define TAD_LISTA_INCLUDED

/*  Constantes */

/*  Estruturas */
struct tipo_elemento
{
    int codigo;
    char nome[80];
};

/*  Typedef */
typedef struct tipo_fila Fila;
typedef struct tipo_elemento Elemento;

/*  Funcoes */
Fila *FILA_CriarFila(void);
int FILA_LiberarFila(Fila *fila);
int FILA_VerificarTamanhoFila(Fila *fila);
int FILA_VerificarFilaCheia(Fila *fila);
int FILA_VerificarFilaVazia(Fila *fila);
int FILA_IncluirElemento(Fila *fila, Elemento *elemento);
int FILA_ExcluirElemento(Fila *fila, Elemento *elemento);
int FILA_ObterElemento(Fila *fila, Elemento *elemento);
int FILA_FormatarFila(Fila *fila);

#endif
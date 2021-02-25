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
typedef struct tipo_lista Lista;
typedef struct tipo_elemento Elemento;

/*  Funcoes */
Lista *LISTA_CriarLista(void);
int LISTA_LiberarLista(Lista *lista);
int LISTA_VerificarTamanho(Lista *lista);
int LISTA_VerificarListaCheia(Lista *lista);
int LISTA_VerificarListaVazia(Lista *lista);
int LISTA_IncluirElemento(Lista *lista, Elemento *elemento);
int LISTA_ExcluirElemento(Lista *lista, int posicao);
int LISTA_AlterarElemento(Lista *lista, Elemento *elemento, int posicao);
int LISTA_ObterElemento(Lista *lista, Elemento *elemento, int posicao);
int LISTA_FormatarLista(Lista *lista);

#endif
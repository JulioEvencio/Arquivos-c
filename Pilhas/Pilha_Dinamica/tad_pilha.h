#ifndef TAD_PILHA_INCLUDED
#define TAD_PILHA_INCLUDED

/*  Constantes */

/*  Estruturas */
struct tipo_elemento
{
    int codigo;
    char nome[80];
};

/*  Typedef */
typedef struct tipo_pilha Pilha;
typedef struct tipo_elemento Elemento;

/*  Funcoes */
Pilha *FILA_CriarFila(void);
int PILHA_LiberarPilha(Pilha *pilha);
int PILHA_VerificarTamanhoPilha(Pilha *pilha);
int PILHA_VerificarPilhaCheia(Pilha *pilha);
int PILHA_VerificarPilhaVazia(Pilha *pilha);
int PILHA_IncluirElemento(Pilha *pilha, Elemento *elemento);
int PILHA_ExcluirElemento(Pilha *pilha, Elemento *elemento);
int PILHA_ObterElemento(Pilha *pilha, Elemento *elemento);
int PILHA_FormatarPilha(Pilha *pilha);

#endif
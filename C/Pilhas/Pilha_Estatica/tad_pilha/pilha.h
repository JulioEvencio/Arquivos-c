#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*  Constantes */
#define PILHA_SUCESSO 0
#define PILHA_ENDERECO_INVALIDO -1
#define PILHA_CHEIA -2
#define PILHA_VAZIA -3
#define PILHA_TAMANHO_INVALIDO -4
#define PILHA_SEM_MEMORIA -5

typedef struct Tipo_Pilha Pilha;

/*  Funcoes*/
int PILHA_InicializarPilha(Pilha *pilha, int tamanho);
int PILHA_LiberarPilha(Pilha *pilha);
int PILHA_VerificarPilhaTamanho(Pilha *pilha);
int PILHA_VerificarPilhaCheia(Pilha *pilha);
int PILHA_VerificarPilhaVazia(Pilha *pilha);
int PILHA_EmpilharElemento(Pilha *pilha, Elemento elemento);
int PILHA_DesempilharElemento(Pilha *pilha, Elemento *elemento);
int PILHA_ObterElemento(Pilha *pilha, Elemento *elemento);
int PILHA_FormatarPilha(Pilha *pilha);

#endif
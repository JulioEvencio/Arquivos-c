#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*  Constantes */
#define PILHA_SUCESSO 0
#define PILHA_ENDERECO_INVALIDO -1
#define PILHA_LISTA_CHEIA -2
#define PILHA_VAZIA -3
#define PILHA_POSICAO_INEXISTENTE -4
#define PILHA_TAMANHO_INVALIDO -5

/*  Estruturas */
struct Tipo_Pilha
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};
typedef struct Tipo_Pilha Pilha;

/*  Funcoes*/

#endif
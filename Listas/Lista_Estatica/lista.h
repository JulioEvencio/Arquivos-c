#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*  Constantes */
#define LISTA_SUCESSO 0
#define LISTA_ENDERECO_INVALIDO -1
#define LISTA_LISTA_CHEIA -2
#define LISTA_LISTA_VAZIA -3
#define LISTA_POSICAO_INEXISTENTE -4

/*  Estruturas */
struct Tipo_Lista
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};
typedef struct Tipo_Lista Lista;

/*  Funcoes */

#endif
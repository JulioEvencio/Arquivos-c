#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/*  Constantes */
#define FILA_SUCESSO 0
#define FILA_ENDERECO_INVALIDO -1
#define FILA_FILA_CHEIA -2
#define FILA_FILA_VAZIA -3
#define FILA_POSICAO_INEXISTENTE -4

/*  Estruturas */
struct Tipo_Fila
{
    int tamanho;
    int inicio;
    int fim;
    Elemento *elemento;
};
typedef struct Tipo_Fila Fila;

/*  Funcoes */

#endif

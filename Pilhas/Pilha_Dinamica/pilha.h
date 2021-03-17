#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*  Constantes */

/*  Estruturas */
typedef struct Tipoo_Nodo Nodo;
struct Tipo_Nodo
{
    Elemento elemento;
    Nodo *prox;
};

struct Tipo_Pilha
{
    int tamanho;
    Nodo *inicio;
};
typedef struct Tipo_Pilha Pilha;

/*  Funcoes */

#endif
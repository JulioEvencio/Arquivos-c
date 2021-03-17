#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define FILA_SUCESSO 0
#define FILA_ENDERECO_INVALIDO -1
#define FILA_FILA_CHEIA -2
#define FILA_FILA_VAZIA -3
#define FILA_POSICAO_INEXISTENTE -4

typedef struct Tipo_Nodo Nodo;
struct Tipo_Nodo
{
    Elemento elemento;
    Nodo *prox;
};

struct Tipo_Fila
{
    Nodo *inicio;
    Nodo *fim;
};
typedef struct Tipo_Fila Fila;

#endif
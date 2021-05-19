#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

enum
{
    FILA_SUCESSO,
    FILA_SEM_MEMORIA,
    FILA_VAZIA,
    FILA_CHEIA,
    FILA_TAMANHO_INVALIDO,
};

struct Elemento
{
    int x;
};
typedef struct Elemento Elemento;

typedef struct Fila Fila;

int fila_inicializar(Fila **fila, int tamanho);
void fila_liberar(Fila **fila);

int fila_obter_tamanho(Fila **fila);
int fila_vazia(Fila **fila);
int fila_cheia(Fila **fila);

int fila_adicionar(Fila **fila, Elemento *elemento);
int fila_remover(Fila **fila, Elemento *elemento);

int fila_alterar(Fila **fila, Elemento *elemento);
int fila_obter(Fila **fila, Elemento *elemento);

#endif

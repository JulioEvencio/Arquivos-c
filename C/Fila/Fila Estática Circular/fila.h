#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define FILA_SUCESSO 0
#define FILA_SEM_MEMORIA -1
#define FILA_VAZIA -2
#define FILA_CHEIA -3
#define FILA_TAMANHO_INVALIDO -4

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Fila Fila;

int fila_inicializar(Fila **fila, int tamanho);
void fila_liberar(Fila **fila);

int fila_tamanho(Fila **fila);
int fila_vazia(Fila **fila);
int fila_cheia(Fila **fila);

int fila_adicionar(Fila **fila, Elemento *elemento);
int fila_remover(Fila **fila);

int fila_alterar(Fila **fila, Elemento *elemento);
int fila_obter(Fila **fila, Elemento *elemento);

#endif

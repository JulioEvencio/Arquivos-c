#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct Elemento {
    int numero;
};

enum Enum_Fila {
    FILA_SUCESSO,
    FILA_SEM_MEMORIA,
    FILA_VAZIA
};

typedef struct Fila Fila;
typedef struct Elemento Elemento;

int fila_criar(Fila **fila);
void fila_liberar(Fila **fila);

int fila_tamanho(Fila **fila);
int fila_vazia(Fila **fila);

int fila_adicionar(Fila **fila, Elemento *elemento);
int fila_remover(Fila **fila, Elemento *elemento);

int fila_obter(Fila **fila, Elemento *elemento);
int fila_alterar(Fila **fila, Elemento *elemento);

void fila_formatar(Fila **fila);

#endif
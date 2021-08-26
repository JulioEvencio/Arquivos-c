#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct Elemento {
    int numero;
};

enum Enum_Lista {
    LISTA_SUCESSO,
    LISTA_SEM_MEMORIA,
    LISTA_VAZIA,
    LISTA_CHAVE_INVALIDA
};

typedef struct Lista Lista;
typedef struct Elemento Elemento;

int lista_criar(Lista **lista);
void lista_liberar(Lista **lista);

int lista_tamanho(Lista **lista);
int lista_vazia(Lista **lista);
int lista_contem(Lista **lista, int chave);

int lista_adicionar(Lista **lista, int chave, Elemento *elemento);
int lista_remover(Lista **lista, int chave, Elemento *elemento);

int lista_obter(Lista **lista, int chave, Elemento *elemento);
int lista_alterar(Lista **lista, int chave, Elemento *elemento);

int lista_for(Lista **lista, Elemento *elemento);
void lista_formatar(Lista **lista);

#endif
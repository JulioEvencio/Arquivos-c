#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

enum
{
    PILHA_SUCESSO,
    PILHA_SEM_MEMORIA,
    PILHA_VAZIA,
    PILHA_CHEIA,
    PILHA_TAMANHO_INVALIDO
};

struct Elemento
{
    int x;
};
typedef struct Elemento Elemento;

typedef struct Pilha Pilha;

int pilha_inicializar(Pilha **pilha, int tamanho);
void pilha_liberar(Pilha **pilha);

int pilha_obter_tamanho(Pilha **pilha);
int pilha_vazia(Pilha **pilha);
int pilha_cheia(Pilha **pilha);

int pilha_empilhar(Pilha **pilha, Elemento *elemento);
int pilha_desempilhar(Pilha **pilha, Elemento *elemento);

int pilha_alterar(Pilha **pilha, Elemento *elemento);
int pilha_obter(Pilha **pilha, Elemento *elemento);

#endif
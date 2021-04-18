#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define PILHA_SUCESSO 0
#define PILHA_SEM_MEMORIA -1
#define PILHA_VAZIA -2
#define PILHA_CHEIA -3
#define PILHA_POSICAO_INEXISTENTE -4
#define PILHA_TAMANHO_INVALIDO -5

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Pilha Pilha;

int pilha_inicializar(Pilha **pilha, int tamanho);
void pilha_liberar(Pilha **pilha);

int pilha_tamanho(Pilha **pilha);
int pilha_vazia(Pilha **pilha);
int pilha_cheia(Pilha **pilha);

int pilha_empilhar(Pilha **pilha, Elemento *elemento);
int pilha_desempilhar(Pilha **pilha);

int pilha_alterar(Pilha **pilha, Elemento *elemento);
int pilha_obter(Pilha **pilha, Elemento *elemento);

#endif
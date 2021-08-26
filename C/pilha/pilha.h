#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

struct Elemento {
    int numero;
};

enum Enum_Pilha {
    PILHA_SUCESSO,
    PILHA_SEM_MEMORIA,
    PILHA_VAZIA
};

typedef struct Pilha Pilha;
typedef struct Elemento Elemento;

int pilha_criar(Pilha **pilha);
void pilha_liberar(Pilha **pilha);

int pilha_tamanho(Pilha **pilha);
int pilha_vazia(Pilha **pilha);

int pilha_empilhar(Pilha **pilha, Elemento *elemento);
int pilha_desempilhar(Pilha **pilha, Elemento *elemento);

int pilha_obter(Pilha **pilha, Elemento *elemento);
int pilha_alterar(Pilha **pilha, Elemento *elemento);

void pilha_formatar(Pilha **pilha);

#endif
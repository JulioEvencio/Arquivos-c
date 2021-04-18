#include <stdlib.h>
#include "pilha.h"

struct Pilha
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};

int pilha_inicializar(Pilha **pilha, int tamanho);
void pilha_liberar(Pilha **pilha);

int pilha_tamanho(Pilha **pilha);
int pilha_vazia(Pilha **pilha);
int pilha_cheia(Pilha **pilha);

int pilha_empilhar(Pilha **pilha, Elemento *elemento);

int pilha_desempilhar(Pilha **pilha);

int pilha_alterar(Pilha **pilha, Elemento *elemento);

int pilha_obter(Pilha **pilha, Elemento *elemento);
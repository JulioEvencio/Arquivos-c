#include <stdlib.h>
#include "pilha.h"

#define PILHA_INICIO 1

struct Pilha {
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};

int pilha_inicializar(Pilha **pilha, int tamanho) {
    if (tamanho < PILHA_INICIO) return PILHA_TAMANHO_INVALIDO;
    
    *pilha = malloc(sizeof **pilha);

    if (*pilha == NULL) return PILHA_SEM_MEMORIA;

    (*pilha)->elemento = malloc(sizeof((*pilha)->elemento) * tamanho);

    if ((*pilha)->elemento == NULL) {
        free(*pilha);
        return PILHA_SEM_MEMORIA;
    }

    (*pilha)->tamanho = 0;
    (*pilha)->tamanho_max = tamanho;

    return PILHA_SUCESSO;
}

void pilha_liberar(Pilha **pilha) {
    free((*pilha)->elemento);
    free(*pilha);
}

int pilha_tamanho(Pilha **pilha) {
    return (*pilha)->tamanho;
}

int pilha_vazia(Pilha **pilha) {
    return (*pilha)->tamanho == 0;
}

int pilha_cheia(Pilha **pilha) {
    return (*pilha)->tamanho == (*pilha)->tamanho_max;
}

int pilha_empilhar(Pilha **pilha, Elemento *elemento) {
    if (pilha_cheia(pilha)) return PILHA_CHEIA;

    (*pilha)->elemento[(*pilha)->tamanho] = *elemento;
    (*pilha)->tamanho++;

    return PILHA_SUCESSO;
}

int pilha_desempilhar(Pilha **pilha) {
    if (pilha_vazia(pilha)) return PILHA_VAZIA;

    (*pilha)->tamanho--;

    return PILHA_SUCESSO;
}

int pilha_alterar(Pilha **pilha, Elemento *elemento) {
    if (pilha_vazia(pilha)) return PILHA_VAZIA;

    (*pilha)->elemento[(*pilha)->tamanho - 1] = *elemento;

    return PILHA_SUCESSO;
}

int pilha_obter(Pilha **pilha, Elemento *elemento) {
    if (pilha_vazia(pilha)) return PILHA_VAZIA;

    *elemento = (*pilha)->elemento[(*pilha)->tamanho - 1];

    return PILHA_SUCESSO;
}
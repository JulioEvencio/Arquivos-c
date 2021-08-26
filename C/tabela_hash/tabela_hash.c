#include <stdlib.h>
#include "tabela_hash.h"

enum Tabela_Hash_Constantes {
    TABELA_HASH_VETOR = 1000
};

typedef struct Nodo Nodo;
struct Nodo {
    int chave;
    Elemento elemento;
    Nodo *proximo;
};

struct Tabela_Hash {
    int tamanho;
    int controle_vetor;
    Nodo *controle_nodo;
    Nodo *vetor[TABELA_HASH_VETOR];
};

int tabela_hash_gerar_hash(int chave) {
    return chave % TABELA_HASH_VETOR;
}

int tabela_hash_criar(Tabela_Hash **tabela_hash) {
    *tabela_hash = malloc(sizeof **tabela_hash);

    if (*tabela_hash == NULL) return TABELA_HASH_SEM_MEMORIA;

    (*tabela_hash)->tamanho = 0;
    (*tabela_hash)->controle_vetor = 0;
    (*tabela_hash)->controle_nodo = NULL;

    for (int i = 0; i < TABELA_HASH_VETOR; i++) {
        (*tabela_hash)->vetor[i] = NULL;
    }

    return TABELA_HASH_SUCESSO;
}

void tabela_hash_liberar(Tabela_Hash **tabela_hash) {
    for (int i = 0; i < TABELA_HASH_VETOR; i++) {
        while ((*tabela_hash)->vetor[i] != NULL) {
            Nodo *nodo = (*tabela_hash)->vetor[i];
            (*tabela_hash)->vetor[i] = (*tabela_hash)->vetor[i]->proximo;
            free(nodo);
        }
    }

    free(*tabela_hash);
}

int tabela_hash_tamanho(Tabela_Hash **tabela_hash) {
    return (*tabela_hash)->tamanho;
}

int tabela_hash_vazia(Tabela_Hash **tabela_hash) {
    return tabela_hash_tamanho(tabela_hash) == 0;
}

int tabela_hash_contem(Tabela_Hash **tabela_hash, int chave) {
    Nodo *nodo = (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)];

    while (nodo != NULL) {
        if (nodo->chave == chave) return 1;

        nodo = nodo->proximo;
    }

    return 0;
}

int tabela_hash_adicionar(Tabela_Hash **tabela_hash, int chave, Elemento *elemento) {
    if (tabela_hash_contem(tabela_hash, chave)) return TABELA_HASH_CHAVE_INVALIDA;

    Nodo *nodo = malloc(sizeof *nodo);

    if (nodo == NULL) return TABELA_HASH_SEM_MEMORIA;

    nodo->chave = chave;
    nodo->elemento = *elemento;
    nodo->proximo = (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)];

    (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)] = nodo;
    (*tabela_hash)->tamanho++;
    (*tabela_hash)->controle_nodo = (*tabela_hash)->vetor[0];

    return TABELA_HASH_SUCESSO;
}

int tabela_hash_remover(Tabela_Hash **tabela_hash, int chave, Elemento *elemento) {
    if (tabela_hash_vazia(tabela_hash)) return TABELA_HASH_VAZIA;

    Nodo *nodo = (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)];

    if (nodo->chave == chave) {
        if (elemento != NULL) *elemento = nodo->elemento;

        (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)] = nodo->proximo;
        (*tabela_hash)->tamanho--;
        (*tabela_hash)->controle_nodo = (*tabela_hash)->vetor[0];

        free(nodo);

        return TABELA_HASH_SUCESSO;
    } else {
        Nodo *nodo_anterior;

        while (nodo != NULL) {
            if (nodo->chave == chave) {
                if (elemento != NULL) *elemento = nodo->elemento;

                (*tabela_hash)->tamanho--;
                nodo_anterior->proximo = nodo->proximo;

                free(nodo);

                return TABELA_HASH_SUCESSO;
            }

            nodo_anterior = nodo;
            nodo = nodo->proximo;
        }
    }

    return TABELA_HASH_CHAVE_INVALIDA;
}

int tabela_hash_obter(Tabela_Hash **tabela_hash, int chave, Elemento *elemento) {
    if (tabela_hash_vazia(tabela_hash)) return TABELA_HASH_VAZIA;

    Nodo *nodo = (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)];

    while (nodo != NULL) {
        if (nodo->chave == chave) {
            *elemento = nodo->elemento;
            return TABELA_HASH_SUCESSO;
        }

        nodo = nodo->proximo;
    }

    return TABELA_HASH_CHAVE_INVALIDA;
}

int tabela_hash_alterar(Tabela_Hash **tabela_hash, int chave, Elemento *elemento) {
    if (tabela_hash_vazia(tabela_hash)) return TABELA_HASH_VAZIA;

    Nodo *nodo = (*tabela_hash)->vetor[tabela_hash_gerar_hash(chave)];

    while (nodo != NULL) {
        if (nodo->chave == chave) {
            nodo->elemento = *elemento;
            return TABELA_HASH_SUCESSO;
        }

        nodo = nodo->proximo;
    }

    return TABELA_HASH_CHAVE_INVALIDA;
}

int tabela_hash_for(Tabela_Hash **tabela_hash, Elemento *elemento) {
    if (tabela_hash_vazia(tabela_hash)) return 0;

    inicio:

    if ((*tabela_hash)->controle_vetor == TABELA_HASH_VETOR) {
        (*tabela_hash)->controle_vetor = 0;
        (*tabela_hash)->controle_nodo = (*tabela_hash)->vetor[0];
        return 0;
    }

    if ((*tabela_hash)->controle_nodo == NULL) {
        (*tabela_hash)->controle_vetor++;
        (*tabela_hash)->controle_nodo = (*tabela_hash)->vetor[(*tabela_hash)->controle_vetor];
        goto inicio;
    }

    *elemento = (*tabela_hash)->controle_nodo->elemento;
    (*tabela_hash)->controle_nodo = (*tabela_hash)->controle_nodo->proximo;

    return 1;
}

void tabela_hash_formatar(Tabela_Hash **tabela_hash) {
    (*tabela_hash)->tamanho = 0;
    (*tabela_hash)->controle_vetor = 0;
    (*tabela_hash)->controle_nodo = NULL;

    for (int i = 0; i < TABELA_HASH_VETOR; i++) {
        while ((*tabela_hash)->vetor[i] != NULL) {
            Nodo *nodo = (*tabela_hash)->vetor[i];
            (*tabela_hash)->vetor[i] = (*tabela_hash)->vetor[i]->proximo;
            free(nodo);
        }
    }
}
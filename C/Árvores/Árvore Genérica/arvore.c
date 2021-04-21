#include <stdlib.h>
#include "arvore.h"

typedef struct Nodo Nodo;
struct Nodo {
    int id;
    Elemento elemento;
    Nodo *esquerda;
    Nodo *direita;
};

int arvore_criar_nodo(Arvore **arvore, Elemento *elemento, int id);
Nodo* arvore_localizar_nodo(Nodo *nodo, int id);

int arvore_criar_arvore(Arvore **arvore, Elemento *elemento, int id) {
    if (arvore_criar_nodo(arvore, elemento, id)) return ARVORE_SEM_MEMORIA;

    return ARVORE_SUCESSO;
}

int arvore_liberar_arvore(Arvore **arvore) {
	if (*arvore == NULL) return ARVORE_NULA;

	if ((*arvore)->esquerda != NULL) arvore_liberar_arvore(&(*arvore)->esquerda);
	if ((*arvore)->direita != NULL) arvore_liberar_arvore(&(*arvore)->direita);

	free(*arvore);

	return ARVORE_SUCESSO;
}

int arvore_criar_nodo(Arvore **arvore, Elemento *elemento, int id) {
    *arvore = malloc(sizeof **arvore);

    if (*arvore == NULL) return ARVORE_SEM_MEMORIA;

    (*arvore)->elemento = *elemento;
    (*arvore)->id = id;
    (*arvore)->esquerda = NULL;
    (*arvore)->direita = NULL;

    return ARVORE_SUCESSO;
}

Nodo* arvore_localizar_nodo(Nodo *nodo, int id) {
    Nodo *esquerda = NULL, *direita = NULL;

    if (nodo->id == id) return nodo;

    if (nodo->esquerda != NULL) esquerda = arvore_localizar_nodo(nodo->esquerda, id);

    if (esquerda == NULL) {
        if (nodo->direita != NULL) direita = arvore_localizar_nodo(nodo->direita, id);
        return direita;
    }

    return esquerda;
}

int arvore_adicionar_elemento(Arvore **arvore, int id_pai, int id_filho, Elemento *elemento) {
    Nodo *nodo_pai = NULL, *nodo_filho = NULL;

    if (*arvore == NULL) return ARVORE_NULA;

    nodo_pai = arvore_localizar_nodo((*arvore), id_pai);

    if (nodo_pai == NULL) return ARVORE_ID_INEXISTENTE;

    if (arvore_criar_nodo(&nodo_filho, elemento, id_filho)) return ARVORE_SEM_MEMORIA;

    if (nodo_pai->esquerda == NULL) nodo_pai->esquerda = nodo_filho;
    else {
        Nodo *nodo = nodo_pai->esquerda;

        while (nodo->direita != NULL) nodo = nodo->direita;

        nodo->direita = nodo_filho;
    }

    return ARVORE_SUCESSO;
}

int arvore_localizar_elemento(Arvore **arvore, Elemento *elemento, int id) {
    int sucesso = ARVORE_ELEMENTO_INVALIDO;

    if (*arvore == NULL) return ARVORE_NULA;

    if ((*arvore)->id == id) {
        *elemento = (*arvore)->elemento;
    	sucesso = ARVORE_SUCESSO;
    }

    if (sucesso != ARVORE_SUCESSO && (*arvore)->esquerda != NULL) {
    	sucesso = arvore_localizar_elemento(&(*arvore)->esquerda, elemento, id);
    }

    if (sucesso != ARVORE_SUCESSO && (*arvore)->direita != NULL) {
    	sucesso = arvore_localizar_elemento(&(*arvore)->direita, elemento, id);
    }

    return sucesso;
}

int arvore_alterar_elemento(Arvore **arvore, Elemento *elemento, int id) {
    int sucesso = ARVORE_ELEMENTO_INVALIDO;

    if (*arvore == NULL) return ARVORE_NULA;

    if ((*arvore)->id == id) {
        (*arvore)->elemento = *elemento;
    	sucesso = ARVORE_SUCESSO;
    }

    if (sucesso != ARVORE_SUCESSO && (*arvore)->esquerda != NULL) {
    	sucesso = arvore_alterar_elemento(&(*arvore)->esquerda, elemento, id);
    }

    if (sucesso != ARVORE_SUCESSO && (*arvore)->direita != NULL) {
    	sucesso = arvore_alterar_elemento(&(*arvore)->direita, elemento, id);
    }

    return sucesso;
}

Arvore* arvore_localizar_sub_arvore_esquerda(Arvore **arvore, int id) {
    Nodo *nodo = NULL;

    nodo = arvore_localizar_nodo(*arvore, id);

    if (nodo == NULL) return nodo;

    return nodo->esquerda;
}

Arvore* arvore_localizar_sub_arvore_direita(Arvore **arvore, int id) {
    Nodo *nodo = NULL;

    nodo = arvore_localizar_nodo(*arvore, id);

    if (nodo == NULL) return nodo;

    return nodo->direita;
}

int arvore_localizar_id_raiz(Arvore **arvore) {
	if (*arvore == NULL) return ARVORE_NULA;

    return (*arvore)->id;
}

int arvore_verificar_quantidade_nodos(Arvore **arvore, int quantidade) {
    if (*arvore == NULL) return ARVORE_NULA;

    quantidade++;

    if ((*arvore)->esquerda != NULL) {
        quantidade = arvore_verificar_quantidade_nodos(&(*arvore)->esquerda, quantidade);
    }

    if ((*arvore)->direita != NULL) {
        quantidade = arvore_verificar_quantidade_nodos(&(*arvore)->direita, quantidade);
    }

    return quantidade;
}
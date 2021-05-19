#include <stdlib.h>
#include "arvore.h"

typedef struct Arvore Nodo;
struct Arvore
{
    int chave;
    Elemento elemento;
    Nodo *esquerda;
    Nodo *direita;
};

Nodo *arvore_localizar_nodo(Arvore **arvore, int chave);
Nodo *arvore_localizar_pai(Arvore **arvore, int chave);

void arvore_inicializar(Arvore **arvore)
{
    *arvore = NULL;
}

void arvore_liberar(Arvore **arvore)
{
    if (*arvore == NULL) return;

    arvore_liberar(&(*arvore)->esquerda);
    arvore_liberar(&(*arvore)->direita);

    free(*arvore);
}

int arvore_obter_quantidade_nodo(Arvore **arvore)
{
    int tamanho = 0;

    if (*arvore != NULL)
    {
        tamanho++;
        tamanho += arvore_obter_quantidade_nodo(&(*arvore)->esquerda);
        tamanho += arvore_obter_quantidade_nodo(&(*arvore)->direita);
    }

    return tamanho;
}

int arvore_vazia(Arvore **arvore)
{
    return *arvore == NULL;
}

Nodo *arvore_localizar_nodo(Arvore **arvore, int chave)
{
    Nodo *esquerda = NULL, *direita = NULL;

    if ((*arvore)->chave == chave) return *arvore;

    if ((*arvore)->esquerda != NULL)
    {
        esquerda = arvore_localizar_nodo(&(*arvore)->esquerda, chave);
    }

    if (esquerda == NULL)
    {
        if ((*arvore)->direita != NULL)
        {
            direita = arvore_localizar_nodo(&(*arvore)->direita, chave);
        }
        return direita;
    }

    return esquerda;
}

Nodo *arvore_localizar_pai(Arvore **arvore, int chave)
{
    Nodo *pai = NULL;

    if ((*arvore)->chave == chave) return pai;

    if ((*arvore)->esquerda != NULL)
    {
        if ((*arvore)->esquerda->chave == chave)
        {
            return *arvore;
        }
        else
        {
            pai = arvore_localizar_nodo(&(*arvore)->esquerda, chave);
        }
    }

    if (pai == NULL)
    {
        if ((*arvore)->direita != NULL)
        {
            if ((*arvore)->direita->chave == chave)
            {
                return *arvore;
            }
            else
            {
                pai = arvore_localizar_nodo(&(*arvore)->direita, chave);
            }
        }
    }

    return pai;
}

int arvore_criar_raiz(Arvore **arvore, Elemento *elemento, int chave)
{
    if (*arvore != NULL) return ARVORE_NODO_OCUPADO;

    *arvore = malloc(sizeof **arvore);

    if (*arvore == NULL) return ARVORE_SEM_MEMORIA;

    (*arvore)->chave = chave;
    (*arvore)->elemento = *elemento;
    (*arvore)->esquerda = NULL;
    (*arvore)->direita = NULL;

    return ARVORE_SUCESSO;
}

int arvore_adicionar_esquerda(Arvore **arvore, int chave_pai, Elemento *elemento, int chave_filho)
{
    Nodo *pai = NULL, *filho = NULL;

    if (*arvore == NULL) return ARVORE_NULA;

    pai = arvore_localizar_nodo(arvore, chave_pai);

    if (pai == NULL) return ARVORE_CHAVE_INVALIDA;

    if (pai->esquerda != NULL) return ARVORE_NODO_OCUPADO;

    filho = malloc(sizeof *filho);

    if (filho == NULL) return ARVORE_SEM_MEMORIA;

    filho->chave = chave_filho;
    filho->elemento = *elemento;
    filho->esquerda = NULL;
    filho->direita = NULL;
    pai->esquerda = filho;

    return ARVORE_SUCESSO;
}

int arvore_adicionar_direita(Arvore **arvore, int chave_pai, Elemento *elemento, int chave_filho)
{
    Nodo *pai = NULL, *filho = NULL;

    if (*arvore == NULL) return ARVORE_NULA;

    pai = arvore_localizar_nodo(arvore, chave_pai);

    if (pai == NULL) return ARVORE_CHAVE_INVALIDA;

    if (pai->direita != NULL) return ARVORE_NODO_OCUPADO;

    filho = malloc(sizeof *filho);

    if (filho == NULL) return ARVORE_SEM_MEMORIA;

    filho->chave = chave_filho;
    filho->elemento = *elemento;
    filho->esquerda = NULL;
    filho->direita = NULL;
    pai->direita = filho;

    return ARVORE_SUCESSO;
}

int arvore_remover(Arvore **arvore, Elemento *elemento, int chave)
{
    Nodo *pai = NULL;

    if (*arvore == NULL) return ARVORE_NULA;

    if ((*arvore)->chave == chave)
    {
        arvore_liberar(arvore);
        *arvore = NULL;
    }
    else
    {
        Nodo *nodo = NULL;

        nodo = arvore_localizar_pai(arvore, chave);

        if (nodo == NULL) return ARVORE_CHAVE_INVALIDA;

        if (nodo->esquerda->chave == chave)
        {
            arvore_liberar(&(*arvore)->esquerda);
            (*arvore)->esquerda = NULL;
        }

        if (nodo->direita->chave == chave)
        {
            arvore_liberar(&(*arvore)->direita);
            (*arvore)->direita = NULL;
        }
    }

    return ARVORE_SUCESSO;
}

int arvore_alterar(Arvore **arvore, Elemento *elemento, int chave)
{
    Nodo *nodo = arvore_localizar_nodo(arvore, chave);

    if (nodo == NULL) return ARVORE_CHAVE_INVALIDA;

    nodo->elemento = *elemento;

    return ARVORE_SUCESSO;
}

int arvore_obter(Arvore **arvore, Elemento *elemento, int chave)
{
    Nodo *nodo = arvore_localizar_nodo(arvore, chave);

    if (nodo == NULL) return ARVORE_CHAVE_INVALIDA;

    *elemento = nodo->elemento;

    return ARVORE_SUCESSO;
}
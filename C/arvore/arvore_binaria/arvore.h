#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

enum
{
    ARVORE_SUCESSO,
    ARVORE_NULA,
    ARVORE_SEM_MEMORIA,
    ARVORE_CHAVE_INVALIDA,
    ARVORE_NODO_OCUPADO
};

struct Elemento
{
    int x;
};
typedef struct Elemento Elemento;

typedef struct Arvore Arvore;

void arvore_inicializar(Arvore **arvore);
void arvore_liberar(Arvore **arvore);

int arvore_obter_quantidade_nodo(Arvore **arvore);
int arvore_vazia(Arvore **arvore);

int arvore_criar_raiz(Arvore **arvore, Elemento *elemento, int chave);
int arvore_adicionar_esquerda(Arvore **arvore, int chave_pai, Elemento *elemento, int chave_filho);
int arvore_adicionar_direita(Arvore **arvore, int chave_pai, Elemento *elemento, int chave_filho);

int arvore_remover(Arvore **arvore, Elemento *elemento, int chave);

int arvore_alterar(Arvore **arvore, Elemento *elemento, int chave);
int arvore_obter(Arvore **arvore, Elemento *elemento, int chave);

#endif
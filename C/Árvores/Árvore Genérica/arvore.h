#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#define ARVORE_SUCESSO 0
#define ARVORE_NULA -1
#define ARVORE_ID_INEXISTENTE -2
#define ARVORE_SEM_MEMORIA -3
#define ARVORE_ELEMENTO_INVALIDO -4

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Nodo Arvore;

int arvore_criar_arvore(Arvore **arvore, Elemento *elemento, int id);
int arvore_liberar_arvore(Arvore **arvore);
int arvore_adicionar_elemento(Arvore **arvore, int id_pai, int id_filho, Elemento *elemento);
int arvore_localizar_elemento(Arvore **arvore, Elemento *elemento, int id);
int arvore_alterar_elemento(Arvore **arvore, Elemento *elemento, int id);
Arvore* arvore_localizar_sub_arvore_esquerda(Arvore **arvore, int id);
Arvore* arvore_localizar_sub_arvore_direita(Arvore **arvore, int id);
int arvore_localizar_id_raiz(Arvore **arvore);
int arvore_verificar_quantidade_nodos(Arvore **arvore, int quantidade);

#endif
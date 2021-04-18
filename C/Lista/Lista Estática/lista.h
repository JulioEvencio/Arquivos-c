#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define LISTA_SUCESSO 0
#define LISTA_SEM_MEMORIA -1
#define LISTA_VAZIA -2
#define LISTA_CHEIA -3
#define LISTA_POSICAO_INEXISTENTE -4
#define LISTA_TAMANHO_INVALIDO -5

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Lista Lista;

int lista_inicializar(Lista **lista, int tamanho);
void lista_liberar(Lista **lista);

int lista_obter_tamanho(Lista **lista);
int lista_esta_vazia(Lista **lista);
int lista_esta_cheia(Lista **lista);

int lista_adicionar_elemento_inicio(Lista **lista, Elemento *elemento);
int lista_adicionar_elemento_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_adicionar_elemento_final(Lista **lista, Elemento *elemento);

int lista_remover_elemento_inicio(Lista **lista);
int lista_remover_elemento_posicao(Lista **lista, int posicao);
int lista_remover_elemento_final(Lista **lista);

int lista_alterar_elemento_inicio(Lista **lista, Elemento *elemento);
int lista_alterar_elemento_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_alterar_elemento_final(Lista **lista, Elemento *elemento);

int lista_obter_elemento_inicio(Lista **lista, Elemento *elemento);
int lista_obter_elemento_posicao(Lista **lista, Elemento *elemento, int posicao);
int lista_obter_elemento_final(Lista **lista, Elemento *elemento);

#endif
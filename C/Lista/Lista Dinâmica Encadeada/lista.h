#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define LISTA_SUCESSO 0
#define LISTA_SEM_MEMORIA -1
#define LISTA_VAZIA -2
#define LISTA_POSICAO_INEXISTENTE -3

struct Elemento {
    int x;
};
typedef struct Elemento Elemento;

typedef struct Nodo Lista;

void lista_inicializar(Lista **lista);
int lista_obter_tamanho(Lista **lista);
int lista_esta_vazia(Lista **lista);

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

void lista_formatar(Lista **lista);

#endif
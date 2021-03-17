#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*  Constantes */
#define PILHA_SUCESSO 0
#define PILHA_ENDERECO_INVALIDO -1
#define PILHA_PILHA_CHEIA -2
#define PILHA_POSICAO_INEXISTENTE -3

/*  Estruturas */
typedef struct Tipoo_Nodo Nodo;
struct Tipo_Nodo
{
    Elemento elemento;
    Nodo *prox;
};

struct Tipo_Pilha
{
    int tamanho;
    Nodo *inicio;
};
typedef struct Tipo_Pilha Pilha;

/*  Funcoes */
int FILA_InicialiarPilha(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    pilha->inicio = NULL;
    pilha->tamanho = 0;
    return PILHA_SUCESSO;
}



#endif
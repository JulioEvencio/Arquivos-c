#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define FILA_SUCESSO 0
#define FILA_ENDERECO_INVALIDO -1
#define FILA_FILA_CHEIA -2
#define FILA_FILA_VAZIA -3
#define FILA_POSICAO_INEXISTENTE -4

typedef struct Tipo_Nodo Nodo;
struct Tipo_Nodo
{
    Elemento elemento;
    Nodo *prox;
};

struct Tipo_Fila
{
    Nodo *inicio;
    Nodo *fim;
};
typedef struct Tipo_Fila Fila;

int FILA_InicializarFila(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    fila->inicio = NULL;
    fila->fim = NULL;
    return FILA_SUCESSO;
}

int FILA_VerificarFilaTamanho(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    int tamanho = 0;
    Nodo *nodo = fila->inicio;
    while(nodo != NULL)
    {
        nodo = nodo->prox;
        tamanho++;
    }
    return tamanho;
}

#endif
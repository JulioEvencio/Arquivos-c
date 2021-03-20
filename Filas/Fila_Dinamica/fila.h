#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define FILA_SUCESSO 0
#define FILA_ENDERECO_INVALIDO -1
#define FILA_CHEIA -2
#define FILA_VAZIA -3
#define FILA_POSICAO_INEXISTENTE -4

typedef struct Fila_Nodo Nodo;
struct Fila_Nodo
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

int FILA_VerificarFilaCheia(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    int fila_cheia;
    Nodo *nodo = malloc(sizeof(nodo));
    if(nodo == NULL) fila_cheia = 1;
    else
    {
        fila_cheia = 0;
        free(nodo);
    }
    return fila_cheia;
}

int FILA_VerificarFilaVazia(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    return fila->inicio == NULL;
}

int FILA_InserirElemento(Fila *fila, Elemento elemento)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    Nodo *nodo = malloc(sizeof(nodo));
    if(nodo == NULL) return FILA_CHEIA;
    nodo->elemento = elemento;
    nodo->prox = NULL;
    if(fila->inicio == NULL) fila->inicio = nodo;
    if(fila->fim != NULL) fila->fim->prox = nodo;
    fila->fim = nodo;
    return FILA_SUCESSO;
}

int FILA_RemoverElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return FILA_ENDERECO_INVALIDO;
    if(fila->inicio == NULL) return FILA_VAZIA;
    Nodo *nodo = fila->inicio;
    fila->inicio = fila->inicio->prox;
    *elemento = nodo->elemento;
    free(nodo);
    if(fila->inicio == NULL) fila->fim = NULL;
    return FILA_SUCESSO;
}

int FILA_ObterElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return FILA_ENDERECO_INVALIDO;
    if(fila->inicio == NULL) return FILA_VAZIA;
    *elemento = fila->inicio->elemento;
    return FILA_SUCESSO;
}

int FILA_FormatarFila(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    Nodo *nodo;
    while(fila->inicio != NULL)
    {
        nodo = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(nodo);
    }
    fila->fim = NULL;
    return FILA_SUCESSO;
}

#endif
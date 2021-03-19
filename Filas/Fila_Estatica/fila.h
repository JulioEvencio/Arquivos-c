#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/*  Constantes */
#define FILA_SUCESSO 0
#define FILA_ENDERECO_INVALIDO -1
#define FILA_FILA_CHEIA -2
#define FILA_FILA_VAZIA -3
#define FILA_POSICAO_INEXISTENTE -4
#define FILA_TAMANHO_INVALIDO -5

/*  Estruturas */
struct Tipo_Fila
{
    int tamanho;
    int tamanho_max;
    int inicio;
    int fim;
    Elemento *elemento;
};
typedef struct Tipo_Fila Fila;

/*  Funcoes */
int FILA_InicializarFila(Fila *fila, int tamanho)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    if(tamanho < 1) return FILA_TAMANHO_INVALIDO;
    fila->elemento = malloc(sizeof(fila->elemento));
    if(fila->elemento == NULL) return FILA_FILA_CHEIA;
    fila->tamanho = 0;
    fila->tamanho_max = tamanho;
    fila->inicio = 0;
    fila->fim = 0;
    return FILA_SUCESSO;
}

int FILA_LiberarFila(Fila *fila)
{
    if(fila == NULL || fila->elemento == NULL) return FILA_ENDERECO_INVALIDO;
    free(fila->elemento);
    return FILA_SUCESSO;
}

int FILA_VerificarFilaTamanho(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    return fila->tamanho;
}

int FILA_VerificarFilaCheia(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    return fila->tamanho == fila->tamanho_max;
}

int FILA_VerificarFilaVazia(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    return fila->tamanho == 0;
}

int FILA_IncluirElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaCheia(fila)) return FILA_FILA_CHEIA;
    fila->elemento[fila->fim] = *elemento;
    fila->fim = (fila->fim + 1) % fila->tamanho_max;
    fila->tamanho++;
    return FILA_SUCESSO;
}

int FILA_RemoverElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaVazia(fila)) return FILA_FILA_VAZIA;
    *elemento = fila->elemento[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho_max;
    fila->tamanho++;
    return FILA_SUCESSO;
}

int FILA_ObterElementoInicio(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaVazia(fila)) return FILA_FILA_VAZIA;
    *elemento = fila->elemento[fila->inicio];
    return FILA_SUCESSO;
}

#endif

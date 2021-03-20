#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

/*  Constantes */
#define FILA_SUCESSO 0
#define FILA_ENDERECO_INVALIDO -1
#define FILA_CHEIA -2
#define FILA_VAZIA -3
#define FILA_TAMANHO_INVALIDO -4
#define FILA_SEM_MEMORIA -5

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
    fila->tamanho = 0;
    fila->tamanho_max = tamanho;
    fila->inicio = 0;
    fila->fim = 0;
    fila->elemento = malloc(sizeof(fila->elemento) * fila->tamanho_max);
    if(fila->elemento == NULL) return FILA_SEM_MEMORIA;
    return FILA_SUCESSO;
}

int FILA_LiberarFila(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    if(fila->elemento != NULL) free(fila->elemento);
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

int FILA_InserirElemento(Fila *fila, Elemento elemento)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaCheia(fila)) return FILA_CHEIA;
    fila->elemento[fila->fim] = elemento;
    fila->fim = (fila->fim + 1) % fila->tamanho_max;
    fila->tamanho++;
    return FILA_SUCESSO;
}

int FILA_RemoverElemento(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaVazia(fila)) return FILA_VAZIA;
    *elemento = fila->elemento[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->tamanho_max;
    fila->tamanho--;
    return FILA_SUCESSO;
}

int FILA_ObterElementoInicio(Fila *fila, Elemento *elemento)
{
    if(fila == NULL || elemento == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaVazia(fila)) return FILA_VAZIA;
    *elemento = fila->elemento[fila->inicio];
    return FILA_SUCESSO;
}

int FILA_FormatarFila(Fila *fila)
{
    if(fila == NULL) return FILA_ENDERECO_INVALIDO;
    if(FILA_VerificarFilaVazia(fila)) return FILA_VAZIA;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;
    return FILA_SUCESSO;
}

#endif

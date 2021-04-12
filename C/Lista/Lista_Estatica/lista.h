#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*  Constantes */
#define LISTA_SUCESSO 0
#define LISTA_ENDERECO_INVALIDO -1
#define LISTA_CHEIA -2
#define LISTA_VAZIA -3
#define LISTA_POSICAO_INEXISTENTE -4
#define LISTA_TAMANHO_INVALIDO -5
#define LISTA_SEM_MEMORIA -6

/*  Estruturas */
struct Tipo_Lista
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};
typedef struct Tipo_Lista Lista;

/*  Funcoes */
int LISTA_InicializarLista(Lista *lista, int tamanho_max)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(tamanho_max < 1) return LISTA_TAMANHO_INVALIDO;
    lista->tamanho = 0;
    lista->tamanho_max = tamanho_max;
    lista->elemento = malloc(sizeof(lista->elemento) * lista->tamanho_max);
    if(lista->elemento == NULL) return LISTA_SEM_MEMORIA;
    return LISTA_SUCESSO;
}

int LISTA_LiberarLista(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->elemento != NULL) free(lista->elemento);
    return LISTA_SUCESSO;
}

int LISTA_VerificarListaTamanho(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->tamanho;
}

int LISTA_VerificarListaCheia(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->tamanho == lista->tamanho_max;
}

int LISTA_VerificarListaVazia(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->tamanho == 0;
}

int LISTA_InserirElementoInicio(Lista *lista, Elemento elemento)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == lista->tamanho_max) return LISTA_CHEIA;
    for(int i = lista->tamanho; i > 0; i--)
    {
        lista->elemento[i] = lista->elemento[i - 1];
    }
    lista->elemento[0] = elemento;
    lista->tamanho++;
    return LISTA_SUCESSO;
}

int LISTA_InserirElementoPosicao(Lista *lista, Elemento elemento, int posicao)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == lista->tamanho_max) return LISTA_CHEIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    for(int i = lista->tamanho; i > (posicao - 1); i--)
    {
        lista->elemento[i] = lista->elemento[i - 1];
    }
    lista->elemento[posicao - 1] = elemento;
    lista->tamanho++;
    return LISTA_SUCESSO;
}

int LISTA_InserirElementoFinal(Lista *lista, Elemento elemento)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == lista->tamanho_max) return LISTA_CHEIA;
    lista->elemento[lista->tamanho] = elemento;
    lista->tamanho++;
    return LISTA_SUCESSO;
}

int LISTA_RemoverElementoInicio(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    for(int i = 0; i < lista->tamanho; i++)
    {
        lista->elemento[i] = lista->elemento[i + 1];
    }
    lista->tamanho--;
    return LISTA_SUCESSO;
}

int LISTA_RemoverElementoPosicao(Lista *lista, int posicao)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    for(int i = (posicao - 1); i < lista->tamanho; i++)
    {
        lista->elemento[i] = lista->elemento[i + 1];
    }
    lista->tamanho--;
    return LISTA_SUCESSO;
}

int LISTA_RemoverElementoFinal(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    lista->tamanho--;
    return LISTA_SUCESSO;
}

int LISTA_AlterarElementoInicio(Lista *lista, Elemento elemento)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    lista->elemento[0] = elemento;
    return LISTA_SUCESSO;
}

int LISTA_AlterarElementoPosicao(Lista *lista, Elemento elemento, int posicao)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    lista->elemento[posicao - 1] = elemento;
    return LISTA_SUCESSO;
}

int LISTA_AlterarElementoFinal(Lista *lista, Elemento elemento)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    lista->elemento[lista->tamanho - 1] = elemento;
    return LISTA_SUCESSO;
}

int LISTA_ObterElementoInicio(Lista *lista, Elemento *elemento)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    *elemento = lista->elemento[0];
    return LISTA_SUCESSO;
}

int LISTA_ObterElementoPosicao(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    if(posicao < 1 || posicao > lista->tamanho) return LISTA_POSICAO_INEXISTENTE;
    *elemento = lista->elemento[posicao - 1];
    return LISTA_SUCESSO;
}

int LISTA_ObterElementoFinal(Lista *lista, Elemento *elemento)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(lista->tamanho == 0) return LISTA_VAZIA;
    *elemento = lista->elemento[lista->tamanho - 1];
    return LISTA_SUCESSO;
}

int LISTA_FormatarLista(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    lista->tamanho = 0;
    return LISTA_SUCESSO;
}

#endif
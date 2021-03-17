#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*  Constantes */
#define LISTA_SUCESSO 0
#define LISTA_ENDERECO_INVALIDO -1
#define LISTA_LISTA_CHEIA -2
#define LISTA_LISTA_VAZIA -3
#define LISTA_POSICAO_INEXISTENTE -4

/*  Estruturas */
typedef struct Tipo_Nodo Nodo;
struct Tipo_Nodo
{
    Elemento elemento;
    Nodo *prox;
};

struct Tipo_Lista
{
    Nodo *inicio;
};
typedef struct Tipo_Lista Lista;

/*  Funcoes */
int LISTA_InicializarLista(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    lista->inicio = NULL;
    return LISTA_SUCESSO;
}

int LISTA_VerificarListaTamanho(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    int tamanho = 0;
    Nodo *nodo = lista->inicio;
    while(nodo != NULL)
    {
        nodo = nodo->prox;
        tamanho++;
    }
    return tamanho;
}

int LISTA_VerificarListaCheia(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    int listaCheia;
    Nodo *nodo = malloc(sizeof(Nodo));
    if(nodo == NULL)
    {
        listaCheia = 1;
    }
    else
    {
        listaCheia = 0;
    }
    free(nodo);
    return listaCheia;
}

int LISTA_VerificarListaVazia(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    return lista->inicio == NULL;
}

int LISTA_IncluirElemento(Lista *lista, Elemento *elemento)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaCheia(lista)) return LISTA_LISTA_CHEIA;
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->elemento = *elemento;
    nodo->prox = lista->inicio;
    lista->inicio = nodo;
    return LISTA_SUCESSO;
}

int LISTA_ExcluirElemento(Lista *lista, int posicao)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaVazia(lista)) return LISTA_LISTA_VAZIA;
    if(posicao < 1 || posicao > LISTA_VerificarListaTamanho(lista)) return LISTA_POSICAO_INEXISTENTE;
    Nodo *nodo_atual = lista->inicio;
    if(posicao == 1)
    {
        lista->inicio = lista->inicio->prox;
        free(nodo_atual);
    }
    else
    {
        Nodo *nodo_anterior;
        for(int i = 1; i < posicao; i++)
        {
            nodo_anterior = nodo_atual;
            nodo_atual = nodo_atual->prox;
        }
        nodo_anterior->prox = nodo_atual->prox;
        free(nodo_atual);
    }
    return LISTA_SUCESSO;
}

int LISTA_AlterarElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaVazia(lista)) return LISTA_LISTA_VAZIA;
    if(posicao < 1 || posicao > LISTA_VerificarListaTamanho(lista)) return LISTA_POSICAO_INEXISTENTE;
    Nodo *nodo = lista->inicio;
    for(int i = 1; i < posicao; i++)
    {
        nodo = nodo->prox;
    }
    nodo->elemento = *elemento;
    return LISTA_SUCESSO;
}

int LISTA_ObterElemento(Lista *lista, Elemento *elemento, int posicao)
{
    if(lista == NULL || elemento == NULL) return LISTA_ENDERECO_INVALIDO;
    if(LISTA_VerificarListaVazia(lista)) return LISTA_LISTA_VAZIA;
    if(posicao < 1 || posicao > LISTA_VerificarListaTamanho(lista)) return LISTA_POSICAO_INEXISTENTE;
    Nodo *nodo = lista->inicio;
    for(int i = 1; i < posicao; i++)
    {
        nodo = nodo->prox;
    }
    *elemento = nodo->elemento;
    return LISTA_SUCESSO;
}

int LISTA_FormatarLista(Lista *lista)
{
    if(lista == NULL) return LISTA_ENDERECO_INVALIDO;
    Nodo *nodo;
    while(lista->inicio != NULL)
    {
        nodo = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(nodo);
    }
    return LISTA_SUCESSO;
}

#endif
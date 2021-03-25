#include "pilha.h"

/*  Estruturas */
struct Tipo_Pilha
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};

/*  Funcoes*/
int PILHA_InicializarPilha(Pilha **pilha, int tamanho)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    if(tamanho < 1) return PILHA_TAMANHO_INVALIDO;
    *pilha = malloc(sizeof(*pilha));
    if(pilha == NULL) return PILHA_SEM_MEMORIA;
    (*pilha)->tamanho = 0;
    (*pilha)->tamanho_max = tamanho;
    (*pilha)->elemento = malloc(sizeof((*pilha)->elemento) * (*pilha)->tamanho_max);
    if((*pilha)->elemento == NULL) return PILHA_SEM_MEMORIA;
    return PILHA_SUCESSO;
}

int PILHA_LiberarPilha(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    if(pilha->elemento != NULL) free(pilha->elemento);
    free(pilha);
    return PILHA_SUCESSO;
}

int PILHA_VerificarPilhaTamanho(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    return pilha->tamanho;
}

int PILHA_VerificarPilhaCheia(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    return pilha->tamanho == pilha->tamanho_max;
}

int PILHA_VerificarPilhaVazia(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    return pilha->tamanho == 0;
}

int PILHA_EmpilharElemento(Pilha *pilha, Elemento elemento)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    if(PILHA_VerificarPilhaCheia(pilha)) return PILHA_CHEIA;
    pilha->elemento[pilha->tamanho] = elemento;
    pilha->tamanho++;
    return PILHA_SUCESSO;
}

int PILHA_DesempilharElemento(Pilha *pilha, Elemento *elemento)
{
    if(pilha == NULL || elemento == NULL) return PILHA_ENDERECO_INVALIDO;
    pilha->tamanho--;
    *elemento = pilha->elemento[pilha->tamanho];
    return PILHA_SUCESSO;
}

int PILHA_ObterElemento(Pilha *pilha, Elemento *elemento)
{
    if(pilha == NULL || elemento == NULL) return PILHA_ENDERECO_INVALIDO;
    *elemento = pilha->elemento[pilha->tamanho - 1];
    return PILHA_SUCESSO;
}

int PILHA_FormatarPilha(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    pilha->tamanho = 0;
    return PILHA_SUCESSO;
}
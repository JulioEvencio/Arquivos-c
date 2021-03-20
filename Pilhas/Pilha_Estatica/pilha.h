#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/*  Constantes */
#define PILHA_SUCESSO 0
#define PILHA_ENDERECO_INVALIDO -1
#define PILHA_CHEIA -2
#define PILHA_VAZIA -3
#define PILHA_POSICAO_INEXISTENTE -4
#define PILHA_TAMANHO_INVALIDO -5

/*  Estruturas */
struct Tipo_Pilha
{
    int tamanho;
    int tamanho_max;
    Elemento *elemento;
};
typedef struct Tipo_Pilha Pilha;

/*  Funcoes*/
int PILHA_InicializarPilha(Pilha *pilha, int tamanho)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    if(tamanho < 1) return PILHA_TAMANHO_INVALIDO;
    pilha->tamanho = 0;
    pilha->tamanho_max = tamanho;
    pilha->elemento = malloc(sizeof(pilha->elemento) * pilha->tamanho_max);
    if(pilha->elemento == NULL) return PILHA_CHEIA;
    return PILHA_SUCESSO;
}

int PILHA_LiberarPilha(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_ENDERECO_INVALIDO;
    if(pilha->elemento != NULL) free(pilha->elemento);
    return PILHA_SUCESSO;
}

int PILHA_VerificarPilhaTamanho(Pilha *pilha)
{
    if(pilha == NULL) return PILHA_TAMANHO_INVALIDO;
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

int PILHA_EmpilharElemento(Pilha *pilha, Elemento *elemento)
{
    if(pilha == NULL || elemento == NULL) return PILHA_ENDERECO_INVALIDO;
    if(PILHA_VerificarPilhaCheia(pilha)) return PILHA_CHEIA;
    pilha->elemento[pilha->tamanho] = *elemento;
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

#endif
#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED
#include "tad_lista.h"

/*  Constantes */
#define LIMPAR_TELA "clear"

/*  Enum */
enum enum_menu
{
    opcao_sair,
    opcao_listar,
    opcao_incluir,
    opcao_alterar,
    opcao_excluir,
    opcao_gravar
};

/*  Funcoes */
void limpar_buffer(void);
void ler_string(char *nome, int tamanho);
void printar_menu(void);
void listar_lista(Lista *lista);
void incluir_cliente(Lista *lista);
void alterar_cliente(Lista *lista);
void excluir_cliente(Lista *lista);

#endif
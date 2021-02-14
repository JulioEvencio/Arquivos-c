#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED
#include "tad_lista.h"

/*  Constantes */
#define LIMPAR_TELA "clear"
#define ARGUMENTOS_DO_PROGRAMA 2
#define INDICE_ARQUIVO 1
#define ARQUIVO_MODO_LEITURA "r"
#define ARQUIVO_MODO_EDICAO "w"

/*  Enum */
enum enum_menu
{
    opcao_sair,
    opcao_listar,
    opcao_incluir,
    opcao_alterar,
    opcao_excluir,
    opcao_gravar,
    opcao_formatar
};

/*  Funcoes */
void limpar_buffer(void);
void ler_string(char *nome, int tamanho);
void printar_menu(void);
void listar_lista(Lista *lista);
void incluir_cliente(Lista *lista);
void alterar_cliente(Lista *lista);
void excluir_cliente(Lista *lista);
void gravar_lista(Lista *lista, char *arquivo);
void carregar_lista(Lista *lista, char *arquivo);
void formatar_lista(Lista *lista);

#endif
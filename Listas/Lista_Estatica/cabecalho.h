#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED
#include "tad_lista.h"

/*  Constantes */
#define LIMPAR_TELA "clear"
//  Menu
#define OPCAO_SAIR 0
#define OPCAO_LISTAR 1
#define OPCAO_INCLUIR 2
#define OPCAO_ALTERAR 3
#define OPCAO_EXCLUIR 4
#define OPCAO_GRAVAR_LISTA 5

/*  Funcoes */
void limpar_buffer(void);
void ler_string(char *nome, int tamanho);
void printar_menu(void);
void listar_lista(Lista *lista);
void incluir_cliente(Lista *lista);
void alterar_cliente(Lista *lista);
void excluir_cliente(Lista *lista);

#endif
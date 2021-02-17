#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLDUED

#include "tad_fila.h"

/*  Constantes */
#define NUMERO_FILA 4
#define NUMERO_PACOTES 10
#define NUMERO_CLIENTES 3
#define NOME_PACOTE "pkt"
#define LIMPAR_TELA "clear"
#define FILA_PROCESSADOR 3

/*  Typedef */
typedef Elemento Pacote;

/*  Funcoes */
void delay(int delay);
void processar_similacao(Fila **fila);
void criar_pacote(Pacote *pacote);
void colocar_fila(Fila *fila);
void enviar_processador(Fila *fila_cliente, Fila *fila_processador);
void remover_processador(Fila *fila_processador);
void montar_tela(Fila **fila);

#endif
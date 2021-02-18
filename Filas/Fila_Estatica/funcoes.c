#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

/*  Funcoes */
void delay(int delay)
{
    for(int i = 0; i < delay; i++)
    {
        for(int j = 0; j < delay; j++)
        {
            /* Delay */
        }
    }
}

void processar_similacao(Fila **fila)
{
    int numero_aleatorio = rand() % NUMERO_PACOTES;
    if(numero_aleatorio >= 0 && numero_aleatorio <= 2)
    {
        colocar_fila(fila[numero_aleatorio]);
    }
    else if(numero_aleatorio >= 3 && numero_aleatorio <= 5)
    {
        enviar_processador(fila[numero_aleatorio - 3], fila[FILA_PROCESSADOR]);
    }
    else if(numero_aleatorio >= 6 && numero_aleatorio <= 10)
    {
        remover_processador(fila[FILA_PROCESSADOR]);
    }
    montar_tela(fila);
}

void criar_pacote(Pacote *pacote)
{
    static int contador = 0;
    pacote->numero = ++contador;
    stpcpy(pacote->nome, NOME_PACOTE);
}

void colocar_fila(Fila *fila)
{
    Pacote pacote;
    criar_pacote(&pacote);
    if(!(TAD_VerificarFilaCheia(fila)))
    {
        TAD_IncluirElemento(fila, &pacote);
    }
}

void enviar_processador(Fila *fila_cliente, Fila *fila_processador)
{
    Pacote pacote;
    TAD_ObterElementoInicio(fila_cliente, &pacote);
    TAD_ExcluirElemento(fila_cliente);
    TAD_IncluirElemento(fila_processador, &pacote);
}

void remover_processador(Fila *fila_processador)
{
    TAD_ExcluirElemento(fila_processador);
}

void montar_tela(Fila **fila)
{
    int tamanho;
    Pacote pacote;
    system(LIMPAR_TELA);
    for(int i = 0; i < NUMERO_FILA; i++)
    {
        if(i <= NUMERO_CLIENTES)
        {
            printf("\n\nCLIENTE %d: \n\n", i + 1);
        }
        else
        {
            printf("\n\n\nSERVIDOR (processando)... : \n\n");
        }
        if((tamanho = TAD_VerificarFilaTamanho(fila[i])) > 0)
        {
            for(int j = 0; j < tamanho; j++)
            {
                TAD_ObterElementoInicio(fila[i], &pacote);
                printf("|%s - %d|  ", pacote.nome, pacote.numero);
                TAD_ExcluirElemento(fila[i]);
                TAD_IncluirElemento(fila[i], &pacote);
            }
        }
        else
        {
            printf("|  vazia  |");
        }
    }
    printf("\n\n...............................................");
    delay(10000);
}
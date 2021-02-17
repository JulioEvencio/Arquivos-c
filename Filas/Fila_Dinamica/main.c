#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecalho.h"

int main(void)
{
    int loop = 1;
    Fila *fila[NUMERO_FILA];

    srand(time(NULL));

    for(int i = 0; i < NUMERO_FILA; i++)
    {
        fila[i] = TAD_CriarFila();
        if(fila[i] == NULL)
        {
            puts("Erro ao criar fila");
            return 1;
        }
    }

    while(loop)
    {
        system(LIMPAR_TELA);
        printf("SIMULACAO DO ENVIO DE PACOTES EM UMA REDE DO TIPO \n");
        printf("CLIENTE/SERVIDOR UTILIZANDO A ESTRUTURA DE DADOS FILA \n\n\n");
        processar_similacao(fila);
    }

    for(int i = 0; i < NUMERO_FILA; i++)
    {
        TAD_LiberarFila(fila[i]);
    }

    return 0;
}
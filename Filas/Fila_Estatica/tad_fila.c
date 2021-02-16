#include <stdlib.h>
#include "tad_fila.h"

/*  Constantes */
#define _TAD_LISTA_INICIO 0
#define _TAD_LISTA_FINAL 0
#define _TAD_LISTA_TAMANHO_INICIO 0

/*  Estruturas */
struct tipo_fila
{
    int tamanho;
    int inicio;
    int final;
    Elemento elemento[TAD_FILA_TAMANHO_MAX];
};

/*  Funcoes */
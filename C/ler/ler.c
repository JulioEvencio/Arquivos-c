#include <stdio.h>
#include <stdlib.h>
#include "ler.h"

enum Enum_Buffer {
    BUFFER_INT = 10,
    BUFFER_FLOAT = 50
};

int ler_int(int *numero) {
    char buffer[BUFFER_INT];

    if (ler_string(buffer, BUFFER_INT)) return LER_INT_ERRO;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            if (i == 0 && buffer[i] == '-') continue;
            else return LER_INT_ERRO;
        }
    }

    *numero = atoi(buffer);

    return LER_SUCESSO;
}

int ler_float(float *numero) {
    int ponto = 1;
    char buffer[BUFFER_FLOAT];

    if (ler_string(buffer, BUFFER_FLOAT)) return LER_FLOAT_ERRO;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            if (i == 0 && buffer[i] == '-') continue;
            else if (buffer[i] == '.' && ponto) ponto--;
            else return LER_FLOAT_ERRO;
        }
    }

    *numero = atof(buffer);

    return LER_SUCESSO;
}

int ler_char(char *caractere) {
    char letra;

    *caractere = getchar();

    if (*caractere == '\n') return LER_CHAR_ERRO;

    do {letra = getchar();} while (letra != '\n' && letra != EOF);

    return LER_SUCESSO;
}

int ler_string(char *string, int tamanho) {
    int i = 0;
    char letra;

    while (1) {
        letra = getchar();

        if (letra == '\n' || letra == EOF) break;

        if (i < tamanho - 1) *(string + i++) = letra;
    }

    *(string + i) = '\0';

    if (*string == '\0') return LER_STRING_ERRO;

    return LER_SUCESSO;
}
#ifndef LER_H_INCLUDED
#define LER_H_INCLUDED

enum Enum_Ler {
    LER_SUCESSO,
    LER_INT_ERRO,
    LER_FLOAT_ERRO,
    LER_CHAR_ERRO,
    LER_STRING_ERRO
};

int ler_int(int *numero);
int ler_float(float *numero);
int ler_char(char *caractere);
int ler_string(char *string, int tamanho);

#endif
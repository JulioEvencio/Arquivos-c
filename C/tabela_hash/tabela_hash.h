#ifndef TABELA_HASH_H_INCLUDED
#define TABELA_HASH_H_INCLUDED

struct Elemento {
    int numero;
};

enum Enum_Tabela_Hash {
    TABELA_HASH_SUCESSO,
    TABELA_HASH_SEM_MEMORIA,
    TABELA_HASH_VAZIA,
    TABELA_HASH_CHAVE_INVALIDA
};

typedef struct Tabela_Hash Tabela_Hash;
typedef struct Elemento Elemento;

int tabela_hash_criar(Tabela_Hash **tabela_hash);
void tabela_hash_liberar(Tabela_Hash **tabela_hash);

int tabela_hash_tamanho(Tabela_Hash **tabela_hash);
int tabela_hash_vazia(Tabela_Hash **tabela_hash);
int tabela_hash_contem(Tabela_Hash **tabela_hash, int chave);

int tabela_hash_adicionar(Tabela_Hash **tabela_hash, int chave, Elemento *elemento);
int tabela_hash_remover(Tabela_Hash **tabela_hash, int chave, Elemento *elemento);

int tabela_hash_obter(Tabela_Hash **tabela_hash, int chave, Elemento *elemento);
int tabela_hash_alterar(Tabela_Hash **tabela_hash, int chave, Elemento *elemento);

int tabela_hash_for(Tabela_Hash **tabela_hash, Elemento *elemento);
void tabela_hash_formatar(Tabela_Hash **tabela_hash);

#endif
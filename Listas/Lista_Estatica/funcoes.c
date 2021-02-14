#include <stdio.h>
#include "cabecalho.h"

/*  Funcoes */
void limpar_buffer(void)
{
    char lixo;
    do
    {
        lixo = getchar();
    }while(lixo != '\n');
}

void ler_string(char *nome, int tamanho)
{
    char letra, i = 0;
    do
    {
        letra = getchar();
        if(letra != '\n' && i < tamanho - 1)
        {
            nome[i] = letra;
            i++;
        }
    }while(letra != '\n');
    nome[i] = '\0';
}

void printar_menu(void)
{
    puts("------MENU------");
    puts("1. Listar");
    puts("2. Incluir");
    puts("3. Alterar");
    puts("4. Excluir");
    puts("5. Gravar lista");
    puts("6. Formatar");
    puts("0. Sair");
    printf("Opcao: ");
}

void listar_lista(Lista *lista)
{
    if(TAD_VerificarListaVazia(lista))
    {
        puts("Lista vazia!");
    }
    else
    {
        int tamanho = TAD_VerificarListaTamanho(lista);
        Cliente cliente;
        for(int i = 0; i < tamanho; i++)
        {
            puts("--------------------------");
            TAD_ObterElementoPosicao(lista, &cliente, i);
            printf("Codigo: %d \n", cliente.codigo);
            printf("Nome: %s \n", cliente.nome);
            puts("--------------------------");
        }
    }
}

void incluir_cliente(Lista *lista)
{
    int erro;
    Cliente cliente;
    puts("Digite o:");
    printf("Codigo: ");
    scanf("%d", &cliente.codigo);
    limpar_buffer();
    printf("Nome: ");
    ler_string(cliente.nome, CLIENTE_NOME_TAMANHO);
    erro = TAD_IncluirElementoOrdenada(lista, &cliente);
    if(erro == TAD_LISTA_INEXISTENTE) puts("Lista nao existe!");
    if(erro == TAD_LISTA_CHEIA) puts("Lista cheia!");
    if(erro == TAD_LISTA_SUCESSO) puts("Cliente incluido com sucesso!");
}

void alterar_cliente(Lista *lista)
{
    int erro, codigo;
    Cliente cliente;
    puts("--------- Cliente antigo ---------");
    printf("Digite o codigo do cliente que deseja alterar: ");
    scanf("%d", &codigo);
    limpar_buffer();
    puts("--------- Novo Cliente ---------");
    printf("Novo Codigo: ");
    scanf("%d", &cliente.codigo);
    limpar_buffer();
    printf("Novo Nome: ");
    ler_string(cliente.nome, CLIENTE_NOME_TAMANHO);
    erro = TAD_AlterarElementoCodigo(lista, &cliente, codigo);
    if(erro == TAD_LISTA_INEXISTENTE) puts("Lista nao existe!");
    if(erro == TAD_ELEMENTO_INEXISTENTE) puts("Cliente inexistente!");
    if(erro == TAD_LISTA_SUCESSO) puts("Cliente alterado com sucesso!");
}

void excluir_cliente(Lista *lista)
{
    int erro, codigo;
    printf("Digite o codigo do cliente que deseja excluir: ");
    scanf("%d", &codigo);
    limpar_buffer();
    erro = TAD_ExcluirElementoCodigo(lista, codigo);
    if(erro == TAD_LISTA_INEXISTENTE) puts("Lista nao existe!");
    if(erro == TAD_LISTA_VAZIA) puts("Lista vazia!");
    if(erro == TAD_ELEMENTO_INEXISTENTE) puts("Cliente inexistente!");
    if(erro == TAD_LISTA_SUCESSO) puts("Cliente excluido com sucesso!");
}

void gravar_lista(Lista *lista, char *arquivo)
{
    FILE *file = NULL;
    if((file = fopen(arquivo, ARQUIVO_MODO_EDICAO)) == NULL)
    {
        puts("Erro ao abrir arquivo!");
    }
    else
    {
        int tamanho = TAD_VerificarListaTamanho(lista);
        Cliente cliente;
        fprintf(file, "%d \n", tamanho);
        for(int i = 0; i < tamanho; i++)
        {
            TAD_ObterElementoPosicao(lista, &cliente, i);
            fprintf(file, "Codigo: %d \n", cliente.codigo);
            fprintf(file, "Nome: %s \n", cliente.nome);
        } 
        fclose(file);
        puts("Lista gravada com sucesso");
    }
}

void formatar_lista(Lista *lista)
{
    int erro = TAD_FormatarLista(lista);
    if(erro == TAD_LISTA_INEXISTENTE) puts("Lista nao existe!");
    if(erro == TAD_LISTA_SUCESSO) puts("Lista formatada com sucesso!");
}
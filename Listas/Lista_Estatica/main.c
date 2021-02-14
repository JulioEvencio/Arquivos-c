#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"
#include "cabecalho.h"

int main(int argc, char *argv[])
{
	int opcao;
	Lista *lista = NULL;

	if(argc != ARGUMENTOS_DO_PROGRAMA)
	{
		puts("Erro! Digite o <nome do programa> <nome do arquivo>");
		return 1;
	}

	if((lista = TAD_CriarLista()) == NULL)
	{
		puts("Erro ao criar lista!");
		return 1;
	}

	do
	{
		system(LIMPAR_TELA);
		printar_menu();
		scanf("%d", &opcao);
		limpar_buffer();
		switch(opcao)
		{
			case opcao_listar:
				listar_lista(lista);
				break;
			case opcao_incluir:
				incluir_cliente(lista);
				break;
			case opcao_alterar:
				alterar_cliente(lista);
				break;
			case opcao_excluir:
				excluir_cliente(lista);
				break;
			case opcao_gravar:
				gravar_lista(lista, argv[INDICE_ARQUIVO]);
				break;
			case opcao_formatar:
				formatar_lista(lista);
				break;
			case opcao_sair:
				puts("Obrigado por utilizar esse programa!");
				break;
			default:
				puts("Opcao invalida!");
		}
		puts("Pressione enter para continuar...");
		limpar_buffer();

	}while(opcao);

	if((TAD_LiberarLista(lista)) == TAD_LISTA_INEXISTENTE)
	{
		puts("Erro ao liberar lista!");
		return 1;
	}

	return 0;
}
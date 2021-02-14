#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"
#include "cabecalho.h"

int main(void)
{
	int opcao;
	Lista *lista = NULL;

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
				puts("Gravar");
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
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
			case OPCAO_LISTAR:
				listar_lista(lista);
				break;
			case OPCAO_INCLUIR:
				incluir_cliente(lista);
				break;
			case OPCAO_ALTERAR:
				alterar_cliente(lista);
				break;
			case OPCAO_EXCLUIR:
				excluir_cliente(lista);
				break;
			case OPCAO_GRAVAR_LISTA:
				puts("Gravar");
				break;
			case OPCAO_SAIR:
				puts("Obrigado por utilizar esse programa!");
				break;
			default:
				puts("Opcao invalida!");
		}
		puts("Pressione enter para continuar...");
		limpar_buffer();

	}while(opcao);

	TAD_LiberarLista(lista);

	return 0;
}
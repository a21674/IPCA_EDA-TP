/*****************************************************************//**
 * \file   Main.c
 * \brief  Funçao main que contem todas as iteraçoes e chamadas de funçoes
 * \email  
 * \author 20844_Oscar Araujo / 20845_Elson Simoes / 21674_Rui Lopes
 * \date   24 March 2021
 *********************************************************************/

#include "Files.h"


void main()
{
	Pacientes* listaPacientes = NULL;
	//Hospitais listaHospitais = NULL;
	int erro, erro2;
	int opcao;
	do
	{
		mostraFuncoes();
		scanf("%i", &opcao);
		switch (opcao)
		{
		case 0:
			printf("\n********** PROGRAMA TERMINADO **********\n");
			break;
		case 1:
			listaPacientes = carregadbPacientes(listaPacientes, &erro);

			if (erro == 1) printf("Ocorreu um erro ao importar os dados");
			else listar(listaPacientes);
			printf("\n");
			break;
		case 2:
			//listaHospitais = carregadbHospitais(listaHospitais, &erro2);

			//if (erro2 == 1) printf("Ocorreu um erro ao importar os dados");
			//else listar(listaHospitais);
			break;
		case 3:
			//editarErros(&listaDef, &listaErros);			// verificar código, estamos num procedimento logo temos de editar a lista
			break;											// original para não a perder
		case 4:
			//editaHospital(&listaHospitais);					// verificar código, estamos num procedimento logo temos de editar a lista
			break;											// original para não a perder
		case 5:
			//atribuiVagas(&listaDef, &listaHospitais);		// verificar código, estamos num procedimento logo temos de editar a lista
			//mostraTabelaHospitais(listaHospitais);			// original para não a perder
			break;
		default:
			printf("Essa opcao nao e valida!!!!\n");
			break;
		}
	} while (opcao != 0);
}


/*****************************************************************//**
 * \file   Main.c
 * \brief  Fun�ao main que contem todas as itera�oes e chamadas de fun�oes
 * \email  
 * \author 20844_Oscar Araujo / 20845_Elson Simoes / 21674_Rui Lopes
 * \date   24 March 2021
 *********************************************************************/

#include "Files.h"

void main()
{
	Pacientes listaPacientes = NULL;
	int erro;
	
	listaPacientes = carregadbPacientes(listaPacientes, &erro);
	if (erro == 1) { printf("Ocorreu um erro ao importar os dados"); }
	else
	{
		listar(listaPacientes);
	}
	



}

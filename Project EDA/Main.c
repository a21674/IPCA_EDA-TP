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
	PacientesTeste listaPacientes = NULL;
	Hospitais listaHospitais = NULL;

	int erro, erro2;

	mostraFuncoes();
	listaPacientes = carregadbPacientes(listaPacientes, &erro);
	//listaHospitais = carregadbHospitais(listaHospitais, &erro2);

	if (erro == 1) printf("Ocorreu um erro ao importar os dados"); 
	else listar(listaPacientes);

	//if (erro2 == 1) printf("Ocorreu um erro ao importar os dados");
	//else listar(listaHospitais);

}
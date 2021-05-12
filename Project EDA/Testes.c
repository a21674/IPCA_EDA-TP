/*****************************************************************//**
 * \file   Testes.c
 * \brief  Ficheiro para testes
 * \email  a20844@alunos.ipca.pt
 * \author Oscar Araujo
 * \date   7 May 2021
 *********************************************************************/

#include "Files.h"





void ordenaPacientesPreferencia(Pacientes lista1, Hospitais lista2)
{
	Pacientes aux = malloc(sizeof(Pacientes));
	Pacientes ultimo = malloc(sizeof(Pacientes));
	char hospital[1];

	while (lista2 != NULL)
	{
		strcpy(hospital, lista2->nome);
		while (lista1 != NULL)
		{
			if (strcmp(lista1->preferencias[0].preferencia, hospital) == 0)
			{
				inserePacienteFim(&aux, lista1);
				ordenaPacientesDistancia(&aux);
			}
			lista1 = lista1->proximo;
		}

		lista2 = lista2->seguinte;
	}

}

Pacientes inserePacienteOrdenado(Pacientes lista, Pacientes paciente)
{
	if (lista != NULL)
	{

	}
}

Pacientes inserirPacienteFim(Pacientes lista, Pacientes paciente)
{
	int i = 0;
	Pacientes novo = malloc(sizeof(Pacientes));
	if (novo != NULL)
	{
		novo->numSNS = paciente->numSNS;
		strcpy(novo->nome, paciente->nome);
		while (i < 5)
		{
			strcpy(novo->preferencias[i]->preferencia, paciente->preferencias->preferencia[i]);
			novo->preferencias[i]->distancia = paciente->preferencias[i].distancia;
			i++;
		}
		novo->proximo = lista;
		return (novo);
	}
	else return (lista);
}

void listar2(Pacientes inicio)
{
	printf("\nID\t NOME\t  PREF1\t  DIST\t PREF2\t DIST\t PREF3\t  DIST\t PREF4\t  DIST\t PREF5\t DIST \n\n");
	while (inicio != NULL)
	{
		printf("%-5d\t %-10s", inicio->numSNS, inicio->nome);
		for (int i = 0; i < inicio->preferencias; i++)
		{
			printf("%3s\t %-3d\t", inicio->preferencias[i].preferencia, inicio->preferencias[i].distancia);
			
		}
		printf("\n");
		inicio = inicio->proximo;
	}
}

void main()
{
	

	listar2(pacientes);

}

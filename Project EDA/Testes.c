/*****************************************************************//**
 * \file   Testes.c
 * \brief  Ficheiro para testes
 * \email  a20844@alunos.ipca.pt
 * \author Oscar Araujo
 * \date   7 May 2021
 *********************************************************************/

#include "Files.h"




/**
 * ordenaPacientesPreferencia:
 * Função que recebe a lista de pacientes e ordena por preferencia principal e distancia
 * \param lista1 -->Recebe a lista ligada de pacientes a ordenar
 * \param lista2 -->Recebe a lista de Hospitais disponiveis
 */
void ordenaPacientesPreferencia(Pacientes lista1, Hospitais lista2)
{
	Pacientes aux = malloc(sizeof(Pacientes));
	char hospital[1];

	while (lista2 != NULL)
	{
		strcpy(hospital, lista2->nome);
		while (lista1 != NULL)
		{
			if (strcmp(lista1->preferencias[0].preferencia, hospital) == 0)
			{
				inserirPacientePosicao(&aux, lista1, hospital);
			}
			lista1 = lista1->proximo;
		}

		lista2 = lista2->seguinte;
	}

}

/**
 * inserirPacientePosicao:
 * Função que dado o endereço de uma lista ligada e um determinado paciente insere o paciente na posição que lhe é devida
 * \param lista -->Recebe lista ligada de Pacientes
 * \param paciente -->Recebe o paciente a inserir na lista ligada
 * \return -->Devolve uma nova lista ligada com o paciente inserido na posição correta
 */
Pacientes inserirPacientePosicao(Pacientes* lista, Pacientes paciente, char hospital)
{
	int i = 0;
	Pacientes novo = malloc(sizeof(Pacientes));
	int compara;

	if (lista == NULL) { inserirPacienteInicio(&lista, paciente); return (lista); }

	compara = strcmp(hospital, lista);
	if (compara != 0 && (lista->preferencias[0].distancia < paciente->preferencias[0].distancia))
		inserirPacientePosicao(lista->proximo, paciente, hospital);
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

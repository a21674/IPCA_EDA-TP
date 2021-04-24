/*****************************************************************//**
 * \file   Functions.c
 * \brief  Ficheiro que contem todas as funçoes e procedimentos a ser utilizados na funçao main
 * \email  
 * \author 20844_Oscar Araujo / 20845_Elson Simoes / 21674_Rui Lopes
 * \date   24 March 2021
 *********************************************************************/

#include "Files.h"


 /**
  * Função que abre o ficheiro txt com a Lista dos Pacientes, valida se tudo correu bem
  *	e carrega para uma lista ligada
  * \param tipoUnidades
  * \param size
  */
Pacientes carregadbPacientes(Pacientes inicio, int* erro)
{
	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL) return (*erro = -1); //erro de abertura do ficheiro

	else {
		char str[100]
			, delimiter[1] = ";" //define o delimitador ";" que separa as colunas do ficheiro txt
			, endOfLine[2] = "\n"; //define o delimitador fim da linha \n, usamos este delimitador quando lemos a ultima coluna, caso contrario se for uma string ela guarda o caracter \n junto com a string

		while (fgets(str, sizeof(str), dbPacientes) != NULL)
		{
			Pacientes novo = (Pacientes*)malloc(sizeof(Pacientes));

			if (novo != NULL)
			{
				novo->numSNS = atoi(strtok(str, delimiter)); //como a função strok lê uma string, para converter para um inteiro o ID usamos a função atoi que faz o cast de string para int;
				strcpy(novo->nome, strtok(NULL, delimiter));
				strcpy(novo->preferencia_1, strtok(NULL, delimiter));
				novo->distancia_1 = atoi(strtok(NULL, delimiter));
				strcpy(novo->preferencia_2, strtok(NULL, delimiter));
				novo->distancia_2 = atoi(strtok(NULL, delimiter));
				strcpy(novo->preferencia_3, strtok(NULL, delimiter));
				novo->distancia_3 = atoi(strtok(NULL, delimiter));
				strcpy(novo->preferencia_4, strtok(NULL, delimiter));
				novo->distancia_4 = atoi(strtok(NULL, delimiter));
				strcpy(novo->preferencia_5, strtok(NULL, delimiter));
				novo->distancia_5 = atoi(strtok(NULL, endOfLine));

				novo->proximo = inicio;
			}
			inicio = novo;

		}
		fclose(dbPacientes); //no fim de abrir o documento e passar o conteúdo para a lista, fechamos o file e gravamos
		return(inicio); //retorna a nova lista carregada caso corra tudo bem
	}
}

void listar(Pacientes inicio)
{
	printf("ID\t NOME\t  PREF1\t  DIST\t PREF2\t DIST\t PREF3\t  DIST\t PREF4\t  DIST\t PREF5\t DIST \n\n");
	while (inicio != NULL)
	{
		printf("%-5d\t %-10s %2s\t %4d\t %2s\t %4d\t  %2s\t %4d\t %2s\t  %4d\t  %2s\t %-4d \n",
			inicio->numSNS, inicio->nome, inicio->preferencia_1, inicio->distancia_1, inicio->preferencia_2, inicio->distancia_2, inicio->preferencia_3, inicio->distancia_3,
			inicio->preferencia_4, inicio->distancia_4, inicio->preferencia_5, inicio->distancia_5);

		inicio = inicio->proximo;
	}
}

/**
 * loadHospitais:
 * Função que abre o ficheiro txt com a lista de pacientes e 
 * \param inicio -->Lista ligada com todos os pacientes
 * \param erro --> valor a retornar dependendo do sucesso de leitura do ficheiro
 */

/*Hospitais loadHospitais(Hospitais lista, int* erro)
{

	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL) return (*erro = -1); //erro de abertura do ficheiro

	else {
		Hospitais novo = (Hospitais*)malloc(sizeof(Hospitais));

		while (!feof(dbPacientes)) {
			fscanf(dbPacientes, "%s;%[^;]d;",&lista->nome, lista->vagas);
		}
	}
	fclose(dbPacientes);

}*/

/*PacientesTeste carregadbPacientes2(PacientesTeste inicio, int* erro)
{
	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL) return(erro = -1); //erro de abertura do ficheiro

	else {
		char str[100]
			, delimiter[1] = ";" //define o delimitador ";" que separa as colunas do ficheiro txt
			, endOfLine[2] = "\n"; //define o delimitador fim da linha \n, usamos este delimitador quando lemos a ultima coluna, caso contrario se for uma string ela guarda o caracter \n junto com a string

		while (fgets(str, sizeof(str), dbPacientes) != NULL)
		{
			PacientesTeste novo = (PacientesTeste*)malloc(sizeof(Pacientes));

			if (novo != NULL)
			{
				novo->numSNS = atoi(strtok(str, delimiter)); //como a função strok lê uma string, para converter para um inteiro o ID usamos a função atoi que faz o cast de string para int;
				strcpy(novo->nome, strtok(NULL, delimiter));
				for (int i = 0; i < 5; i++)
				{
					strcpy(novo->preferencias[i]->preferencia, strtok(NULL, delimiter));
					novo->preferencias[i]->distancia = atoi(strtok(NULL, delimiter));
				}

				novo->proximo = inicio;
			}
			inicio = novo;

		}
		fclose(dbPacientes); //no fim de abrir o documento e passar o conteúdo para a lista, fechamos o file e gravamos
		return(inicio); //retorna a nova lista carregada caso corra tudo bem
	}
}

*/

/*
void listar2(PacientesTeste inicio)
{
	while (inicio != NULL)
	{
		printf("%d; %s; ",inicio->numSNS, inicio->nome);

		inicio = inicio->proximo;
	}
}*/

/**
 * procuraErros:
 * Função que dada um elemento de uma lista de pacientes procura a existencia de erros nos dados fornecidos pelo mesmo
 * \param lista -->Recebe elemento da lista ligada de pacientes
 * \return --> 0 se contiver erros || 1 se estiver tudo completo e correto
 */
PacientesTeste procuraErros(PacientesTeste paciente, int erro)
{
	if (paciente->numSNS < 1)
	{
		strcpy(paciente->dados, "numSNS");
		return(0);
	}
	else if (paciente->nome == NULL)
	{
		strcpy(paciente->nome, "NOME");
		return(0);
	}
	else
	{
		for (int i = 0; i < paciente->preferencias; i++)
		{
			if (i == 1 && (paciente->preferencias[i]->preferencia == NULL || paciente->preferencias[i]->distancia < 1)) return(0);
			else if (paciente->preferencias[i]->preferencia == NULL || paciente->preferencias[i]->distancia < 1) return(0);
		}
	}
	return (1);
}





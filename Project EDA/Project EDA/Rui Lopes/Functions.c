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
  *
  * \param tipoUnidades
  * \param size
  */
Pacientes carregadbPacientes(Pacientes inicio, int *erro)
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

Pacientes loadHospitais(Pacientes inicio, int* erro)
{

	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL) return (*erro = -1); //erro de abertura do ficheiro

	else {
		Pacientes novo = (Pacientes*)malloc(sizeof(Pacientes));

		while (!feof(dbPacientes)) {
			fscanf(dbPacientes, "%d;%[^;]s;%[^;]s;%d;%[^;]s;%d;%[^;]s;%d;%[^;]s;%d;%[^;]s;%d",
				&inicio->numSNS, inicio->nome, inicio->preferencia_1, &inicio->distancia_1, inicio->preferencia_2, &inicio->distancia_2, inicio->preferencia_3, &inicio->distancia_3,
				inicio->preferencia_4, &inicio->distancia_4, inicio->preferencia_5, &inicio->distancia_5);
			printf("%d; %s; %s; %d; %s; %d; %s; %d; %s; %d; %s; %d \n",
				inicio->numSNS, inicio->nome, inicio->preferencia_1, inicio->distancia_1, inicio->preferencia_2, inicio->distancia_2, inicio->preferencia_3, inicio->distancia_3,
				inicio->preferencia_4, inicio->distancia_4, inicio->preferencia_5, inicio->distancia_5);
		}
	}
	fclose(dbPacientes);

}


void listar(Pacientes inicio)
{
	while (inicio != NULL)
	{
		printf("%d; %s; %s; %d; %s; %d; %s; %d; %s; %d; %s; %d \n", 
			inicio->numSNS, inicio->nome, inicio->preferencia_1, inicio->distancia_1, inicio->preferencia_2, inicio->distancia_2, inicio->preferencia_3, inicio->distancia_3,
			inicio->preferencia_4, inicio->distancia_4, inicio->preferencia_5, inicio->distancia_5);
		
		inicio = inicio->proximo;
	}
}

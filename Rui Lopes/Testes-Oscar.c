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

Pacientes* carregadbPacientes(Pacientes* inicio, int* erro)
{
	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL)  return (*erro = -1);  //erro de abertura do ficheiro
	else {
		char str[100]
			, delimiter[1] = ";" //define o delimitador ";" que separa as colunas do ficheiro txt
			, endOfLine[2] = "\n"; //define o delimitador fim da linha \n, usamos este delimitador quando lemos a ultima coluna, caso contrario se for uma string ela guarda o caracter \n junto com a string

		Pacientes* checkErros = (Pacientes*)malloc(sizeof(Pacientes));

		while (fgets(str, sizeof(str), dbPacientes) != NULL)
		{
			if (checkErros != NULL)
			{
				checkErros->numSNS = atoi(strtok(str, delimiter)); //como a função strok lê uma string, para converter para um inteiro o ID usamos a função atoi que faz o cast de string para int;
				strcpy(checkErros->nome, strtok(NULL, delimiter));
				strcpy(checkErros->preferencia[0].preferencia, strtok(NULL, delimiter));
				checkErros->preferencia[0].distancia = atoi(strtok(NULL, delimiter));
				strcpy(checkErros->preferencia[1].preferencia, strtok(NULL, delimiter));
				checkErros->preferencia[1].distancia = atoi(strtok(NULL, delimiter));
				strcpy(checkErros->preferencia[2].preferencia, strtok(NULL, delimiter));
				checkErros->preferencia[2].distancia = atoi(strtok(NULL, delimiter));
				strcpy(checkErros->preferencia[3].preferencia, strtok(NULL, delimiter));
				checkErros->preferencia[3].distancia = atoi(strtok(NULL, delimiter));
				strcpy(checkErros->preferencia[4].preferencia, strtok(NULL, delimiter));
				checkErros->preferencia[4].distancia = atoi(strtok(NULL, endOfLine));
				strcpy(checkErros->vaga, "VAZIO");
			}
			//inicio = inserePacInicio(inicio, checkErros);
			inicio = inserePacFim(inicio, checkErros);
		}
		fclose(dbPacientes); //no fim de abrir o documento e passar o conteúdo para a lista, fechamos o file e gravamos
		erro = 0;
		return(inicio); //retorna a nova lista carregada caso corra tudo bem
	}
}

void listar(Pacientes* inicio)
{
	Pacientes* aux = inicio; //cria um apontador que irá apontar para o inicio
	printf("\nID\t NOME\t  PREF1\t  DIST\t PREF2\t DIST\t PREF3\t  DIST\t PREF4\t  DIST\t PREF5\t DIST \n\n");
	while (aux != NULL)
	{
		printf("%-5d\t %-10s %2s\t %4d\t %2s\t %4d\t  %2s\t %4d\t %2s\t  %4d\t  %2s\t %-4d \n",
			aux->numSNS, aux->nome, aux->preferencia[0].preferencia, aux->preferencia[0].distancia, aux->preferencia[1].preferencia,
			aux->preferencia[1].distancia, aux->preferencia[2].preferencia, aux->preferencia[2].distancia, aux->preferencia[3].preferencia,
			aux->preferencia[3].distancia, aux->preferencia[4].preferencia, aux->preferencia[4].distancia);

		aux = aux->proximo; //aux ficará com o valor do próximo elemento
	}
}

void main2()
{
	Pacientes pacientes = NULL;
	int erro;
	carregadbPacientes(pacientes, &erro);
	listar(&pacientes);

}

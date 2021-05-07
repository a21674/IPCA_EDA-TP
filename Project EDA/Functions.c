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
				strcpy(novo->vaga, "VAZIO");

				novo->proximo = inicio;
			}
			inicio = novo;

		}
		fclose(dbPacientes); //no fim de abrir o documento e passar o conteúdo para a lista, fechamos o file e gravamos
		return(inicio); //retorna a nova lista carregada caso corra tudo bem
	}
}

/**
 * listar:
 * Procedimento para listar no ecra todos os pacientes carreegados por ficheiro assim como todos os seus dados
 * \param inicio -->Recebe uma lista ligada de pacientes
 */
void listar(Pacientes inicio)
{
	printf("\nID\t NOME\t  PREF1\t  DIST\t PREF2\t DIST\t PREF3\t  DIST\t PREF4\t  DIST\t PREF5\t DIST \n\n");
	while (inicio != NULL)
	{
		printf("%-5d\t %-10s %2s\t %4d\t %2s\t %4d\t  %2s\t %4d\t %2s\t  %4d\t  %2s\t %-4d \n",inicio->numSNS, inicio->nome, inicio->preferencia_1, inicio->distancia_1, inicio->preferencia_2, inicio->distancia_2, inicio->preferencia_3, inicio->distancia_3,inicio->preferencia_4, inicio->distancia_4, inicio->preferencia_5, inicio->distancia_5);

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
	if (paciente->numSNS < 1) strcpy(paciente->dados, "numSNS");				//discutir a aparencia do ID SNS (Quantos digitos??)
	else if (paciente->nome == NULL) strcpy(paciente->dados, "NOME");
	else
	{
		for (int i = 0; i < paciente->preferencias; i++)
		{
			if (i == 1 && (paciente->preferencias[i]->preferencia == NULL || paciente->preferencias[i]->distancia < 1)) strcpy(paciente->dados, "PREFERENCIA");;
			else if (paciente->preferencias[i]->preferencia == NULL || paciente->preferencias[i]->distancia < 1) strcpy(paciente->dados, "PREFERENCIA");
		}
	}
	erro = 1;
}

/**
 * mostraFuncoes:
 * Procedimento para mostrar menu de opções disponiveis de executar
 */
void mostraFuncoes()
{
	printf("=================================\n");
	printf("Software de Atribuicao de Vagas\n");
	printf("[1] Listar Dados Pacientes\n");
	printf("[2] Listar Hospitais e vagas livres\n");
	printf("[3] Gerir Pacientes com erros de dados\n");
	printf("[4] Gerir Vagas de Hospitais\n");
	printf("[5] Atribuir vagas e mostrar resultado\n");
	printf("[0] Terminar Software\n");
	printf("Escolha uma opcao: ");
}

/**
 * escolheFuncao:
 * Procedimento para ler escolha e executar a pção escolhida
 * \param listaDef -->Lista ligada definitiva de pacientes
 * \param listaHospitais -->Lista ligada dos Hospitais e suas vagas
 * \param listaErros -->Lista ligada de pacientes com dados errados ou imcompletos
 */
void escolheFuncao(Pacientes* listaDef, Hospitais* listaHospitais, Pacientes listaErros )
{
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
			listar(listaDef);
			break;
		case 2:
			listarHospitais(listaHospitais);
			break;
		case 3:
			editarErros(&listaDef, &listaErros);			// verificar código, estamos num procedimento logo temos de editar a lista
			break;											// original para não a perder
		case 4:
			editaHospital(&listaHospitais);					// verificar código, estamos num procedimento logo temos de editar a lista
			break;											// original para não a perder
		case 5:
			atribuiVagas(&listaDef, &listaHospitais);		// verificar código, estamos num procedimento logo temos de editar a lista
			mostraTabelaHospitais(listaHospitais);			// original para não a perder
			break;
		default:
			printf("Essa opcao nao e valida!!!!\n");
			break;

		}
	} 	while (opcao != 0);
}

/**
 * inserirPosicao:
 * Função para dada a lista definiviva de pacientes insere um novo paciente cujos dados foram corrigidos na posição correta
 * \param listaDef -->Recebe lista definiva de pacientes
 * \param x -->Recebe um doente do tipo struct com dados corrigidos
 * \return -->Devolve a lista definitiva com o paciente inserido na posição correta
 */
Pacientes inserirPosicao(Pacientes listaDef, Pacientes x)
{
	Pacientes aux = listaDef;
	int contador = 0;
	while (aux != NULL)
	{
		contador++;
		aux = aux->proximo;
	}
	if ( x->numSNS >= 1 && x->numSNS <= contador + 1)
	{
		if (x->numSNS == 1)
		{
			return (inserirPacienteInicio(listaDef, x));
		}
		else
		{
			Pacientes novo = NULL;
			Pacientes seguinte = listaDef;

			for (int i = 1; i < x->numSNS; i++)					//x é o numSNS do paciente a inserir
			{													//rever ciclo para situação de numSNS não sequenciais
				novo = seguinte;
				seguinte = novo->proximo;
			}
			novo->proximo = inserirInicio(seguinte, x);
			return listaDef;
		}
	}
	else { return listaDef; }
}

/**
 * inserirPacienteInicio:
 * Função que dada uma lista de pacientes insere no inicio um paciente
 * \param lista -->Lista de pacientes a editar
 * \param x -->Paciente do tipo struct a inserir
 * \return -->Devolve a lista com o paciente inserido se for possivel
 */
Pacientes inserirPacienteInicio(Pacientes lista, Pacientes x)
{
	Pacientes novo = malloc(sizeof(Pacientes));
	if (novo != NULL)
	{
		novo->numSNS = x->numSNS;
		strcpy(novo->nome, x->nome);
		strcpy(novo->preferencia_1, x->preferencia_1);
		novo->distancia_1 = x->distancia_1;
		strcpy(novo->preferencia_2, x->preferencia_2);
		novo->distancia_2 = x->distancia_2;
		strcpy(novo->preferencia_3, x->preferencia_3);
		novo->distancia_3 = x->distancia_3;
		strcpy(novo->preferencia_4, x->preferencia_4);
		novo->distancia_4 = x->distancia_4;
		strcpy(novo->preferencia_5, x->preferencia_5);
		novo->distancia_5 = x->distancia_5;
		novo->proximo = lista;
		return (novo);
	}
	else return (lista);
}

/**
 * atribuiVagas:
 * Função que dadas as lisltas ligadas de pacientes e hospitais analisa preferencias distancias e vagas livres para atribuir
 * \param lista1 -->Recebe lista ligadaDef de Pacientes
 * \param lista2 -->Recebe lista ligada dos Hospitais
 */

Hospitais atribuiVagas(Pacientes lista1, Hospitais lista2)
{
	Preferencias preferencia[2];

	while (lista2 != NULL)
	{
		if (lista2->vagas != 0)
		{
			while (lista1 != NULL)
			{
				if (strcmp(lista1->vaga, "VAZIO") != 0)
				{
					preferencia = lista1->preferencia;
					if (strcmp(preferencia, lista2->nome) == 0)
					{
						if (lista2->vagas > 0)
						{
							strcpy(lista1->vaga, lista2->nome);
							lista2->listaVagas = inserirPosicao(lista2->listaVagas, lista1);
						}
						else atribuiVagas()
					}

				}
				lista1 = lista1->proximo;
			}
		}
		lista2 = lista2->seguinte;
	}		

}




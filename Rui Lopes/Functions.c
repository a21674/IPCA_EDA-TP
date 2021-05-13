/*****************************************************************//**
 * \file   Functions.c
 * \brief  Ficheiro que contem todas as funçoes e procedimentos a ser utilizados na funçao main
 * \email  
 * \author 20844_Oscar Araujo / 20845_Elson Simoes / 21674_Rui Lopes
 * \date   24 March 2021
 *********************************************************************/

#include "Files.h"


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
  * Função que abre o ficheiro txt com a Lista dos Pacientes, valida se tudo correu bem e carrega para uma lista ligada
  * \param tipoUnidades
  * \param size
  */
Pacientes* carregadbPacientes(Pacientes* inicio, int* erro)
{
	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL) *erro = -1; //erro de abertura do ficheiro
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
		*erro = 0;
		fclose(dbPacientes); //no fim de abrir o documento e passar o conteúdo para a lista, fechamos o file e gravamos
		return(inicio); //retorna a nova lista carregada caso corra tudo bem
	}
}
/**
 * inserirPacienteInicio:
 * Função que dada uma lista de pacientes insere no inicio um paciente
 * \param lista -->Lista de pacientes a editar
 * \param entrada -->Paciente do tipo struct a inserir
 * \return -->Devolve a lista com o paciente inserido se for possivel
 */
Pacientes* inserePacInicio(Pacientes* lista, Pacientes* entrada)
{
	Pacientes* novo = (Pacientes*)malloc(sizeof(Pacientes));
	if (novo != NULL)
	{
		novo->numSNS = entrada->numSNS;
		strcpy(novo->nome, entrada->nome);
		strcpy(novo->preferencia[0].preferencia, entrada->preferencia[0].preferencia);
		novo->preferencia[0].distancia = entrada->preferencia[0].distancia;
		strcpy(novo->preferencia[1].preferencia, entrada->preferencia[1].preferencia);
		novo->preferencia[1].distancia = entrada->preferencia[1].distancia;
		strcpy(novo->preferencia[2].preferencia, entrada->preferencia[2].preferencia);
		novo->preferencia[2].distancia = entrada->preferencia[2].distancia;
		strcpy(novo->preferencia[3].preferencia, entrada->preferencia[3].preferencia);
		novo->preferencia[3].distancia = entrada->preferencia[3].distancia;
		strcpy(novo->preferencia[4].preferencia, entrada->preferencia[4].preferencia);
		novo->preferencia[4].distancia = entrada->preferencia[4].distancia;
		
		novo->proximo = lista;

		return (novo);
	}
	else return (lista);
}

/**
 * inserePacFim
 * Função que dada uma lista de pacientes insere no fim um paciente
 * \param lista -->Lista de pacientes a editar
 * \param entrada -->Paciente do tipo struct a inserir
 * \return -->Devolve a lista com o paciente inserido se for possivel
 */
Pacientes* inserePacFim(Pacientes* lista, Pacientes* entrada)
{
	Pacientes* novo = (Pacientes*)malloc(sizeof(Pacientes));
	Pacientes* temp = lista;
	if (novo != NULL)
	{
		novo->numSNS = entrada->numSNS;
		strcpy(novo->nome, entrada->nome);
		strcpy(novo->preferencia[0].preferencia, entrada->preferencia[0].preferencia);
		novo->preferencia[0].distancia = entrada->preferencia[0].distancia;
		strcpy(novo->preferencia[1].preferencia, entrada->preferencia[1].preferencia);
		novo->preferencia[1].distancia = entrada->preferencia[1].distancia;
		strcpy(novo->preferencia[2].preferencia, entrada->preferencia[2].preferencia);
		novo->preferencia[2].distancia = entrada->preferencia[2].distancia;
		strcpy(novo->preferencia[3].preferencia, entrada->preferencia[3].preferencia);
		novo->preferencia[3].distancia = entrada->preferencia[3].distancia;
		strcpy(novo->preferencia[4].preferencia, entrada->preferencia[4].preferencia);
		novo->preferencia[4].distancia = entrada->preferencia[4].distancia;
		
		novo->proximo = NULL;

		if (lista == NULL) { return novo; }
		else
		{
			while (temp->proximo != NULL) temp = temp->proximo;
			temp->proximo = novo;
			return(lista);
		}
	}
	else return(lista);
}

/**
 * listar:
 * Procedimento para listar no ecra todos os pacientes carreegados por ficheiro assim como todos os seus dados
 * \param inicio -->Recebe uma lista ligada de pacientes
 */
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





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
Pacientes* carregadbPacientes(Pacientes* inicio, int *erro)
{
	FILE* dbPacientes; //cria um apontador do tipo file
	dbPacientes = fopen(PATH_DB_PACIENTES, "r");

	if (dbPacientes == NULL) { }//{ return (*erro -1); } //erro de abertura do ficheiro
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
			//inicio = inserePacFim(inicio, checkErros);
			inicio = checkErrosPac(inicio, checkErros);

		}
		fclose(dbPacientes); //no fim de abrir o documento e passar o conteúdo para a lista, fechamos o file e gravamos
		return(inicio); //retorna a nova lista carregada caso corra tudo bem
	}
}


/**
 * procuraErros:
 * Função que dada um elemento de uma lista de pacientes procura a existencia de erros nos dados fornecidos pelo mesmo
 * \param lista -->Recebe elemento da lista ligada de pacientes
 * \return --> 0 se contiver erros || 1 se estiver tudo completo e correto
 */
Pacientes* checkErrosPac(Pacientes* lista, Pacientes* checkErros)
{
	boolean nSNSExist;
	if (checkErros->numSNS == NULL) {
		//insereListaErros(erro1); 
	}
	else
	{
		nSNSExist = checkNumSNSExist(lista, checkErros->numSNS);
		if (nSNSExist == true) {
			//insereListaErros(erro2); 
		}
		else if (checkErros->preferencia[0].preferencia == NULL || checkErros->preferencia[0].distancia == NULL) {
			//insereListaErros(erro3); 
		}
		else inserePacFim(lista, checkErros);
	}
	

}

boolean checkNumSNSExist(Pacientes* lista, int numSNS)
{
	if (lista == NULL) return false;
	else
	{
		while (lista != NULL)
		{
			if (numSNS == lista->numSNS) return true;
			lista = lista->proximo;
		}
		return false;
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







/**
 * inserirPosicao:
 * Função para dada a lista definiviva de pacientes insere um novo paciente cujos dados foram corrigidos na posição correta
 * \param listaDef -->Recebe lista definiva de pacientes
 * \param x -->Recebe um doente do tipo struct com dados corrigidos
 * \return -->Devolve a lista definitiva com o paciente inserido na posição correta
 */
//Pacientes inserirPosicao(Pacientes listaDef, Pacientes x)
//{
//	Pacientes aux = listaDef;
//	int contador = 0;
//	while (aux != NULL)
//	{
//		contador++;
//		aux = aux->proximo;
//	}
//	if ( x->numSNS >= 1 && x->numSNS <= contador + 1)
//	{
//		if (x->numSNS == 1)
//		{
//			return (inserirPacienteInicio(listaDef, x));
//		}
//		else
//		{
//			Pacientes novo = NULL;
//			Pacientes seguinte = listaDef;
//
//			for (int i = 1; i < x->numSNS; i++)					//x é o numSNS do paciente a inserir
//			{													//rever ciclo para situação de numSNS não sequenciais
//				novo = seguinte;
//				seguinte = novo->proximo;
//			}
//			novo->proximo = inserirInicio(seguinte, x);
//			return listaDef;
//		}
//	}
//	else { return listaDef; }
//}






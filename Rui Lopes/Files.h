/*****************************************************************//**
 * \file   Files.h
 * \brief  Header file que contem todas as assinaturas de funçoes e definiçoes de tipos de dados
 * \email  
 * \author 20844_Oscar Araujo / 20845_Elson Simoes / 21674_Rui Lopes
 * \date   24 March 2021
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //lib para manipular strings

#pragma region Defines
#pragma warning (disable:4996) // desativa os warings referentes ao printf e scanf
#define PATH_DB_PACIENTES "DataBase\\pacientes.txt" // Define o caminho do ficheiro dos pacientes
#define MAXNOME 30


#pragma endregion

//Criaçao de tipos de dados a utilizar no nosso código
#pragma region Tipos de Dados
typedef enum { false, true }boolean;

typedef struct preferencias {
    char preferencia[1];
    int distancia;
}Preferencias;

typedef struct pacientes {
    int numSNS;
    char nome[MAXNOME];
    Preferencias preferencia[5];
    char vaga[5];
    char dados[10];
    struct pacientes *proximo;
    //Pacientes* anterior;
}Pacientes;



//typedef struct vagas
//{
//    int numSNS;
//    Pacientes* utente;
//    struct vagas* seguinte;
//}*vagas;
//
//typedef struct Hospitais
//{
//    char nome[1];
//    int vagas;
//    struct Hospitais* seguinte;
//    struct vagas* listaVagas;
//}*Hospitais;

//typedef struct listaPacientes {
//    Pacientes* nPaciente;
//    struct listaPacientes* proximo;
//
//}


#pragma endregion

//Assinaturas das funçoes/procedimentos criados e a ser chamadas no main
#pragma region Assinaturas de Funçoes

Pacientes* carregadbPacientes(Pacientes* inicio, int* erro);
Pacientes* checkErrosPac(Pacientes* lista, Pacientes* checkErros);
boolean checkNumSNSExist(Pacientes* lista, int numSNS);
Pacientes* inserePacInicio(Pacientes* lista, Pacientes* x);
Pacientes* inserePacFim(Pacientes* lista, Pacientes* entrada);
void listar(Pacientes* inicio);
void mostraFuncoes();








#pragma endregion
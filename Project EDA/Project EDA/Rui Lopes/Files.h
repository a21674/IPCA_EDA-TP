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

typedef struct pacientes{
    int numSNS;
    char nome[MAXNOME];
    char preferencia_1[1];
    int distancia_1;
    char preferencia_2[1];
    int distancia_2;
    char preferencia_3[1];
    int distancia_3;
    char preferencia_4[1];
    int distancia_4;
    char preferencia_5[1];
    int distancia_5;
    struct pacientes *proximo;
}* Pacientes;


//typedef struct listaPacientes {
//    Pacientes* nPaciente;
//    struct listaPacientes* proximo;
//
//}


#pragma endregion

//Assinaturas das funçoes/procedimentos criados e a ser chamadas no main
#pragma region Assinaturas de Funçoes

Pacientes carregadbPacientes(Pacientes inicio, int* erro);
void listar(Pacientes inicio);
Pacientes loadHospitais(Pacientes inicio, int* erro);

#pragma endregion

#ifndef QUERIE1_H
#define QUERIE1_H

#include <fixtures.h>
#include <parsing/checker.h>


/**
 \file querie1.h
 \brief Módulo para a resolução da querie 1
*/


/**
 * @brief Função que calcula todos os dados pedidos na querie 1 que correspondem a um utilizador
 * 
 * @param users_list tabela de hash com a informação dos utilizadores
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com as informações das cidades
 * @param ficheiro ficheiro no qual serão escritos os dados recolhidos
 * @param username nome do utilizador que é dado pelo comando da querie
 */
void calculate_user(USERS users_list, DRIVERS drivers_list, RIDES rides_list, FILE *ficheiro, char *username);


/**
 * @brief Função que calcula todos os dados pedidos na querie 1 que correspondem a um condutor
 * 
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com as informações das cidades
 * @param ficheiro ficheiro no qual serão escritos os dados recolhidos
 * @param id do condutor que é dado pelo comando da querie
 */
void calculate_driver(DRIVERS drivers_list, RIDES rides_list, FILE *ficheiro, int id);


/**
 * @brief Função que executa um comando correspondente à queire 1
 * 
 * @param command comando que será executado
 * @param ncommand número do comando a ser executado 
 * @param users_list tabela de hash com a informação dos utilizadores
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com as informações das cidades
 * @param N_DRIVERS tamanho do array dos condutores
 */
void resolve_querie1(char *command, int ncommand, USERS users_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS);


#endif
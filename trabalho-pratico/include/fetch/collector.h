#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <fixtures.h>
#include <parsing/parser.h>


/**
 \file collector.h
 \brief Módulo para funções de recolha de catalogos
*/


/**
 * @brief Função que indica que uma viagem não está disponivel
 * 
 * @param path diretoria que contem o ficheiro referente aos utilizadores
 * @param users_list estrutura de dados dos utilizadores
 * @return 0 se a operação foi bem sucedida, caso contrario -1
 */
int fecth_users(char *path, USERS users_list);


/**
 * @brief Função que indica que uma viagem não está disponivel
 * 
 * @param path diretoria que contem o ficheiro referente aos condutores
 * @param drivers_list estrutura de dados dos condutores
 * @param N_DRIVERS numero de condutores analisados até ao momento
 * @param SIZE_DRIVERS tamanho da estrututa do condutores
 * @return 0 se a operação foi bem sucedida, caso contrario -1
 */
int fetch_drivers(char *path, DRIVERS *drivers_list, int *N_DRIVERS, int *SIZE_DRIVERS);


/**
 * @brief Função que indica que uma viagem não está disponivel
 * 
 * @param path diretoria que contem o ficheiro referente aos utilizadores
 * @param users_list estrutura de dados dos utilizadores
 * @param drivers_list estrutura de dados dos condutores
 * @param rides_list estrutura de dados das viagens
 * @param cities_list estrutura de dados das cidades
 * @param N_RIDES numero de viagens analisadas até ao momento
 * @param N_CITIES numero de cidades analisadas até ao momento
 * @param SIZE_RIDES tamanho da estrututa das viagens
 * @param SIZE_CITIES tamanho da estrututa das cidades
 * @return 0 se a operação foi bem sucedida, caso contrario -1
 */
int fetch_rides(char *path, USERS users_list, DRIVERS drivers_list, RIDES *rides_list, CITIES *cities_list, int *N_RIDES, int *N_CITIES, int *SIZE_RIDES, int *SIZE_CITIES);

#endif
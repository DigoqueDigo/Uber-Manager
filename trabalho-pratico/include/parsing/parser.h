#ifndef PARSER_H
#define PARSER_H

#include <parsing/checker.h>
#include <catalogs/users.h>
#include <catalogs/rides.h>
#include <catalogs/drivers.h>
#include <catalogs/cities.h>


/**
 \file parser.h
 \brief Módulo para o parsing dos dados
*/


/*!
 \def CAP_LINE_USER
 \brief Numero de parametros que um utilizador possui no ficheiro csv
*/
#define CAP_LINE_USER 7


/*!
 \def CAP_LINE
 \brief Numero de parametros que um condutor ou viagem possuem no ficheiro csv
*/
#define CAP_LINE 9


/**
 * @brief Função que organiza os dados de forma a estes serem colocados a estrutura dos utilizadores
 * 
 * @param linha estrutura na qual os dados estão separados e organizados
 * @param string linha da qual serão recolhidos os dados para tratamento
 * @param lista tabela de hash dos utilizadores na qual serão colocados os dados recolhidos
 */
void set_user_line(char  **linha, char *string, USERS lista);


/**
 * @brief Função que organiza os dados de forma a estes serem colocados a estrutura dos condutores
 * 
 * @param linha estrutura na qual os dados estão separados e organizados
 * @param string linha da qual serão recolhidos os dados para tratamento
 * @param lista array do condutores no qual serão colocados os dados recolhidos
 * @return 1 se os dados obtidos são válidos e 0 caso não sejam 
 */
int set_driver_line(char **linha, char *string, DRIVERS lista);


/**
 * @brief Função que organiza os dados de forma a estes serem colocados em diversas estruturas
 * 
 * @param linha estrutura na qual os dados estão separados e organizados
 * @param string linha da qual serão recolhidos os dados para tratamento
 * @param lista array no qual os dados referentes a viagens serão colocados 
 * @param lista_users tabale de hash na qual os dados referentes a utilizadores serão colocados
 * @param lista_drivers array do condutores no qual serão colocados os dados recolhidos
 * @param cities_list array no qual dados referentes a cidades serão colocados
 * @param N_CITIES comprimento array das cidades
 * @return 1 se os dados obtidos são válidos e 0 caso não sejam 
 */
int set_ride_line(char **linha, char *string, RIDES lista, USERS lista_users, DRIVERS lista_drivers, CITIES cities_list, int *N_CITIES);

#endif
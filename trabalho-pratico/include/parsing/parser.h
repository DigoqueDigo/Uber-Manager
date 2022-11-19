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
 * @brief Estrutura responsável pelo armazenamento de uma linha lida
 * 
 * É nesta estrutra que as linhas lidas são separadas e organizadas
 */
typedef struct line *LINE;


/**
 * @brief Função que organiza os dados de forma a estes serem colocados a estrutura dos condutores
 * 
 * @param linha estrutura na qual os dados estão separados e organizados
 * @param string linha da qual serão recolhidos os dados para tratamento
 * @param lista array do condutores no qual serão colocados os dados recolhidos
 * @return 1 se os dados obtidos são válidos e 0 caso não sejam 
 */
int set_driver_line(LINE linha, char *string, DRIVERS lista);


/**
 * @brief Função que imprime no standart output uma linha de um condutor
 * 
 * @param line estrutura que será impressa
 */
void print_driver_line(LINE line);


/**
 * @brief Função que liberta a memória alocada por uma linha utilizada para armazenar um condutor
 * 
 * @param line estrutura que será removida da memória
 */
void destroy_driver_line(LINE line);


/**
 * @brief Função que organiza os dados de forma a estes serem colocados a estrutura dos utilizadores
 * 
 * @param linha estrutura na qual os dados estão separados e organizados
 * @param string linha da qual serão recolhidos os dados para tratamento
 * @param lista tabela de hash dos utilizadores na qual serão colocados os dados recolhidos
 * @return 1 se os dados obtidos são válidos e 0 caso não sejam 
 */
int set_user_line(LINE linha, char *string, USERS lista);


/**
 * @brief Função que imprime no standart output uma linha de um utilizador
 * 
 * @param line estrutura que será impressa
 */
void print_user_line(LINE line);


/**
 * @brief Função que liberta a memória alocada por uma linha utilizada para armazenar um utilizador
 * 
 * @param line estrutura que será removida da memória
 */
void destroy_user_line(LINE line);


/**
 * @brief Função que organiza os dados de forma a estes serem colocados em diversas estruturas
 * 
 * @param line estrutura na qual os dados estão separados e organizados
 * @param string linha da qual serão recolhidos os dados para tratamento
 * @param lista array no qual os dados referentes a viagens serão colocados 
 * @param lista_users tabale de hash na qual os dados referentes a utilizadores serão colocados
 * @param lista_drivers array do condutores no qual serão colocados os dados recolhidos
 * @param cities_list array no qual dados referentes a cidades serão colocados
 * @param N_CITIES comprimento array das cidades
 * @return 1 se os dados obtidos são válidos e 0 caso não sejam 
 */
int set_ride_line(LINE line, char *string, RIDES lista, USERS lista_users, DRIVERS lista_drivers, CITIES cities_list, int *N_CITIES);

#endif
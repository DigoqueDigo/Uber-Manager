#ifndef QUERIE4_H
#define QUERIE4_H

#include <fixtures.h>


/**
 \file querie4.h
 \brief Módulo para a resolução da querie 4
*/


/**
 * @brief Função que calcula o preço media das viagens numa cidade
 * 
 * @param drivers_list array com a informação dos condutores
 * @param rides_list array com toda a informação correspondente às viagens
 * @param cities_list array com informação complementar às cidades
 * @param N_CITIES comprimento do array das cidades
 * @param city cidade em que se pretende fazer a analise
 * @return preço medio das viagens numa cidade
 */
double preco_medio_cidade(
    DRIVERS drivers_list, 
    RIDES rides_list, 
    CITIES cities_list, 
    int N_CITIES, 
    char* city
);


/**
 * @brief Função que executa um comando correspondente à querie 4
 * 
 * @param command comando que será executado 
 * @param ncommand número do comando que será executado
 * @param drivers_list array com toda a informação correspondente aos condutores
 * @param rides_list array com toda a informação correspondente às viagens
 * @param cities_list array com informação complementar às cidades
 * @param N_CITIES comprimento do array das cidades
 */
void resolve_querie4(
    char* command,
    int ncommand,
    DRIVERS drivers_list,
    RIDES rides_list,
    CITIES cities_list,
    int N_CITIES
);

#endif
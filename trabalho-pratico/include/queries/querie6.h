#ifndef QUERIE6_H
#define QUERIE6_H

#include <fixtures.h>


/**
 \file querie6.h
 \brief Módulo para a resolução da querie 6
*/


/**
 * @brief Função que calcula a media da disctância percorrida numa cidadde
 * 
 * @param rides_list array com as informações das viagens
 * @param cities_list array com informação complementar das cidades
 * @param N_CITIES tamanho do array das cidades
 * @param date_1 data de limite inferior
 * @param date_2 date de limite superior
 * @param city cidade na qual se pretende fazar a pesquisa
 * @return media da distância percorrida numa cidade 
 */
double calculate_average_distance(
    RIDES rides_list,
    CITIES cities_list,
    int N_CITIES,
    int date_1,
    int date_2,
    char *city
);


/**
 * @brief Função que executa um comando correspondente à querie 6
 * 
 * @param command comando que será executado 
 * @param ncommand número do comando que será executado
 * @param rides_list array com toda a informação correspondente às viagens
 * @param cities_list array com informação complementar às cidades
 * @param N_CITIES comprimento do array das cidades
 */
void resolve_querie6(
    char *command,
    int ncommand,
    RIDES rides_list,
    CITIES cities_list,
    int N_CITIES
);

#endif
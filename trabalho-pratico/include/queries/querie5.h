#ifndef QUERIE5_H
#define QUERIE5_H

#include <fixtures.h>


/**
 \file querie5.h
 \brief Módulo para a resolução da querie 5
*/


/**
 * @brief Função que calcula o preço medio das viagens entre uma determinada data
 * 
 * @param drivers_list array com as informações dos condutores 
 * @param rides_list array com as informações das viagens
 * @param N_RIDES tamanho do array da viagens
 * @param date_1 inteiro que representa data limite inferior
 * @param date_2 inteiro que representa data limite superior
 * @return preço medio das viagens entre duas datas
 */
double average_price_date(DRIVERS drivers_list, RIDES rides_list, int N_RIDES, int date_1, int date_2);


/**
 * @brief Função que executa um comando correspondente à queire 5
 * 
 * @param command comando que será executado
 * @param ncommand número do comando a ser executado 
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com as informações das viagens
 * @param N_RIDES tamanho do array das viagens
 */
void resolve_querie5(char* command, int ncommand, DRIVERS drivers_list, RIDES rides_list, int N_RIDES);

#endif
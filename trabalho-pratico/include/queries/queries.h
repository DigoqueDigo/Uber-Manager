#ifndef QUERIES_H
#define QUERIES_H

#include <fixtures.h>


/** \mainpage Projeto - Laboratórios de informática
 * 
 * Este projeto consiste no desenvolvimento de um gestor de dados, ou seja,
 * a partir da recolhar de várias informações, o programa tem de ser capaz
 * de responder a determinadas questões utiliadas pelo utilizador.
 *
 * Como as questões tinham de ser resolvidas em tempo útil utilizamos todas
 * as estrtégias que estavam ao nosso alcance sem que com isso quebrassemos
 * os conceitos de encapsulamento e modularidade. 
 * 
 * Projeto realizado por:\n 
 * :: Diogo Marques\n
 * :: João Faria\n
 * :: João Loureiro\n\n
 *
 * Universidade do Minho
*/


/**
 \file queries.h
 \brief Módulo para a aplicação das queries
*/


/**
 * @brief Função que executa todos os comandos existentes num ficheiro de texto
 * 
 * @param command commando que se pretende executar 
 * @param ncommand indice do comando a ser executado
 * @param users_list tabela de hash com toda a informação dos utilizadores
 * @param drivers_list array com toda a informação dos condutores
 * @param rides_list array com toda a informação correspondente às viagens
 * @param cities_list array com informação complementar das cidades 
 * @param N_DRIVERS comprimento do array dos condutores
 * @param N_RIDES comprimento do array das viagens
 * @param N_CITIES comprimento do array das cidades
 */
void resolve_queries(
    char *command,
    char ncommand,
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    CITIES cities_list,
    int N_DRIVERS,
    int N_RIDES,
    int N_CITIES
);



int resolve_queries_batch(
    char *path,
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    CITIES cities_list,
    int N_DRIVERS,
    int N_RIDES,
    int N_CITIES
);

#endif
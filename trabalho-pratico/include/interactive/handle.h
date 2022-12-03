#ifndef HANDLE_H
#define HANDLE_H

#include <fixtures.h>
#include <queries/queries.h>
#include <interactive/pagination.h>


/**
 \file handle.h
 \brief Módulo para funções de manipulação do modo interativo
*/


/**
 * @brief Função que imprime uma mensagem de sucesso referente à adição/eliminação de catalogos
 * 
 * @param N indica o ficheiro que foi adicionado/eliminado
 * @param flag indica se ocorreu uma adição ou eliminação
 */
void mensage_success(int N, int flag);


/**
 * @brief Função que elimina o catalogo dos utilizadores
 * 
 * @param users_list estrutura de dados que se pretende remover
 * @param users_flag obtem o valor zero caso a eliminação tenha sido bem efetuada 
 */
void remove_users_catalog(USERS *users_list, int *users_flag);


/**
 * @brief Função que elimina o catalogo dos condutores
 * 
 * @param drivers_list estrutura de dados que se pretende remover
 * @param N_DRIVERS tamanho da estrutura a ser removida
 */
void remove_drivers_catalog(DRIVERS *drivers_list, int *N_DRIVERS);


/**
 * @brief Função que elimina o catalogo dos condutores
 * 
 * @param rides_list estrutura das viagens que se pretende remover
 * @param cities_list estrutura das cidades que se pretende remover
 * @param N_RIDES tamanho da estrutura das viagens
 * @param N_CITIES tamanho da estrutura das cidades
 */
void remove_rides_catalog(RIDES *rides_list, CITIES *cities_list, int *N_RIDES, int *N_CITIES);


/**
 * @brief Função raiz de controlo do modo interativa
 * 
 * @param users_list catalogo dos utilizadores
 * @param drivers_list catalogo dos condutores
 * @param rides_list catalogo das viagens
 * @param cities_list catalogo das cidades
 * @param N_DRIVERS tamanho da estrutura dos condutores
 * @param N_RIDES tamanho da estrutura das viagens
 * @param N_CITIES tamanho da estrutura das cidades
 */
void interactive_mode(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    CITIES cities_list,
    int N_DRIVERS,
    int N_RIDES,
    int N_CITIES
);

#endif
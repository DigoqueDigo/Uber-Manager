#ifndef QUERIE8_H
#define QUERIE8_H

#include <fixtures.h>
#include <sort.h>


/**
 \file querie8.h
 \brief Módulo para a resolução da querie 8
*/


/*!
 \def CAP_GENDER
 \brief capacidade incial do array dos generos
*/
#define CAP_GENDER 500


/*!
 * @brief Estrutura responsável pela resolução da querie 8
 * 
 * É nesta estrutra que os dados derão guardados para posteriormente serem ordenados
 */
typedef struct sort_gender *SORT_GENDER;


/**
 * @brief Função que inicializa a estrutura de ordenação de dados
 * 
 * @return a estrutura já inicializada
 */
SORT_GENDER init_sort_gender();


/**
 * @brief Função que liberta a memória reservada à estrutura de ordenação
 * 
 * @param list array do qual será feita a libertação de memória 
 * @param N comprimento da array de ordenação
 */
void free_sort_gender(SORT_GENDER list, int N);


/**
 * @brief Função que preenche a estrutura de ordenação
 * 
 * @param users_list tabela de hash com as informações dos utilizadores
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com toda a informação correspondente às viagens
 * @param list estrutura onde são colocados os dados para depois ordenas 
 * @param N copmrimento da estrutura de ordenação 
 * @param gender genero dos utilizadores o condutores que se pretende colocar na estrutura
 * @param N_DRIVERS comprimento do array dos condutores
 */
int fill_sort_gender(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    SORT_GENDER *list,
    char *gender,
    int N_DRIVERS,
    int age
);


/**
 * @brief Função que compara a idade da conta de dois condutores
 * 
 * @param a elemento da estrutura de ordenação
 * @param b elemento da estrutura de ordenação
 * @return a idade da conta de a menos a idade da conta de b
 */
int cmprfunc_driver(const void *a, const void *b);


/**
 * @brief Função que compara a idade da conta de dois utilizadores
 * 
 * @param a elemento da estrutura de ordenação
 * @param b elemento da estrutura de ordenação
 * @return a idade da conta de a menos a idade da conta de b
 */
int cmprfunc_user(const void *a, const void *b);


/**
 * @brief Função que compara o id de duas viagens
 * 
 * @param a elemento da estrutura de ordenação
 * @param b elemento da estrutura de ordenação
 * @return o id da viagem de a menos o id da viagem de b
 */
int cmprfunc_id_ride(const void *a, const void *b);


/**
 * @brief Função que executa um comando correspondente à querie 8
 * 
 * @param command comando que será executado 
 * @param ncommand número do comando que será executado
 * @param users_list tabela de hash com toda a informação dos utilizadores
 * @param drivers_list array com toda a informação dos condutores
 * @param rides_list array com toda a informação correspondente às viagens
 * @param N_DRIVERS comprimento do array dos condutores
 * @param N_RIDES comprimento do array das viagens
 */
void resolve_querie8(
    char *command,
    int ncommand,
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    int N_DRIVERS
);

#endif
#ifndef QUERIE8_H
#define QUERIE8_H

#include <fixtures.h>
#include <sort.h>


/**
 \file querie8.h
 \brief Módulo para a resolução da querie 8
*/


/*!
 * @brief Estrutura responsável pela resolução da querie 8
 * 
 * É nesta estrutra que os dados derão guardados para posteriormente serem ordenados
 */
typedef struct sort_gender *SORT_GENDER;


/**
 * @brief Função que inicializa a estrutura de ordenação de dados
 * 
 * @param N_RIDES comprimento do array das viagens
 * @return a estrutura já inicializada
 */
SORT_GENDER init_sort_gender(int N_RIDES);


/**
 * @brief Função que liberta a memória reservada à estrutura de ordenação
 * 
 * @param list array do qual será feita a libertação de memória 
 * @param N comprimento da array de ordenação
 */
void free_sort_gender(SORT_GENDER list, int N);


/**
 * @brief Função que faz push de um bloco de informação na estrutura de ordenação
 * 
 * @param list array no qual serão colocadas todas as informações passadas nos argumentos
 * @param N comprimento no array
 * @param id_driver id de um condutor que será colocado na lista
 * @param name_driver nome de um condutor que será colocado na lista
 * @param account_creation_driver data da criação de conta de um condutor
 * @param username nome de perfil de um utilizador
 * @param name_user nome de um utilizador
 * @param account_creation_user data da criação de conta de um utilizador
 * @param id_rides id de um viagem que será coloado no array
 * @param account_driver string correspondente à data da criação de conta de um condutor
 * @param account_user string correspondente à data da criação de conta de um utilizador
 */
void push_sort_gender(
    SORT_GENDER list,
    int *N,
    int id_driver,
    char *name_driver,
    int account_creation_driver,
    char *username,
    char *name_user,
    int account_creation_user,
    int id_rides,
    char *account_driver,
    char *account_user
);


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
void fill_sort_gender(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    SORT_GENDER list,
    int *N,
    char *gender,
    int N_DRIVERS
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
    int N_DRIVERS,
    int N_RIDES
);

#endif
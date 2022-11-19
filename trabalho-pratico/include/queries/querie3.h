#ifndef QUERIE_3
#define QUERIE_3

#include <fixtures.h>
#include <sort.h>


/**
 \file querie3.h
 \brief Módulo para a resolução da querie 3
*/


/*!
 * @brief Estrutura responsável pelo armazenamento temporario de dados e pela sua ordenação
 * 
 * Estrutra que contem os utilizadores e as distâncias percorridas por cada um
 */
typedef struct sort_distance *SORT_DISTANCE;


/**
 * @brief Função que inicializa um estrutura de ordenação
 * 
 * @param N_RIDES
 * @return estrutura de dados onde serão colocadas as avaliações dos condutores numa dada cidade
 */
SORT_DISTANCE init_sort_distance(int N_RIDES);


/**
 * @brief Função que liberta a memória ocupada pela estrutura de ordenação
 * 
 * @param list estrtura que será removida da memória
 * @param N comprimento da estrutura 
 */
void free_sort_distance(SORT_DISTANCE list, int N);


/**
 * @brief Função que coloca as informações necessárias à ordenação dos utilizadores numa estrutura
 * 
 * @param users_list array com as informações dos utilizadores
 * @param rides_list array com as informações das viagens
 * @param list estrutura onde os utilizadores serão armazenados
 * @param N comprimento da estrutura onde estão a ser colocados os dados
 */
void fill_sort_distance(USERS users_list, RIDES rides_list, SORT_DISTANCE list, int *N);


/**
 * @brief Função que compara as distâncias percorridas por dois utilizadores
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre as distâncias percorridas por cada utilizador
 */
int compare_distance_ride(const void *a, const void *b);


/**
 * @brief Função que compara as datas de duas viagens
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre as datas das viagens
 */
int compare_recente_ride(const void *a, const void *b);


/**
 * @brief Função que compara o username de dois utilizadores
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return o mesmo valor que a função strcmp devolveria
 */
int compare_username(const void *a, const void *b);


/**
 * @brief Função que executa um comando correspondente à queire 3
 * 
 * @param command comando que será executado
 * @param ncommand número do comando a ser executado 
 * @param users_list tabela de hash com a informação dos utilizadores
 * @param rides_list array com as informações das cidades
 * @param N_RIDES tamanho do array das viagens
 */
void resolve_querie3(char *command, int ncommand, USERS users_list, RIDES rides_list, int N_RIDES);

#endif
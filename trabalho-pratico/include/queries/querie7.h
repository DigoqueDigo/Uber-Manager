#ifndef QUERIE7_H
#define QUERIE7_H

#include <fixtures.h>
#include <sort.h>


/**
 \file querie7.h
 \brief Módulo para a resolução da querie 7
*/


/*!
 * @brief Estrutura responsável pelo armazenamento temporario de dados
 * 
 * É nesta estrutra que os dados são guardados pare depois serem passados a outra estrutura
 */
typedef struct driver_city *DRIVER_CITY;


/*!
 * @brief Estrutura responsável pela ordenação dos dados
 * 
 * É nesta estrutra que os dados são ordenados conforma as indicação passadas pela querie
 */
typedef struct driver_city_list *DRIVER_CITY_LIST;


/**
 * @brief Função que adiciona uma avaliação a um condutor presente na arvore
 * 
 * @param abin arvore binaria de procura onde os condutores são armazenados segundo o id
 * @param id id de um condutors
 * @param score avaliação que se pretende adicionar à arvore
 * @param name nome de um utilizador que se pretende adicionar à arvore
 */
void push_driver_score(DRIVER_CITY *abin, int id, double score, char *name);


/**
 * @brief Função que liberta a memória ocupada por uma árvore
 * 
 * @param abin arvore que serão removida sa memória
 */
void free_cities(DRIVER_CITY abin);


/**
 * @brief Função que coloca as informações necessárias à ordenação dos dados numa arvore binária de procura
 * 
 * @param rides_list array com as informações das viagens
 * @param drivers_list array com as informações dos condutores 
 * @param cities_list array com informação complementar das cidades
 * @param city cidade na qual se pretende fazar a pesquisa
 * @param N_CITIES tamanho do array das cidades
 * @return estrutura de dados com as avaliações dos condutores numa dada cidade
 */
DRIVER_CITY fill_abin(RIDES rides_list, DRIVERS drivers_list, CITIES cities_list, char *city, int N_CITIES);


/**
 * @brief Função que calcula o número de nodos de uma árvore
 * 
 * @param abin árvore que se pretende analisar
 * @return número de nodos de uma árvore
 */
int count_nodes(DRIVER_CITY abin);


/**
 * @brief Função recursiva que converte uma arvore binaria num array
 * 
 * @param abin arvore que será convertida para um array
 * @param array estrutura para onde passarão os dados da arvore binária
 * @param index tamanho atual do array que está a ser preenchido
 */
void convert_abin_to_array(DRIVER_CITY abin, DRIVER_CITY_LIST array, int *index);


/**
 * @brief Função que compara a avaliação de dois condutores
 * 
 * @param a primeiro elemento para acomparação
 * @param b segundo elemento para acomparação
 * @return a diferença entre as avaliações
 */
int compare_score_average(const void *a,const void *b);


/**
 * @brief Função que compara o id de dois condutores
 * 
 * @param a primeiro elemento para acomparação
 * @param b segundo elemento para acomparação
 * @return a diferença entre os id's
 */
int compare_id(const void *a, const void *b);


/**
 * @brief Função que executa um comando correspondente à querie 7
 * 
 * @param command comando que será executado 
 * @param ncommand número do comando que será executado
 * @param drivers_list array com toda a informação correspondente aos condutores 
 * @param rides_list array com toda a informação correspondente às viagens
 * @param cities_list array com informação complementar às cidades
 * @param N_CITIES comprimento do array das cidades
 */
void resolve_querie7(char *command, int ncommand, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_CITIES);

#endif
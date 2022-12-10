#ifndef CITIES_H
#define CITIES_H


/**
 \file cities.h
 \brief Módulo para a manipulação das cidades
*/


/*!
 \def CAP_CITIES
 \brief capacidade incial do array das cidades
*/
#define CAP_CITIES 2


/*!
 \def CAP_CITY
 \brief capacidade incial do array dos indices de uma cidade
*/
#define CAP_CITY 100


/*!
 * @brief Estrutura responsável pelo armazenamento das cidades
 * 
 * É nesta estrutra que os dados das cidades são guardados (array dinamico)
 */
typedef struct city *CITIES; 


/**
 * @brief Função que incializa a estrutura de dados das cidades
 * 
 * @return estrutura de dados das cidades inicializada
 */
CITIES init_cities();


/**
 * @brief Função que coloca o indice de uma cidade no array das cidades
 * 
 * @param cities_list estrutura de dados das cidades
 * @param city cidades na qual se pretende colocar o indice
 * @param index indice que se pretende adicionar
 * @param N_CITIES comprimento do array das cidades
 */
void push_city(CITIES cities_list, char *city, int index, int *N_CITIES);


/**
 * @brief Função que estande a capacidade da estrutura das cidades
 * 
 * @param cities_list array das cidades que será realocado
 * @param new_size novo tamanho do array (x2)
 */
void realloc_cities(CITIES *cities_list, int new_size);


/**
 * @brief Função que remove da memória a estrutura das cidades
 * 
 * @param cities_list estrutura de dados das cidades
 * @param N_CITIES comprimento do array das cidades
 */
void free_cities_list(CITIES cities_list, int N_CITIES);


/**
 * @brief Função que indica se uma determinada cidade por ser acedida ou não
 * 
 * @param cities_list estrutura de dados das cidades
 * @param city cidade que se pretende analisar
 * @param N_CITIES comprimento do array das cidades
 * @return 1 se pode ser acedida, 0 caso contrário
 */
int analyse_city(CITIES cities_list, char *city, int N_CITIES);


/**
 * @brief Função recolhe a informação dos indices de uma certa cidade
 * 
 * @param cities_list estrutura de dados das cidades
 * @param city cidade que pretendemos recolher os indices
 * @param sp endereço no qual será guardado o número de indices de uma cidade 
 * @param N_CITIES comprimento do array das cidades
 * @return posição inicial do array com todos os indices da cidade passada como argumento
 */
int* lookup_cities_positions(CITIES cities_list, char *city, int *sp, int N_CITIES);

#endif
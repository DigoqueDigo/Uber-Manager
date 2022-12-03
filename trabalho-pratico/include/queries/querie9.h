#ifndef QUERIE_9
#define QUERIE_9

#include <fixtures.h>
#include <sort.h>

/**
 \file querie9.h
 \brief Módulo para a resolução da querie 9
*/


/*!
 \def CAP_SORT_TIP
 \brief capacidade incial do array das viagens com gorjeta
*/
#define CAP_SORT_TIP 1000


/*!
 * @brief Estrutura responsável pelo armazenamento temporario de dados e pela sua ordenação
 * 
 * Estrutra que contem as viagens entre duas determinadas datas nas quais o utilizador deu gorjeta
 */
typedef struct sort_tip *SORT_TIP;


/**
 * @brief Função que inicializa um array para guardar os dados das viagens nas quais o utilizador deu gorjeta
 * 
 * @return estrutura das viagens com gorjeta já inicializada
 */
SORT_TIP init_sort_tip();


/**
 * @brief Função que remove a estrutura de dados das viagens com gorjetas da memória
 * 
 * @param sort_tip_list estrutura de dados que se pretende remover da memória
 * @param N tamanho da estrutura de dados que se pretende remover
 */
void free_sort_tip(SORT_TIP sort_tip_list, int N);


/**
 * @brief Função que preenche a estrutura das viagens com gorjeta entre duas datas
 * 
 * @param sort_tip_list estrutura de dados que se pretende preencher
 * @param rides_list array com as informações das viagens
 * @param date_1 inteiro que representa data limite inferior
 * @param date_2 inteiro que representa data limite superior
 * @param N_RIDES comprimento do array das viagens
 * @return numero de elementos que foram inseridos na estrutura das viagens com gorjetas
 */
int fill_sort_tip(SORT_TIP *sort_tip_list, RIDES rides_list, int date_1, int date_2, int N_RIDES);


/**
 * @brief Função que compara o id de duas viagens nas quias houve gorjeta
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre os ids das viagens
 */
int compare_id_sort_tip(const void *a, const void *b);


/**
 * @brief Função que compara a distancia de duas viagens nas quias houve gorjeta
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre as distancias das viagens
 */
int compare_distance_sort_tip(const void *a, const void *b);


/**
 * @brief Função que compara o valor das gorjetas de duas viagens
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre as gorjetas das viagens
 */
int compare_date_sort_tip(const void *a, const void *b);


/**
 * @brief Função que executa um comando correspondente à queire 9
 * 
 * @param command comando que será executado
 * @param ncommand número do comando a ser executado 
 * @param rides_list array com as informações das viagens
 * @param N_RIDES comprimento do array das viagens
 */
void resolve_querie9(char *command,int ncommand, RIDES rides_list, int N_RIDES);

#endif
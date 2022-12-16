#ifndef QUERIE_2
#define QUERIE_2

#include <fixtures.h>
#include <sort.h>


/**
 \file querie2.h
 \brief Módulo para a resolução da querie 2
*/


/*!
 \def CAP_SORT_SCORE
 \brief capacidade incial do array das avaliações dos condutores
*/
#define CAP_SORT_SCORE 500


/*!
 * @brief Estrutura responsável pelo armazenamento temporario de dados e pela sua ordenação
 * 
 * Estrutra que contem os condutores e as suas respetivas avaliações medias
 */
typedef struct sort_score *SORT_SCORE;


/**
 * @brief Função que inicializa um array para guardar os dados das avaliações medias dos condutores
 * 
 * @return estrutura das avaliações medias dos condutores já inicializada
 */
SORT_SCORE init_sort_score();


/**
 * @brief Função que remove a estrutura de dados das avaliações médias dos condutores da memória
 * 
 * @param sort_score_list estrutura de dados que se pretende remover da memória
 * @param N tamanho da estrutura de dados que se pretende remover
 */
void free_sort_score(SORT_SCORE sort_score_list, int N);


/**
 * @brief Função que chama outra função de remoção de memória
 *
 */
void call_free_score_drivers();


/**
 * @brief Função que preenche a estrutura das avaliações médias dos condutores
 * 
 * @param sort_score_list estrutura de dados que se pretende preencher
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com as informações das viagens
 * @param N_DRIVERS comprimento do array dos condutores
 * @return numero de elementos que foram inseridos na estrutura das avaliações medias dos condutores
 */
int fill_sort_score(SORT_SCORE *sort_score_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS);


/**
 * @brief Função que compara as avaliações medias dois condutores
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre as avaliações medias de cada condutores
 */
int compare_score(const void *a, const void *b);


/**
 * @brief Função que compara a viagem mais recente de dois condutores
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre as viagens mais recentes dos condutores
 */
int compare_score_recent_ride(const void *a, const void *b);


/**
 * @brief Função que compara o idondutores
 * 
 * @param a primeiro elemento de comparação
 * @param b segundo elemento de comparação
 * @return diferença entre os ids dos condutores
 */
int compare_score_id(const void *a, const void *b);


/**
 * @brief Função que executa um comando correspondente à queire 2
 * 
 * @param command comando que será executado
 * @param ncommand número do comando a ser executado 
 * @param drivers_list array com as informações dos condutores
 * @param rides_list array com as informações das viagens
 * @param N_DRIVERS tamanho do array dos condutores
 */
void resolve_querie2(char *command, int ncommand, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS);

#endif
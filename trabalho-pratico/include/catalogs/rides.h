#ifndef RIDES_H
#define RIDES_H


/**
 \file rides.h
 \brief Módulo para a manipulação das viagens
*/


/*!
 \def CAP_RIDES
 \brief Capacidade inicial do array que contem as viagens
*/
#define CAP_RIDES 100000


/*!
 \def T_BASIC
 \brief Preço da tarifa inical na class basic
*/
#define T_BASIC 3.25


/*!
 \def T_GREEN
 \brief Preço da tarifa inicial na class green
*/
#define T_GREEN 4


/*!
 \def T_PREMIUM
 \brief Preço da tarifa inicial na class premium
*/
#define T_PREMIUM 5.2


/*!
 \def TK_BASIC
 \brief Preço da tarifa por quilometro na class basic
*/
#define TK_BASIC 0.62


/*!
 \def TK_GREEN
 \brief Preço da tarifa por quilometro na class green
*/
#define TK_GREEN 0.79


/*!
 \def TK_PREMIUM
 \brief Preço da tarifa por quilometro na class premium
*/
#define TK_PREMIUM 0.94


/*!
 * @brief Estrutura responsável pelo armazenamento das viagens
 * 
 * É nesta estrutra que os dados das viagens são guardados (array dinamico)
 */
typedef struct ride *RIDES;


/**
 * @brief Função que incializa a estrutura de dados da viagens
 * 
 * @return estrutura de dados da viagens inicializada
 */
struct ride* init_ride_list();


/**
 * @brief Função que espande a capacidade da estrutura das viagens
 * 
 * @param rides_list array das viagens que será realocado
 * @param new_size novo tamanho do array (x2)
 * @return estrutura de dados realodada
 */
RIDES realloc_rides(RIDES rides_list, int new_size);


/**
 * @brief Função que adiciona um viagem à estrutura de dados das viagens (a viagem é criada na própria função)
 * 
 * @param lista array das viagens e ao qual será adicionado um viagem
 * @param id numero da viagem
 * @param date data da realização da viagem
 * @param driver id do condutor
 * @param user username do utilizador
 * @param city cidade onde se realizou a viagem
 * @param distance distancia percorrida durante a viagem
 * @param score_user avaliação do utilizador
 * @param score_driver avaliaçao do condutor
 * @param tip gorjeta oferece na viagem
 */
void push_ride(
    RIDES lista,
    char *id,
    char *date,
    char *driver,
    char *user,
    char *city,
    char *distance,
    char *score_user,
    char *score_driver,
    char *tip
);


/**
 * @brief Função liberta a memória utilizada pelo array das viagens
 * 
 * @param rides_list array que será destuido e removido da memória
 * @param N_RIDES número de elementos que o array contem (número de viagens realizadas)
 */
void free_rides(RIDES rides_list, int N_RIDES);


// MANAGER

int analyse_ride(RIDES rides_list, int index);

/**
 * @brief Função que recolhe o id de um condutor
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return id do contudor na viagem mencionada pelo indice
 */
int lookup_id_driver(RIDES rides_list, int index);


/**
 * @brief Função que recolhe o username de um utilizador
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @param username string para a qual será copiado o o username presente na viagem
 */
void lookup_rides_username(RIDES rides_list, int index, char *username);


/**
 * @brief Função que recolhe a data de uma viagem
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return apontador com a data da viagem
 */
char* lookup_rides_date(RIDES rides_list, int index);


/**
 * @brief Função que recolhe a distancia percorrida numa viagem 
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return distancia da viagem data pelo indice
 */
int lookup_rides_distance(RIDES rides_list, int index);


/**
 * @brief Função que recolhe a cidade onde uma viagem foi realizada
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return apondador com a cidade onde foi realizada a viagem
 */
char* lookup_rides_city(RIDES rides_list, int index);


/**
 * @brief Função que recolhe o id de um condutor de forma segura
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return id do contudor na viagem mencionada pelo indice
 */
int lookup_rides_id_driver(RIDES rides_list, int index);


/**
 * @brief Função que recolhe a gorjeta de uma viagem
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return gorjeta correspondente à viagem indica pelo indice
 */
double lookup_rides_tip(RIDES rides_list, int index);


/**
 * @brief Função que recolhe a avaliação de um condutor
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return avaliação de um condutor na viagem indicada pelo indice
 */
double lookup_rides_score_driver(RIDES rides_list, int index);


/**
 * @brief Função que recolhe a avaliação de um utilizador
 * 
 * @param rides_list estrutura de dados das viagens
 * @param index indice na viagem no qual será feita a recolha
 * @return avaliação de um utilizador na viagem indicada pelo indice
 */
int lookup_rides_score_user(RIDES rides_list, int index);

#endif
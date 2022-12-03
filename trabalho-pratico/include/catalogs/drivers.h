#ifndef DRIVERS_H
#define DRIVERS_H


/**
 \file drivers.h
 \brief Módulo para a manipulação dos condutores
*/


/*!
 \def CAP_DRIVER
 \brief capacidade incial do array dos indices de um condutor
*/
#define CAP_DRIVER 100

/*!
 \def CAP_DRIVERS
 \brief capacidade incial do array dos contudores
*/
#define CAP_DRIVERS 5000


/*!
 * @brief Estrutura responsável pelo armazenamento dos condutores
 * 
 * É nesta estrutra que os dados dos condutores são guardados (array dinamico)
 */
typedef struct driver *DRIVERS;


/**
 * @brief Função que inicializa a estrutura dos condutores
 * 
 * @return estrutura dos condutores inicializada
 */
DRIVERS init_drivers();


/**
 * @brief Função que espande a capacidade da estrutura daos condutores
 * 
 * @param drivers_list array dos condutores que será realocado
 * @param new_size novo tamanho do array (x2)
 */
void realloc_drivers(DRIVERS *drivers_list, int new_size);


/**
 * @brief Função que adiciona um condutor à estrutura dos mesmo (o condutor é criado na própria função)
 * 
 * @param lista estrutura de dados dos condutores e na qual será inserido o condutor
 * @param id numero do condutor a ser inserido
 * @param name nome do condutor
 * @param birth_date data de nascimento do condutor
 * @param gender genero do condutor
 * @param car_class classe do carro utilizado pelo condutor
 * @param license_plate matricula do carro do condutor
 * @param city cidade do condutor
 * @param account_creation data ed criação de conta
 * @param account_status estado da conta do condutor
 */
void push_driver(
    DRIVERS lista,
    char *id,
    char *name,
    char *birth_date,
    char *gender,
    char *car_class,
    char *license_plate,
    char *city,
    char *account_creation,
    char *account_status
);


/**
 * @brief Função que adiciona um indice a um condutor
 * 
 * @param lista estrutura de dados dos condutores
 * @param position indice que será inserido
 * @param driver_id id do condutor ao qual se pretende adicionar o indice
 */
void push_position_driver(DRIVERS lista, int position, char *driver_id);


/**
 * @brief Função que indica que um condutor é inválido
 *
 * @param drivers_list estrutura de dados dos condutores
 * @param index id cujo o condutor é inválido
 */ 
void push_null_driver(DRIVERS drivers_list, int index);


/**
 * @brief Função destroi a estrutura do condutores
 * 
 * @param drivers_list estrutura que será removida da memória
 * @param N_DRIVERS número de condutores que a lista o array possui
 */
void free_drivers(DRIVERS drivers_list, int N_DRIVERS);


// MANAGER

/**
 * @brief Função que analisa se um condutor está disponivel
 * 
 * @param drivers_list estrutura que será removida da memória
 * @param index id do condutor que se pretende analisar
 */
int analyse_driver(DRIVERS drivers_list, int index);


/**
 * @brief Função recolhe informação da classe do carro de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @param car_class string para a qual será copiada a classe do carro
 */
void lookup_car_class(DRIVERS drivers_list, int index, char *car_class);


/**
 * @brief Função recolhe os indices de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @param sp endero no qual será o numero de indices de um dado condutor
 * @return endereço na primeira posição do array dos indices
 */
int* lookup_driver_positions(DRIVERS drivers_list, int index, int *sp);


/**
 * @brief Função recolhe o nome de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @param name string para a qual será copiado o nome do condutor
 */
void lookup_driver_name(DRIVERS drivers_list, int index, char *name);


/**
 * @brief Função recolhe a data de criação de conta de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @param account_creation string para a qual será copiada a data de criação de conta do condutor
 */
void lookup_driver_account_creation(DRIVERS drivers_list, int index, char *account_creation);


/**
 * @brief Função recolhe o genero de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @param gender string para a qual será copiado o genero de um condutor
 */
void lookup_driver_gender(DRIVERS drivers_list, int index, char *gender);


/**
 * @brief Função que indica o estado da conta de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @return 1 se a conta está ativa, 0 caso estaja inativa
 */
int lookup_driver_accounts_status(DRIVERS drivers_list, int index);


/**
 * @brief Função recolhe a data de aniversário de um condutor
 * 
 * @param drivers_list estrutura de dados dos condutores
 * @param index id do condutor que pretendemos encontrar
 * @param date string para a qual será copiada a data de aniversário do condutor
 */
void lookup_driver_birth_date(DRIVERS drivers_list, int index, char *date);

#endif
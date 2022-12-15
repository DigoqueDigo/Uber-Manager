#ifndef CHECKER_H
#define CHECKER_H


/**
 \file checker.h
 \brief Módulo para a validação dos dados
*/


/**
 * @brief Função que valida os dados referentes a um id
 * 
 * @param string segmento de memória que contem um id
 * @return 1 se o id recebido no é válido, 0 caso não seja 
 */
int check_id(char *string);


/**
 * @brief Função que valida os dados referentes a um nome
 * 
 * @param string segmento de memória que contem oum nome
 * @return 1 se o nome recebido é válido, 0 caso não seja
 */
int check_name(char *string);


/**
 * @brief Função que valida os dados referentes a uma data
 * 
 * @param string segmento de memória que contem uma data 
 * @return 1 se a data é válido, 0 caso não seja
 */
int check_date(char *string);


/**
 * @brief Função que valida os dados referentes a um genero
 * 
 * @param string segmento de memória que contem um genero 
 * @return 1 se o genero é válido, 0 caso não seja
 */
int check_gender(char *string);


/**
 * @brief Função que valida os dados referentes a uma classe de carro 
 * 
 * @param string segmento de memória que contem a classe de um carro
 * @return 1 se a classe é válida, 0 caso não seja
 */
int check_car_class(char *string);


/**
 * @brief Função que valida os dados referentes a um cidade
 * 
 * @param string segmento de memória que contem uma cidade
 * @return 1 se a cidade é válida, 0 caso não seja
 */
int check_city(char *string);


/**
 * @brief Função que valida os dados referentes a uma data de criação de conta
 * 
 * @param string segmento de memória que contem uma data de criação de conta 
 * @return 1 se a data de criação de conta é válida, 0 caso não seja
 */
int check_account_creation(char *string);


/**
 * @brief Função que valida os dados referentes ao estado de uma conta
 * 
 * @param string segmento de memória que contem o estado de uma conta
 * @return 1 se o estado da conta é válido, 0 caso não seja
 */
int check_account_status(char *string);


/**
 * @brief Função que valida os dados referentes a uma matrícula
 * 
 * @param string segmento de memória que contem uma matrícula
 * @return 1 se a matrícula é válida, 0 caso não seja
 */
int check_license_plate(char *string);


/**
 * @brief Função que valida os dados referentes a um método de pagamento
 * 
 * @param string segmento de memória que contem um método de pagamento
 * @return 1 se o método de pagamento é válido, 0 caso não seja
 */
int check_pay_method(char *string);


/**
 * @brief Função que valida os dados referentes a um username
 * 
 * @param string segmento de memória que contem um username 
 * @return 1 se o username é válido, 0 caso não seja
 */
int check_username(char *string);


/**
 * @brief Função que valida os dados referentes a uma gorjeta
 * 
 * @param string segmento de memória que contem um grojeta
 * @return 1 se a gorjeta é válida, 0 caso não seja
 */
int check_tip(char *string);


/**
 * @brief Função que valida os dados referentes a uma distancia
 * 
 * @param string segmento de memória que contem uma distancia
 * @return 1 se a distancia é válida, 0 caso não seja
 */
int check_distance(char *string);

#endif
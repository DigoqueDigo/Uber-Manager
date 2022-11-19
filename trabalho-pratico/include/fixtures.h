#ifndef FIXTURES_H
#define FIXTURES_H

#include <catalogs/users.h>
#include <catalogs/drivers.h>
#include <catalogs/rides.h>
#include <catalogs/cities.h>


/**
 \file fixtures.h
 \brief Módulo para funções de uso geral
*/


/**
 * @brief Função que a partir de uma data calcula uma idade
 * 
 * @param birth_date data que se pretence saber a idade
 * @return anos correspondente à data passada no argumento
 */
int calculate_idade(char *birth_date);


/**
 * @brief Função que trasnforma uma string passa em argumento numa data
 * 
 * @param string zona de memória na qual será guardada a data criada
 * @param age idade a partir da qual será calculada a nova data
 */
void creat_date(int age, char *string);


/**
 * @brief Função que convert um inteiro num id
 * 
 * @param string zona de memória onde será guardado o id resultante
 * @param id inteiro que será convertido num id
 */
void convert_id_to_string(char *string, int id);


/**
 * @brief Função que convert uma data num inteiro
 * 
 * @param string data a partir da qual será calculado um inteiro
 * @return inteiro resultante da conversão
 */
int convert_date_to_int(char *string);


/**
 * @brief Função que cria o nome do ficheiro de output
 * 
 * @param command string na qual será guardado o nome do ficheiro de output
 * @param N indixe do comando
 */
void set_command_name(char *command, int N);

#endif
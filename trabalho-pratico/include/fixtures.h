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


/**
 * @brief Função que cria o nome do ficheiro de output conforme uma diretoria
 * 
 * @param file_path string na qual será guardado o nome do ficheiro de output
 * @param N indixe do comando
 * @param sub_path diretoria a partir da qual é criado no nome do ficheiro de output
 */
void set_outfile_name(char *file_path, int N, char *sub_path);

#endif
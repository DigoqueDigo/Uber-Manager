#ifndef DIFF_H
#define DIFF_H

#include <fixtures.h>
#include <tests/test.h>


/**
 \file diff.h
 \brief Módulo para a validação de testes
*/


/**
 * @brief Função que compara dois ficheiros resultantes da execução de um comando
 * 
 * @param source ficheiro com o resultado obtido através da execução dos comandos
 * @param test ficheiro com o resultado correto da execução de um comando
 * @param obtained string para a qual será copiada a primeira linha de divergencia no ficheiro source 
 * @param expected string para a qual será copiada a primeira linha de divergencia no ficheiro test
 * @return 1 se os ficheiros são iguais, caso contrário 0
 */
int compare_two_files(FILE *source, FILE *test, char *obtained, char *expected);


/**
 * @brief Função que compara todos os ficheiros de texto resultantes da execução de vários comandos
 * 
 * @param tests_list estrutura de dados onde será colocada o valor da analise de cada comando
 * @param N_TESTS numero de ficheiros que se pretende analisar
 * @param test_path diretoria que contem os ficheiros válidos, e a partir dos quais serão feitas as comparações
 */
void set_all_comparations(TESTS tests_list, int N_TESTS, char *test_path);

#endif
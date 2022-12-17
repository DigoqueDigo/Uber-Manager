#ifndef TEST_H
#define TEST_H

#include <interactive/terminal.h>


/**
 \file test.h
 \brief Módulo para o controlo dos testes
*/


/*!
 \def CAP_TESTS
 \brief Capacidade inicial que o array de testes possui
*/
#define CAP_TESTS 5


/*!
 * @brief Estrutura responsável pelo armazenamento dos dados relativos aos testes
 * 
 * Esta estrutura consitui um array dinâmico
 */
typedef struct test *TESTS;


/**
 * @brief Função que inicializa a estrtura de dados dos testes
 * 
 * @return estutura de dados já inicializada
 */
TESTS init_tests();


/**
 * @brief Função que estende o comprimento da estrutura de testes
 * 
 * @param tests_list estrtura de dados que será realocada
 * @param new_size novo tamanho da estrtura de dados
 */
void realloc_tests(TESTS *tests_list, int new_size);


/**
 * @brief Função que coloca alguns dados relativos a um determinado teste na estrutura de dados principal
 * 
 * @param tests_list estrutura de dados na qual será colocado o novo teste
 * @param query analise que foi executada
 * @param time tempo que foi necessário para fazer a análise
 * @param N_TESTS numero de elementos que a estrtura de dados dos testes possui
 * @param SIZE_TESTS capacidade total da estrtura de dados dos testes
 */
void push_test(TESTS *tests_list, char *query, double time, int *N_TESTS, int *SIZE_TESTS);


/**
 * @brief Função que coloca alguns dados relativos à validação um determinado teste na estrutura de dados principal
 * 
 * @param tests_list estrutura de dados na qual será colocado o novo teste
 * @param index indice no qual pretendemos inserir os dados de validação
 * @param checker indicador da válidade de um testes, 1 - válido, 0 - inválido
 * @param obtained resultado que se obteve na execução
 * @param expected resultados que se esperarir obter
 */
void push_test_comparation(TESTS tests_list, int index, short int checker, char *obtained, char *expected);


/**
 * @brief Função que remove a memória alocada pela estrutura de dados dos testes
 * 
 * @param tests_list estrutura de dados que se pretende remover da memória
 * @param N_TESTS numero de testes que estão na estrutura dos testes
 */
void free_tests(TESTS tests_list, int N_TESTS);


/**
 * @brief Função que imprime palavras no terminal ou numm ficheiro
 * 
 * @param sintax parametro que indica com as palavras serão impressas
 * @param ficheiro ficheiro no qual serão escritas as palavras
 */
void print(char *sintax, FILE *ficheiro, ...);

/**
 * @brief Função que imprime o conteudo da estrutura de dados dos testes
 * 
 * @param tests_list estrutura de dados que se pretende remover da memória
 * @param N_TESTS numero de testes que estão na estrutura dos testes
 * @param catalogs_time array com outros tempos de execução
 * @param test_file ficheiro no qual serão escritos os resultados do teste
 */
void print_tests(TESTS tests_list, int N_TESTS, double *catalogs_time, char *test_file);

#endif
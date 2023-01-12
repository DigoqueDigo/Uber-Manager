#ifndef TERMINAL_H
#define TERMINAL_H


/**
 \file terminal.h
 \brief Módulo para funções referentes ao terminal
*/


/**
 * @brief Função que indica o numero de linhas do terminal
 * 
 * @return numero de linhas do terminal
 */
int get_terminal_lines();


/**
 * @brief Função que indica o numero de colunas do terminal
 * 
 * @return numero de linhas do terminal
 */
int get_terminal_columns();


/**
 * @brief Função que imprime um determinado numero de linhas vazia
 * 
 * @param N numero de linhas vazia que se pretende imprimir
 */
void print_empty_lines(int N);


/**
 * @brief Função que imprime um determinado numero de caracteres '-'
 * 
 * @param N numero de caracteres que se pretende imprimir
 * @param ficheiro ficheiro no qual se pretende imprimir
 */
void print_separator_line(int N, FILE *ficheiro);


/**
 * @brief Função que indica o numero de linhas que um ficheiro de texto possui
 * 
 * @param ficheiro ficheiro que se pretende analisar
 * @return numero de linhas do ficheiro em questão
 */
int get_file_lines(FILE *ficheiro);

#endif
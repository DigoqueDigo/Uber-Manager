#ifndef TERMINAL_H
#define TERMINAL_H


/**
 \file terminal.h
 \brief Módulo para funções referentes ao terminal
*/


//int get_terminal_lines();

//int get_terminal_columns();


/**
 * @brief Função que imprime um determinado numero de linhas vazia
 * 
 * @param N numero de linhas vazia que se pretende imprimir
 */
void print_empty_lines(int N);


/**
 * @brief Função que indica o numero de linhas que um ficheiro de texto possui
 * 
 * @param ficheiro ficheiro que se pretende analisar
 * @return numero de linhas do ficheiro em questão
 */
int get_file_lines(FILE *ficheiro);

#endif
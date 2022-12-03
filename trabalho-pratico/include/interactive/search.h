#ifndef SEARCH_H
#define SEARCH_H

#include <parsing/checker.h>
#include <interactive/pagination.h>


/**
 \file search.h
 \brief Módulo para funções de pesquisa de palavras
*/


/**
 * @brief Função que indica o numero de vezes que uma dada palavra ocorre
 * 
 * @param ficheiro ficheiro que se pretende analisar
 * @param word palavra que se pretende pesquisar
 * @param matches numero de vezes que a palavra ocorre no fichiero
 * @return numero de linhas em que a palavra ocorre
 */
int count_matches(FILE *ficheiro, char *word, int *matches);


/**
 * @brief Função que imprime os resultados de uma pesquisa
 * 
 * @param ficheiro ficheiro que se pretende analisar
 * @param word palavra que se pretende pesquisar
 * @param page numero da pagina a que se pretende aceder
 * @param pages numero que paginas resultantes da pesquisa de uma palavra 
 * @param terminal_lines numero de linhas que podem ser usadas pelo terminal
 */
void print_search(FILE *ficheiro, char *word, int page, int pages, int terminal_lines);


/**
 * @brief Função que controla o modo de pesquisa
 * 
 * @param ficheiro ficheiro que se pretende analisar
 * @param word palavra que se pretende pesquisar
 * @param terminal_lines numero de linhas que podem ser usadas pelo terminal
 */
void search_mode(FILE *ficheiro, char *word, int terminal_lines);

#endif
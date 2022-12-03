#ifndef PAGINATION_H
#define PAGINATION_H

#include <parsing/checker.h>
#include <interactive/terminal.h>
#include <interactive/search.h>


/**
 \file pagination.h
 \brief Módulo para funções de paginação
*/


/**
 * @brief Função que calcula o numero total de paginas que um dado ficheiro/comando pode gerar
 * 
 * @param lines numero de linhas que o ficheiro/comando gerou
 * @param terminal_lines numero de linhas que podem ser usadas pelo terminal
 * @return numero de paginas que as linhas ocupam
 */
int get_total_pages(int lines, int terminal_lines);


/**
 * @brief Função que imprime um dada pagina
 * 
 * @param ficheiro ficheiro que contem o conteudo que se deve imprimir
 * @param page pagina à qual se pretende aceder
 * @param pages numero de paginas geradas pelo ficheiro
 * @param terminal_lines numero de linhas que podem ser usadas pelo terminal
 */
void print_page(FILE *ficheiro, int page, int pages, int terminal_lines);


/**
 * @brief Função que controlo o modo de navegação nas páginas
 * 
 */
void page_browser();

#endif
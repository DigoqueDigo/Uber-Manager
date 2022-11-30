#ifndef PAGINATION_H
#define PAGINATION_H

#include <interactive/terminal.h>


int get_total_pages(int lines, int terminal_lines);

void print_page(FILE *ficheiro, int page);

#endif
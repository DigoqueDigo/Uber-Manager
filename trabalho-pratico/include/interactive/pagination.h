#ifndef PAGINATION_H
#define PAGINATION_H

#include <parsing/checker.h>
#include <interactive/terminal.h>
#include <interactive/search.h>


int get_total_pages(int lines, int terminal_lines);

void print_page(FILE *ficheiro, int page, int pages, int terminal_lines);

void page_browser();

#endif
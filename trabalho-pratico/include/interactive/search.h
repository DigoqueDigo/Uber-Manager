#ifndef SEARCH_H
#define SEARCH_H

#include <parsing/checker.h>
#include <interactive/pagination.h>

int count_matches(FILE *ficheiro, char *word, int *matches);

void print_search(FILE *ficheiro, char *word, int page, int pages, int terminal_lines);

void search_mode(FILE *ficheiro, char *word, int terminal_lines);

#endif
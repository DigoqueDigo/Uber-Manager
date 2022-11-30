#include <stdio.h>
#include <stdlib.h>
#include <interactive/pagination.h>



int get_total_pages(int lines, int terminal_lines){

    int pages = lines/terminal_lines;

    if (lines % terminal_lines) pages++;

    return pages;
}



void print_page(FILE *ficheiro, int page){

    char string[1000];
    
    int total_lines, terminal_lines, pages, p = 0;

    total_lines = get_file_lines(ficheiro);
    terminal_lines = get_terminal_lines();

    pages = get_total_pages(total_lines,terminal_lines);

    if (total_lines == -1 || terminal_lines < 0) return;

    if (page < pages){

        int start = page*terminal_lines, end = start + terminal_lines;
        
        for (; fgets(string, 1000, ficheiro); p++){

            if (start < p && p < end) printf("%s", string);
        }
    }

    else printf("Não foi possivel identificas essa página\n");

    print_empty_lines(terminal_lines-p);
}

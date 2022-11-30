#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <interactive/pagination.h>



int get_total_pages(int lines, int terminal_lines){

    int pages = lines/terminal_lines;

    if (lines % terminal_lines) pages++;

    return pages;
}



void print_page(FILE *ficheiro, int page, int pages, int terminal_lines){

    int p = 0;
    char string[1000];

    fseek(ficheiro, 0, SEEK_SET);

    if (page < pages){

        int start = page*terminal_lines, end = start + terminal_lines;
        
        for (int i = 0; fgets(string, 1000, ficheiro); i++){

            if (start <= i && i < end){
                
                printf("%d\t%s", i+1, string);
                p++;
            }
        }
    }

    else if (!pages){
        
        printf("A querie não gerou qualquer output\n");
        p++;
    }
    
    else if (page >= pages){
        
        printf("Não foi possivel identificar a página %d\n", page);
        p++;
    }


    print_empty_lines(terminal_lines-p);
}



void page_browser(){

    FILE *ficheiro = fopen("Resultados/command1_output.txt", "r");

    char string[1000] = "";
    int total_lines, terminal_lines, pages, page = 0;

    if (ficheiro == NULL){

        perror("Resultados/command1_output.txt");
        return;
    }

    
    total_lines = get_file_lines(ficheiro);
    terminal_lines = 55;
    //terminal_lines = get_terminal_lines();
    pages = get_total_pages(total_lines,terminal_lines);

    print_page(ficheiro,0,pages,terminal_lines);            
    

    while (strstr(string,"quit") == NULL){

        printf("Nagevador de páginas [%d...%d] (%d) >>> ", 0, pages-1, page);

        if (fgets(string, 1000, stdin)){

            string[strlen(string)-1] = '\0'; 


            if (check_id(string)){

                page = atoi(string);
                print_page(ficheiro,page,pages,terminal_lines);
            }
        }
    }


    fclose(ficheiro);

    remove("Resultados/command1_output.txt");
}
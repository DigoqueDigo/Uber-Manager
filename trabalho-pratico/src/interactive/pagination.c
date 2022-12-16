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

    fseek(ficheiro,0,SEEK_SET);

    if (page < pages){

        int start = page*terminal_lines, end = start + terminal_lines;
        
        for (int i = 0; fgets(string, 1000, ficheiro); i++){

            if (start <= i && i < end){
                
                printf("%d\t%s", i+1, string);
                p++;
            }
        }
    }
    
    else{
        
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

    if (!pages){
        
        printf("A querie não gerou qualquer resultado\n");
        print_empty_lines(terminal_lines-1);
    }

    else print_page(ficheiro,0,pages,terminal_lines);            
    

    while (strstr(string,"quit") == NULL){

        printf("Nagevador de páginas [%d...%d] (%d) >>> ", 0, pages-1, page);

        if (fgets(string, 1000, stdin)){

            string[strlen(string)-1] = '\0'; 

            if (!pages){
                
                printf("A querie não gerou qualquer resultado\n");
                print_empty_lines(terminal_lines-1);
            }

            else if (check_page(string)){

                if (string[0] != '\0') page = atoi(string);

                print_page(ficheiro,page,pages,terminal_lines);
            }

            else if (string[0] == '/'){
                
                search_mode(ficheiro,string,terminal_lines);
                print_page(ficheiro,page,pages,terminal_lines);
            }

            else{

                printf("Não foi possivel identificar o comando\n");
                print_empty_lines(terminal_lines-1);
            }
        }
    }


    fclose(ficheiro);

    print_empty_lines(terminal_lines);

    remove("Resultados/command1_output.txt");
}
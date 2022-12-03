#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <interactive/search.h>



int count_matches(FILE *ficheiro, char *word, int *matches){

    int p, aux = strlen(word);
    char string[1000];

    fseek(ficheiro,0,SEEK_SET);

    for (p = 0; fgets(string, 1000, ficheiro);){

        if (strstr(string,word)){
            
            char *token = strstr(string,word);

            for (; token; token += aux, token = strstr(token,word), ++*matches);

            p++;
        }
    }

    return p;
}


void print_search(FILE *ficheiro, char *word, int page, int pages, int terminal_lines){
    
    int p = 0, printed_lines = 0;
    char string[1000];

    fseek(ficheiro,0,SEEK_SET);

    if (page < pages){

        int start = page*terminal_lines, end = start + terminal_lines;
        
        for (int i = 0; fgets(string, 1000, ficheiro); i++){

            if (strstr(string,word)){

                if (start <= p && p < end){
                    
                    printf("%d\t%s", i+1, string);
                    printed_lines++;
                }

                p++;
            }
        }
    }

    else if (!pages){

        printf("Não foi encontrada qualquer correspondência com a palavra %s\n", word);
        printed_lines++;
    }

    else if (page >= pages){

        printf("Não foi possivel identificar a página %d\n", page);
        printed_lines++;
    }

    print_empty_lines(terminal_lines-printed_lines);
}



void search_mode(FILE *ficheiro, char *word, int terminal_lines){

    int pages, total_lines, page = 0, matches = 0;
    char string[1000] = "";

    fseek(ficheiro,0,SEEK_SET);

    word += 2;

    total_lines = count_matches(ficheiro,word,&matches);
    pages = get_total_pages(total_lines,terminal_lines);

    /*printf("total_lines: %d\n", total_lines);
    printf("pages: %d\n", pages);
    printf("matches: %d\n", matches);*/
    
    print_search(ficheiro,word,0,pages,terminal_lines);
    
    while (strstr(string,"quit") == NULL){

        printf("Pesquisa de palavras || %s :: %d || [%d...%d] (%d) >>> ", word, matches, 0, pages-1, page);

        if (fgets(string, 1000, stdin)){

            string[strlen(string)-1] = '\0';

            if (check_id(string)){

                page = atoi(string);
                print_search(ficheiro,word,page,pages,terminal_lines);
            }

            else{

                printf("Não foi possivel identificar o comando\n");
                print_empty_lines(terminal_lines-1);
            }
        }
    }

    print_empty_lines(terminal_lines);
}


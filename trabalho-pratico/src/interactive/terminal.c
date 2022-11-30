#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <error.h>
#include <interactive/terminal.h>


int get_terminal_lines(){

    static char termbuf[2048];

    char *termtype = getenv("TERM");

    if (tgetent(termbuf, termtype) < 0){
        
        printf("Não foi possivel extrair as linhas do terminal\n");
        return -1;
    }

    return (tgetnum("li") - 1);
}


void print_empty_lines(int N){

    for (int p = 0; p < N; p++){

        printf("\n");
    }
}


int get_file_lines(FILE *ficheiro){

    int p;
    char string[1000];

    if (ficheiro == NULL){

        perror("Resultados/command1_output.txt");
        return -1;
    }

    for (p = 0; fgets(string, 1000, ficheiro); p++);

    return p;
}
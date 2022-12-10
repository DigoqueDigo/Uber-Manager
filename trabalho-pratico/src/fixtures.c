#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fixtures.h>


int calculate_idade(char *birth_date){
    int i = 0;
    char string[5];
    for (int p = 6; p < 10; p++, i++){
        string[i] = birth_date[p];
    }
    string[i] = '\0';
    i = (2022 - atoi(string));
    if (birth_date[3] == '1' && birth_date[4] > '0') i--;
    else if (birth_date[3] == '1' && birth_date[0] > '0') i--;
    return i;
}


int convert_date_to_int(char *string){
    string[2] = string[5] = '\0';
    int a = atoi(string), b = atoi(string+3), c = atoi(string+6);
    string[2] = string[5] = '/';
    return (a + (b<<5) + (c<<9));
}


void set_command_name(char *command, int N){
    char index_command[20];
    sprintf(index_command, "%d", N);
    strcat(command,"Resultados/command");
    strcat(command,index_command);
    strcat(command,"_output.txt");
}


void set_outfile_name(char *file_path, int N, char *sub_path){
    char index[20];
    sprintf(index, "%d", N);
    strcpy(file_path,sub_path);
    strcat(file_path,"/command");
    strcat(file_path,index);
    strcat(file_path,"_output.txt");
}
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


void creat_date(int age, char *string){
    char aux[10];
    age = 2022 - age; 
    sprintf(aux, "%d", (unsigned short)age);
    strcpy(string,"09/10/");
    strcat(string,aux);
}


void convert_id_to_string(char *string, int id){
    int p;
    char aux[15];
    sprintf(aux, "%d", id);
    id = 12 - strlen(aux);
    for (p = 0; p < id; p++) string[p] = '0';
    for (int i = 0; p < 12; i++, p++) string[p] = aux[i];
    string[p] = '\0';
}


int convert_date_to_int(char *string){
    char day[3], month[3], year[5];
    day[0] = string[0]; day[1] = string[1]; day[2] = '\0';
    month[0] = string[3]; month[1] = string[4]; month[2] = '\0';
    year[0] = string[6]; year[1] = string[7]; year[2] = string[8]; year[3] = string[9]; year[4] = '\0';
    return (atoi(day) + 100*atoi(month) + 10000*atoi(year));
}


void set_command_name(char *command, int N){
    char index_command[20];
    sprintf(index_command, "%d", N);
    strcat(command,"Resultados/command");
    strcat(command,index_command);
    strcat(command,"_output.txt");
}
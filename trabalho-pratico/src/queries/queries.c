#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/queries.h>
#include <queries/querie1.h>
#include <queries/querie3.h>
#include <queries/querie8.h>


int resolve_queries(char *path, USERS users_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS, int N_RIDES){

    FILE *commands;

    char linha[1000];

    commands = fopen(path, "r");

    if (commands == NULL){
        perror(path);
        return -1;
    }


    for (int p = 1; fgets(linha, 1000, commands) != NULL; p++){

        int index = linha[0] - '0';


        switch (index){

            case 1: 
                resolve_querie1(linha,p,users_list,drivers_list,rides_list,N_DRIVERS);
                break;

            case 3:
                resolve_querie3(linha,p,users_list,rides_list,N_RIDES);
                break;

            case 8:
                resolve_querie8(linha,p,users_list,drivers_list,rides_list,N_DRIVERS,N_RIDES);
                break;


        }


    }

    fclose(commands);

    return 0;
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/queries.h>
#include <queries/querie1.h>
#include <queries/querie2.h>
#include <queries/querie3.h>
#include <queries/querie4.h>
#include <queries/querie5.h>
#include <queries/querie6.h>
#include <queries/querie7.h>
#include <queries/querie8.h>
#include <queries/querie9.h>



void resolve_queries(char *command, char ncommand, USERS users_list, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_DRIVERS, int N_RIDES, int N_CITIES){

    int index = command[0] - '0';

    switch (index){

        case 1: 
            resolve_querie1(command,ncommand,users_list,drivers_list,rides_list,N_DRIVERS);
            break;

        case 2:
            resolve_querie2(command,ncommand,drivers_list,rides_list,N_DRIVERS);
            break;

        case 3:
            resolve_querie3(command,ncommand,users_list,rides_list);
            break;

        case 4:
            resolve_querie4(command,ncommand,drivers_list,rides_list,cities_list,N_CITIES);
            break;

        case 5:
            resolve_querie5(command,ncommand,drivers_list,rides_list,N_RIDES);
            break;

        case 6:
            resolve_querie6(command,ncommand,rides_list,cities_list,N_CITIES);
            break;

        case 7:
            resolve_querie7(command,ncommand,drivers_list,rides_list,cities_list,N_CITIES);
            break;

        case 8:
            resolve_querie8(command,ncommand,users_list,drivers_list,rides_list,N_DRIVERS);
            break;

        case 9:
            resolve_querie9(command,ncommand,rides_list,N_RIDES);
            break;
    }
}



int resolve_queries_batch(char *path, USERS users_list, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_DRIVERS, int N_RIDES, int N_CITIES){

    FILE *input;

    char linha[1000];

    input = fopen(path, "r");

    if (input == NULL){
        
        perror(path);
        return -1;
    }

    for (int p = 1; fgets(linha, 1000, input) != NULL; p++){

        resolve_queries(linha,p,users_list,drivers_list,rides_list,cities_list,N_DRIVERS,N_RIDES,N_CITIES);
    }

    fclose(input);

    return 0;
}
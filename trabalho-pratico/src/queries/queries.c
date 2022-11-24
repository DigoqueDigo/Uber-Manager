#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/queries.h>
#include <queries/querie1.h>
#include <queries/querie2.h>
#include <queries/querie3.h>
#include <queries/querie4.h>
#include <queries/querie6.h>
#include <queries/querie7.h>
#include <queries/querie8.h>
#include <queries/querie9.h>



int resolve_queries(char *path, USERS users_list, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_DRIVERS, int N_RIDES, int N_CITIES){

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

            case 2:
                resolve_querie2(linha,p,drivers_list,rides_list,N_DRIVERS);
                break;

            case 3:
                resolve_querie3(linha,p,users_list,rides_list,N_RIDES);
                break;

            case 4:
                resolve_querie4(linha,p,drivers_list,rides_list,cities_list,N_CITIES);
                break;

            case 6:
                resolve_querie6(linha,p,rides_list,cities_list,N_CITIES);
                break;

            case 7:
                resolve_querie7(linha,p,drivers_list,rides_list,cities_list,N_CITIES);
                break;

            case 8:
                resolve_querie8(linha,p,users_list,drivers_list,rides_list,N_DRIVERS);
                break;

            case 9:
                resolve_querie9(linha,p,rides_list,N_RIDES);
                break;

        }


    }

    fclose(commands);

    return 0;
    
}
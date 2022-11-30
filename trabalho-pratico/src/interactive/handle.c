#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <interactive/handle.h>


void mensage_success(int N){

    switch (N){

        case 0:
            printf("Ficheiro dos utilizadores carregado com sucesso ✔\n");
            break;

        case 1:
            printf("Ficheiro dos condutores carregado com sucesso ✔\n");
            break;

        case 2:
            printf("Ficheiro das viagens carregado com sucesso ✔\n");
            break;
    }
}


void mensage_error(){

    printf("Não foi possivel carregar os dados\n");
}


void interactive_mode(USERS users_list, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_DRIVERS, int N_RIDES, int N_CITIES){

    char string[1000] = "";

    while (strstr(string,"quit") == NULL){

        printf("Execução de queries >>> ");

        if (fgets(string, 1000, stdin) != NULL){

            if (isdigit(string[0])){
            
                resolve_queries(string,1,users_list,drivers_list,rides_list,cities_list,N_DRIVERS,N_RIDES,N_CITIES);
                page_browser();
            }
        }
    }
}
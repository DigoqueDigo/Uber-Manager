#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <interactive/handle.h>


void mensage_success(int N, int flag){

    switch (N){

        case 0:
            if (flag) printf("Ficheiro dos utilizadores carregado com sucesso ✔\n");
            else printf("Os dados dos utilizadores foram removidos com sucesso ✔\n");
            break;

        case 1:
            if (flag) printf("Ficheiro dos condutores carregado com sucesso ✔\n");
            else printf("Os dados dos condutores foram removidos com sucesso ✔\n");
            break;

        case 2:
            if (flag) printf("Ficheiro das viagens carregado com sucesso ✔\n");
            else printf("Os dados das viagens foram removidos com sucesso ✔\n");
            break;
    }
}


void remove_users_catalog(USERS *users_list, int *users_flag){

    free_hash_table(*users_list);
    *users_flag = 0;
            
    mensage_success(0,0);

    *users_list = init_users();
}


void remove_drivers_catalog(DRIVERS *drivers_list, int *N_DRIVERS){

    free_drivers(*drivers_list,*N_DRIVERS);
    *N_DRIVERS = 0;

    mensage_success(1,0);

    *drivers_list = init_drivers();
}


void remove_rides_catalog(RIDES *rides_list, CITIES *cities_list, int *N_RIDES, int *N_CITIES){

    free_rides(*rides_list,*N_RIDES);
    free_cities_list(*cities_list,*N_CITIES);
    *N_RIDES = 0;
    *N_CITIES = 0;

    mensage_success(2,0);

    *rides_list = init_ride_list();
    *cities_list = init_cities();
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
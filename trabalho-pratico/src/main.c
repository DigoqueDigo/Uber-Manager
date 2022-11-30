#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parsing/parser.h>
#include <fetch/collector.h>
#include <queries/queries.h>
#include <interactive/handle.h>



int main(int argc, char** argv){

    RIDES rides_list = init_ride_list();
    USERS users_list = init_users();
    DRIVERS drivers_list = init_drivers();
    CITIES cities_list = init_cities();
    
    int N_RIDES = 0, N_DRIVERS = 0, N_CITIES = 0;
    int SIZE_DRIVERS = CAP_DRIVERS, SIZE_RIDES = CAP_RIDES, SIZE_CITIES = CAP_CITIES;

    if (argc > 1){

        if (fecth_users(argv[1],users_list) == -1) return -1;

        if (fetch_drivers(argv[1],&drivers_list,&N_DRIVERS,&SIZE_DRIVERS) == -1) return -1;

        if (fetch_rides(argv[1],users_list,drivers_list,&rides_list,&cities_list,&N_RIDES,&N_CITIES,&SIZE_RIDES,&SIZE_CITIES) == -1) return -1;

        if (argc == 3){

            resolve_queries_batch(argv[2],users_list,drivers_list,rides_list,cities_list,N_DRIVERS,N_RIDES,N_CITIES);
        }
    }

    else if (argc == 1){

        char string[1000] = "", *token;
        int users_flag = 0;

        while (strstr(string,"quit") == NULL){

            printf("Página inicial >>> ");

            if (fgets(string, 1000, stdin) != NULL){

                token = strtok(string, " " "\n");

                if (!strcmp(token,"load")){

                    token = strtok(NULL, " " "\n");
            
                    if (!users_flag){

                        if (!fecth_users(token,users_list)){

                            users_flag = 1;
                            mensage_success(0);
                        }
                    }

                    if (!N_DRIVERS){
                    
                        if (!fetch_drivers(token,&drivers_list,&N_DRIVERS,&SIZE_DRIVERS)) mensage_success(1);
                    }

                    if (!N_RIDES){

                        if (!fetch_rides(token,users_list,drivers_list,&rides_list,&cities_list,&N_RIDES,&N_CITIES,&SIZE_RIDES,&SIZE_CITIES)) mensage_success(2);
                    }
                }
                

                else if (!strcmp(token,"execute") && users_flag && N_DRIVERS && N_RIDES){

                    interactive_mode(users_list,drivers_list,rides_list,cities_list,N_DRIVERS,N_RIDES,N_CITIES);
                }

                else if (strstr(string,"quit") == NULL && (!users_flag || !N_DRIVERS || !N_RIDES)) printf("Não é possivel avançar sem os dados serem recolhidos\n");
            }
        }
    }


    free_drivers(drivers_list,N_DRIVERS);
    free_rides(rides_list,N_RIDES);
    free_hash_table(users_list);
    free_cities_list(cities_list,N_CITIES);

    return 0;
}
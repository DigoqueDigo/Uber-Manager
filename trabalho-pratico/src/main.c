#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parsing/checker.h>
#include <parsing/parser.h>
#include <queries/queries.h>



int main(int argc, char** argv){

//    Inicio do fetch dos dados

    LINE linha = malloc(120);
    RIDES rides_list = init_ride_list();
    USERS users_list = init_users();
    DRIVERS drivers_list = init_drivers();
    CITIES cities_list = init_cities();
    char aux_path[1000] = "";
    char string[1000];
    int N_RIDES = 0, N_DRIVERS = 0, N_CITIES = 0; 
    int SIZE_DRIVERS = CAP_DRIVERS, SIZE_RIDES = CAP_RIDES, SIZE_CITIES = CAP_CITIES; 
    int path_size = strlen(argv[1]);

    strcpy(aux_path,argv[1]);
    strcat(aux_path,"drivers.csv");


    FILE *ficheiro_rides, *ficheiro_users, *ficheiro_drivers;


    ficheiro_drivers = fopen(aux_path, "r");

    if (ficheiro_drivers == NULL){
        perror("drivers.csv");
        return -1;
    }


    while (fgets(string, 1000, ficheiro_drivers)){
        if (N_DRIVERS >= SIZE_DRIVERS){
            SIZE_DRIVERS *= 2;
            drivers_list = realloc_drivers(drivers_list,SIZE_DRIVERS);
        }
        
        if (set_driver_line(linha,string,drivers_list)){
            destroy_driver_line(linha);
        }
        
        N_DRIVERS++;
    }

    fclose(ficheiro_drivers);

    aux_path[path_size] = '\0';
    strcat(aux_path,"users.csv");


    ficheiro_users = fopen(aux_path, "r");

    if (ficheiro_users == NULL){
        perror("users.csv\n");
        return -1;
    }

    while (fgets(string, 1000, ficheiro_users)){
        if (set_user_line(linha,string,users_list)){
        
            destroy_user_line(linha);
        }
    }

    fclose(ficheiro_users);

    aux_path[path_size] = '\0';
    strcat(aux_path,"rides.csv");

    ficheiro_rides = fopen(aux_path, "r");

    if (ficheiro_rides == NULL){
        perror("rides.csv");
        return -1;
    }

    while (fgets(string, 1000, ficheiro_rides)){

        if (N_RIDES >= SIZE_RIDES){
            SIZE_RIDES *= 2;
            rides_list = realloc_rides(rides_list,SIZE_RIDES);
        }

        if (N_CITIES >= SIZE_CITIES){
            SIZE_CITIES *= 2;
            cities_list = realloc_cities(cities_list,SIZE_CITIES);
        }

        if (set_ride_line(linha,string,rides_list,users_list,drivers_list,cities_list,&N_CITIES)){
            destroy_driver_line(linha);
        }

        N_RIDES++;
    }

    fclose(ficheiro_rides);

//    print_drivers(drivers_list);

//    print_users(users_list);

//    print_rides(rides_list);

//    Fim do fetch de dados  

    if (argc == 3){

        resolve_queries(argv[2],users_list,drivers_list,rides_list,cities_list,N_DRIVERS,N_RIDES,N_CITIES);
    }

    free_drivers(drivers_list,N_DRIVERS);
    free_rides(rides_list,N_RIDES);
    free_hash_table(users_list);
    free_cities_list(cities_list,N_CITIES);


    return 0;
}
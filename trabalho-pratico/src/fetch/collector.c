#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fetch/collector.h>



int fecth_users(char *path, USERS users_list){

    FILE *ficheiro;
    
    int path_size = strlen(path);

    char string[1000], aux_path[2*path_size], *linha[CAP_LINE_USER*POINTER_SIZE];

    strcpy(aux_path,path);
    strcat(aux_path,"/users.csv");

    ficheiro = fopen(aux_path, "r");

    if (ficheiro == NULL){
        perror("users.csv");
        return -1;
    }

    while (fgets(string, 1000, ficheiro)){
        
        set_user_line(linha,string,users_list);
    }

    fclose(ficheiro);

    return 0;
}



int fetch_drivers(char *path, DRIVERS *drivers_list, int *N_DRIVERS, int *SIZE_DRIVERS){

    FILE *ficheiro;

    int path_size = strlen(path);

    char string[1000], aux_path[2*path_size], *linha[CAP_LINE*POINTER_SIZE];

    strcpy(aux_path,path);
    strcat(aux_path,"/drivers.csv");

    ficheiro = fopen(aux_path, "r");

    if (ficheiro == NULL){
        perror("drivers.csv");
        return -1;
    }


    while (fgets(string, 1000, ficheiro)){
        
        if (*N_DRIVERS >= *SIZE_DRIVERS){
            
            *SIZE_DRIVERS *= 2;
            realloc_drivers(drivers_list,*SIZE_DRIVERS);
        }
        
        if (!set_driver_line(linha,string,*drivers_list)){

            push_null_driver(*drivers_list,*N_DRIVERS);
        }
        
        ++*N_DRIVERS;
    }

    fclose(ficheiro);

    return 0;
}



int fetch_rides(char *path, USERS users_list, DRIVERS drivers_list, RIDES *rides_list, CITIES *cities_list, int *N_RIDES, int *N_CITIES, int *SIZE_RIDES, int *SIZE_CITIES){

    FILE *ficheiro;

    int path_size = strlen(path);

    char string[1000], aux_path[2*path_size], *linha[CAP_LINE*POINTER_SIZE];

    strcpy(aux_path,path);
    strcat(aux_path,"/rides.csv");

    ficheiro = fopen(aux_path, "r");

    if (ficheiro == NULL){
        perror("rides.csv");
        return -1;
    }

    while (fgets(string, 1000, ficheiro)){

        if (*N_RIDES >= *SIZE_RIDES){
            
            *SIZE_RIDES *= 2;
            realloc_rides(rides_list,*SIZE_RIDES);
        }

        if (*N_CITIES >= *SIZE_CITIES){
            
            *SIZE_CITIES *= 2;
            realloc_cities(cities_list,*SIZE_CITIES);
        }

        if (!set_ride_line(linha,string,*rides_list,users_list,drivers_list,*cities_list,N_CITIES)){

            push_null_ride(*rides_list,*N_RIDES);
        }

        ++*N_RIDES;
    }

    fclose(ficheiro);

    return 0;
}
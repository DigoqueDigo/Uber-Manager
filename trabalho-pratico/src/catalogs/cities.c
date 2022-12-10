#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catalogs/cities.h>


struct city{
    char *city;
    int sp;
    int size;
    int *positions;
};


CITIES init_cities(){
    CITIES new = malloc(CAP_CITIES*sizeof(struct city));
    return new;
}


void push_city(CITIES cities_list, char *city, int index, int *N_CITIES){

    int p;

    for (p = 0; p < *N_CITIES && strcmp(cities_list[p].city,city) != 0; p++);

    if (p == *N_CITIES){

        cities_list[*N_CITIES].city = strdup(city);
        cities_list[*N_CITIES].size = CAP_CITY;
        cities_list[*N_CITIES].sp = 1;
        cities_list[*N_CITIES].positions = malloc(CAP_CITY*sizeof(int));
        cities_list[*N_CITIES].positions[0] = index;
        ++*N_CITIES;
    }

    else{

        if (cities_list[p].sp >= cities_list[p].size){

            cities_list[p].size *= 2;
            cities_list[p].positions = realloc(cities_list[p].positions,cities_list[p].size*sizeof(int));
        }

        cities_list[p].positions[cities_list[p].sp++] = index;
    }
}


void realloc_cities(CITIES *cities_list, int new_size){
    *cities_list = realloc(*cities_list,new_size*(sizeof(struct city)));
}


void free_cities_list(CITIES cities_list, int N_CITIES){
    for (int p = 0; p < N_CITIES; p++){
        if (cities_list[p].city != NULL){
            free(cities_list[p].city);
            free(cities_list[p].positions);
        }
    }
    free(cities_list);
}

//MANAGER

int analyse_city(CITIES cities_list, char *city, int N_CITIES){
    int p;

    for (p = 0; p < N_CITIES && !strcmp(cities_list[p].city,city); p++);

    if (p == N_CITIES) return 0;

    return 1;
}


int* lookup_cities_positions(CITIES cities_list, char *city, int *sp, int N_CITIES){
    int p;
    for (p = 0; p < N_CITIES && cities_list[p].city != NULL && strcmp(cities_list[p].city,city) != 0; p++);

    if (p == N_CITIES){
        *sp = 0;
        return NULL;
    }

    *sp = cities_list[p].sp;
    return cities_list[p].positions;
}
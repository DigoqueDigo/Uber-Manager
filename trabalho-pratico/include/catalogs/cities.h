#ifndef CITIES_H
#define CITIES_H

#define CAP_CITIES 2
#define CAP_CITY 100


typedef struct city *CITIES; 


CITIES init_cities();

void push_city(
    CITIES cities_list, // array das cidades
    char *city, // cidade que pretendemos adicionar ao array
    int index, // indece que pretendemos adicionar á cidade
    int *N_CITIES // comprimento util do array das cidades
);

CITIES realloc_cities(CITIES cities_list, int new_size);

void free_cities_list(CITIES cities_list, int N_CITIES);

#endif
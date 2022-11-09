#ifndef QUERIE7_H
#define QUERIE7_H

#include <fixtures.h>

typedef struct driver_city *DRIVER_CITY;


typedef struct driver_city_list *DRIVER_CITY_LIST;


void push_driver_score(DRIVER_CITY *abin, int id, double score, char *name);


void free_cities(DRIVER_CITY abin);


DRIVER_CITY fill_abin(
    RIDES rides_list, // estrutura de dados com as viagens
    DRIVERS drivers_list, // estrutura de dados com os condutores
    char *city, // cidade que predentemos procurar nas viagens
    int N_RIDES // tamanho da estrutura das viagens
);


int count_nodes(DRIVER_CITY abin);


void convert_abin_to_array(
    DRIVER_CITY abin, // abin que será copiada para o array
    DRIVER_CITY_LIST array, // array no qual serão guardados os resuldados da abin
    int *index // posição atual do array
);


int compare_score_average(const void *a,const void *b);


int compare_id(const void *a, const void *b);


void sort_driver_city_list(
    void *array,
    int N,
    int size,
    int (*compare_0)(const void*, const void*), // primeira função de comparação
    int (*compare_1)(const void*, const void*) // segunda função de compararação
);

/*
void resolve_querie8(
    char *command,
    int ncommand,
    DRIVERS drivers_list,
    RIDES rides_list,
    int N_RIDES
);
*/
#endif
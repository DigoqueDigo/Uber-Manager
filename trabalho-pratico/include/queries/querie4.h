#ifndef QUERIE4_H
#define QUERIE4_H

#include <fixtures.h>

double preco_medio_cidade(
    DRIVERS drivers_list, 
    RIDES rides_list, 
    CITIES cities_list, 
    int N_CITIES, 
    char* city
);

void resolve_querie4(
    char* command,
    int ncommand,
    DRIVERS drivers_list,
    RIDES rides_list,
    CITIES cities_list,
    int N_CITIES
);

#endif
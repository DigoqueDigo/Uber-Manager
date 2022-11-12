#ifndef QUERIE6_H
#define QUERIE6_H

#include <fixtures.h>


double calculate_average_distance(
    RIDES rides_list,
    CITIES cities_list,
    int N_CITIES,
    int date_1,
    int date_2,
    char *city
);

void resolve_querie6(
    char *command,
    int ncommand,
    RIDES rides_list,
    CITIES cities_list,
    int N_CITIES
);

#endif
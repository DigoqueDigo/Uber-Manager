#ifndef HANDLE_H
#define HANDLE_H

#include <fixtures.h>
#include <queries/queries.h>
#include <interactive/pagination.h>



void mensage_success(int N);

void interactive_mode(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    CITIES cities_list,
    int N_DRIVERS,
    int N_RIDES,
    int N_CITIES
);

#endif
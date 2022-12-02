#ifndef HANDLE_H
#define HANDLE_H

#include <fixtures.h>
#include <queries/queries.h>
#include <interactive/pagination.h>



void mensage_success(int N, int flag);

void remove_users_catalog(USERS *users_list, int *users_flag);

void remove_drivers_catalog(DRIVERS *drivers_list, int *N_DRIVERS);

void remove_rides_catalog(RIDES *rides_list, CITIES *cities_list, int *N_RIDES, int *N_CITIES);

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
#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <fixtures.h>
#include <parsing/parser.h>


int fecth_users(char *path, USERS users_list);

int fetch_drivers(char *path, DRIVERS *drivers_list, int *N_DRIVERS, int *SIZE_DRIVERS);

int fetch_rides(char *path, USERS users_list, DRIVERS drivers_list, RIDES *rides_list, CITIES *cities_list, int *N_RIDES, int *N_CITIES, int *SIZE_RIDES, int *SIZE_CITIES);

#endif
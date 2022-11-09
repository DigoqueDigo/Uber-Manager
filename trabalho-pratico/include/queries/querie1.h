#ifndef QUERIE1_H
#define QUERIE1_H

#include <fixtures.h>
#include <parsing/checker.h>


int calculate_user(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    char *username,
    char *name,
    char *gender,
    char *birth_date,
    int *numero_viagens,
    double *score,
    double *money)
;

int calculate_driver(
    DRIVERS drivers_list,
    RIDES rides_list,
    int id,
    char *name,
    char *gender,
    char *birth_date,
    int *numero_viagens,
    double *score,
    double *money
);

void resolve_querie1(
    char *commands,
    int ncommand,
    USERS lista,
    DRIVERS drivers_lista,
    RIDES rides_lista,
    int N_DRIVERS
);


#endif
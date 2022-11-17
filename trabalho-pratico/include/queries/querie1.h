#ifndef QUERIE1_H
#define QUERIE1_H

#include <fixtures.h>
#include <parsing/checker.h>


void calculate_user(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    FILE *ficheiro,
    char *username
);

void calculate_driver(
    DRIVERS drivers_list,
    RIDES rides_list,
    FILE *ficheiro,
    int id
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
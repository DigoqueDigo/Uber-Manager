#ifndef QUERIE8_H
#define QUERIE8_H

#include"../fixtures.h"

typedef struct sort_gender *SORT_GENDER;



SORT_GENDER init_sort_gender(int N_RIDES);

void free_sort_gender(SORT_GENDER list, int N);


void push_sort_gender(
    SORT_GENDER list,
    int *N,  // comprimento da sort_gender list
    int id_driver,
    char *name_driver,
    int account_creation_driver,
    char *username,
    char *name_user,
    int account_creation_user,
    int id_rides,
    char *account_driver,
    char *account_user
);

void fill_sort_gender(
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    SORT_GENDER list,
    int *N,
    char *gender,
    int N_DRIVERS
);


int cmprfunc_driver(const void *a, const void *b);

int cmprfunc_user(const void *a, const void *b);

int cmprfunc_id_ride(const void *a, const void *b);

void sort_gender_list(SORT_GENDER list, int N);


void resolve_querie8(
    char *command,
    int ncommand,
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    int N_DRIVERS, // comprimento da lista dos drivers
    int N_RIDES // comprimento da lista das rides
);


#endif
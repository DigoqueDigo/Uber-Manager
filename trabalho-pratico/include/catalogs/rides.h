#ifndef RIDES_H
#define RIDES_H


#define T_BASIC 3.25
#define T_GREEN 4
#define T_PREMIUM 5.2
#define TK_BASIC 0.62
#define TK_GREEN 0.79
#define TK_PREMIUM 0.94


typedef struct ride *RIDES;

struct ride* init_ride_list();

RIDES realloc_rides(RIDES rides_list, int new_size);

void push_ride(
    RIDES lista,
    char *id,
    char *date,
    char *driver,
    char *user,
    char *city,
    char *distance,
    char *score_user,
    char *score_driver,
    char *tip
);


void print_rides(RIDES lista);


// MANAGE QUERIE 1

// retorna o id de um driver de uma determinada viagem

int lookup_id_driver(RIDES rides_list, int index);

// calcula os float apenas para uma viagem

void calculate_floats(
    RIDES rides_list,
    int index,
    char *car_class,
    double *score,
    double *money,
    int flag
);

void lookup_rides_username(RIDES rides_list, int index, char *username);

char* lookup_rides_date(RIDES rides_list, int index);

int lookup_rides_distance(RIDES rides_list, int index);

#endif
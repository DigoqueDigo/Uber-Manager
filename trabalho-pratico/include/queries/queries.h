#ifndef QUERIES_H
#define QUERIES_H

#include <fixtures.h>


int resolve_queries(
    char *path,
    USERS users_list,
    DRIVERS drivers_list,
    RIDES rides_list,
    int N_DRIVERS,
    int N_RIDES
);

#endif
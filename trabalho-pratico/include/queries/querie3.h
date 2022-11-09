#ifndef QUERIE_3
#define QUERIE_3

#include <fixtures.h>


typedef struct sort_distance *SORT_DISTANCE;


SORT_DISTANCE init_sort_distance(int N_RIDES);

void free_sort_distance(SORT_DISTANCE list, int N);

void fill_sort_distance(USERS users_list, RIDES rides_list, SORT_DISTANCE list, int *N);

int compare_distance_ride(const void *a, const void *b);

int compare_recente_ride(const void *a, const void *b);

int compare_username(const void *a, const void *b);

void sort_distance_list(SORT_DISTANCE list, int N);

void resolve_querie3(char *command, int ncommand, USERS users_list, RIDES rides_list, int N_RIDES);

#endif
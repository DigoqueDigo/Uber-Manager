#ifndef QUERIE_9
#define QUERIE_9

#include <fixtures.h>
#include <sort.h>

#define CAP_SORT_TIP 1000

typedef struct sort_tip *SORT_TIP;



SORT_TIP init_sort_tip();

void free_sort_tip(SORT_TIP sort_tip_list, int N);

int fill_sort_tip(SORT_TIP *sort_tip_list, RIDES rides_list, int date_1, int date_2, int N_RIDES);

int compare_id_sort_tip(const void *a, const void *b);

int compare_distance_sort_tip(const void *a, const void *b);

int compare_date_sort_tip(const void *a, const void *b);

void resolve_querie9(char *command,int ncommand, RIDES rides_list, int N_RIDES);

#endif
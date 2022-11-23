#ifndef QUERIE_2
#define QUERIE_2

#include <fixtures.h>
#include <sort.h>

#define CAP_SORT_SCORE 500

typedef struct sort_score *SORT_SCORE;


SORT_SCORE init_sort_score();

void free_sort_score(SORT_SCORE sort_score_list, int N);

int fill_sort_score(SORT_SCORE *sort_score_list, DRIVERS dirvers_list, RIDES rides_list, int N_DRIVERS);

int compare_score(const void *a, const void *b);

int compare_score_recent_ride(const void *a, const void *b);

int compare_score_id(const void *a, const void *b);

void resolve_querie2(char *command,int ncommand, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS);

#endif
#ifndef QUERIE5_H
#define QUERIE5_H


#include <fixtures.h>


double average_price_date(DRIVERS drivers_list, RIDES rides_list, int N_RIDES, int date_1, int date_2);

void resolve_querie5(char* command, int ncommand, DRIVERS drivers_list, RIDES rides_list, int N_RIDES);

#endif
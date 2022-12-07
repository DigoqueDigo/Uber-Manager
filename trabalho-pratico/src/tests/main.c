#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tests/diff.h>
#include <parsing/parser.h>
#include <fetch/collector.h>
#include <queries/queries.h>



int main(int argc, char **argv){

    if (system("clear") == -1) return -1;

    USERS users_list = init_users();
    DRIVERS drivers_list = init_drivers();
    RIDES rides_list = init_ride_list();
    CITIES cities_list = init_cities();
    TESTS tests_list = init_tests();

    int N_RIDES = 0, N_DRIVERS = 0, N_CITIES = 0, N_TESTS = 0;
    int SIZE_DRIVERS = CAP_DRIVERS, SIZE_RIDES = CAP_RIDES, SIZE_CITIES = CAP_CITIES, SIZE_TESTS = CAP_TESTS;

    if (argc == 4){

        if (fecth_users(argv[1],users_list) == -1) return -1;

        if (fetch_drivers(argv[1],&drivers_list,&N_DRIVERS,&SIZE_DRIVERS) == -1) return -1;

        if (fetch_rides(argv[1],users_list,drivers_list,&rides_list,&cities_list,&N_RIDES,&N_CITIES,&SIZE_RIDES,&SIZE_CITIES) == -1) return -1;

        if (argc > 3){

            resolve_queries_test(argv[2],users_list,drivers_list,rides_list,cities_list,&tests_list,N_DRIVERS,N_RIDES,N_CITIES,&N_TESTS,&SIZE_TESTS);
        }

        set_all_comparations(tests_list,N_TESTS,argv[3]);

        print_tests(tests_list,N_TESTS);
    }

    free_tests(tests_list,N_TESTS);
    free_drivers(drivers_list,N_DRIVERS);
    free_rides(rides_list,N_RIDES);
    free_hash_table(users_list);
    free_cities_list(cities_list,N_CITIES);

    return 0;
}
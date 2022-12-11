#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

        double catalogs_time[5];
        clock_t comparation_time, total_time = clock();

        for (int p = 0; p < 3; p++){

            clock_t time_taken = clock();

            switch (p){

                case 0:
                    if (fecth_users(argv[1],users_list) == -1) return -1;
                    break;

                case 1:
                    if (fetch_drivers(argv[1],&drivers_list,&N_DRIVERS,&SIZE_DRIVERS) == -1) return -1;
                    break;
                
                case 2:
                    if (fetch_rides(argv[1],users_list,drivers_list,&rides_list,&cities_list,&N_RIDES,&N_CITIES,&SIZE_RIDES,&SIZE_CITIES) == -1) return -1;
                    break;
            }

            time_taken = clock() - time_taken;
            catalogs_time[p] = ((double) time_taken)/CLOCKS_PER_SEC;
        }

        
        resolve_queries_test(argv[2],users_list,drivers_list,rides_list,cities_list,&tests_list,N_DRIVERS,N_RIDES,N_CITIES,&N_TESTS,&SIZE_TESTS);

        comparation_time = clock();

        set_all_comparations(tests_list,N_TESTS,argv[3]);

        comparation_time = clock() - comparation_time;
        total_time = clock() - total_time;

        catalogs_time[3] = ((double) comparation_time)/CLOCKS_PER_SEC;
        catalogs_time[4] = ((double) total_time)/CLOCKS_PER_SEC;

        print_tests(tests_list,N_TESTS,catalogs_time);
    }

    free_tests(tests_list,N_TESTS);
    free_drivers(drivers_list,N_DRIVERS);
    free_rides(rides_list,N_RIDES);
    free_hash_table(users_list);
    free_cities_list(cities_list,N_CITIES);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie4.h>


double preco_medio_cidade(DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_CITIES, char* city){
    char aux[500];
    int sp, dist, id, count = 0, *positions;
    double total = 0;

    if (!analyse_city(cities_list,city,N_CITIES)) return 0;

    positions = lookup_cities_positions(cities_list,city,&sp,N_CITIES);

    for (int p = 0; p < sp; p++){

        if (analyse_ride(rides_list,positions[p])){

            dist = lookup_rides_distance(rides_list,positions[p]);
            id = lookup_rides_id_driver(rides_list,positions[p]);


            if (analyse_driver(drivers_list,id)){

                count++;

                lookup_car_class(drivers_list,id,aux);

                if (!strcasecmp(aux,"basic")){
                    total += (dist*TK_BASIC) + T_BASIC;
                }

                else if (!strcasecmp(aux,"green")){
                    total += (dist*TK_GREEN) + T_GREEN;
                }

                else if (!strcasecmp(aux,"premium")){
                    total += (dist*TK_PREMIUM) + T_PREMIUM;
                }
            }
        }
    }

    if (!count) return count;

    return (total/count);
}


void resolve_querie4(char* command, int ncommand, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_CITIES){
    FILE *ficheiro;
    double average_price;
    char outfile[500] = "", *token;
    set_command_name(outfile, ncommand);

    token = strtok(command, " "  "\n");
    token = strtok(NULL, " ""\n");
    
    ficheiro = fopen(outfile, "w");

    average_price = preco_medio_cidade(drivers_list, rides_list, cities_list, N_CITIES, token);
    
    if (average_price) fprintf(ficheiro,"%.3f\n", average_price);    

    fclose(ficheiro);
}
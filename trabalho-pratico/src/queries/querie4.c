#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie4.h>

#define T_BASIC 3.25
#define T_GREEN 4
#define T_PREMIUM 5.2
#define TK_BASIC 0.62
#define TK_GREEN 0.79
#define TK_PREMIUM 0.94


double preco_medio_cidade(DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_CITIES, char* city){
    char aux[500];
    int sp, dist, id, count = 0;
    double total = 0;
    int *positions = lookup_cities_positions(cities_list,city,&sp,N_CITIES);

    if (positions == NULL) return 0;

    for (int p = 0; p < sp; p++){

        dist = lookup_rides_distance(rides_list,positions[p]);
        id = lookup_rides_id_driver(rides_list,positions[p]);

        
        if (dist != 0 && id != -1){

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

    return (total/count);
}

void resolve_querie4(char* command, int ncommand, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_CITIES){
    FILE *ficheiro;
    double average_price;
    char outfile[500] = "", *token;
    set_command_name(outfile, ncommand);

    token = strtok(command, " "  "\n");
    token = strtok(NULL, " ""\n");
    
    ficheiro = fopen(outfile, "a");

    average_price = preco_medio_cidade(drivers_list, rides_list, cities_list, N_CITIES, token);
    
    if (average_price){

        fprintf(ficheiro,"%.3f\n", average_price);    
    }

    fclose(ficheiro);
}
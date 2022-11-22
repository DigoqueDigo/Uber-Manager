#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie5.h>

#define T_BASIC 3.25
#define T_GREEN 4
#define T_PREMIUM 5.2
#define TK_BASIC 0.62
#define TK_GREEN 0.79
#define TK_PREMIUM 0.94

//int verificaData (RIDES rides_list, int k, int date1, int date2) {
//    rides_list[k].date
//}

double preco_medio_data(DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, char* date1, char* date2){
    char aux[500];
    int dist, id, count = 0;
    double total = 0;

    for (int p = 0; rides_list[p]; p++){
        date_ride = lookup_rides_date(rides_list,p);
        
        if (date_ride != NULL){
    
           aux_date = convert_date_to_int(date_ride);
           dist = lookup_rides_distance(rides_list,p);
           id = lookup_rides_id_driver(rides_list,p);

           if (date1 <= aux_date && aux_date <= date2){
               aux_date = convert_date_to_int(date_ride);
               dist = lookup_rides_distance(rides_list,p);
               id = lookup_rides_id_driver(rides_list,p);

                lookup_car_class(drivers_list,id,aux);

                if (!strcasecmp(aux,"basic")){
                    total += (dist*TK_BASIC) + T_BASIC;
                }

                else if (!strcasecmp(aux,"green")){
                    total += (dist*TK_GREEN) + T_GREEN;
                }

                else if (!strcasecmp(aux,"premium")){
                    total += (dist*TK_PREMIUM) + T_PREMIUM;

                count++;
                }
           }
        }

    return (total/count);
}

void resolve_querie5(char* command, int ncommand, DRIVERS drivers_list, RIDES rides_list, CITIES cities_list, int N_CITIES){
    FILE *ficheiro;
    double average_price;
    char *date1;
    char *date2;
    char outfile[500] = "", *token;
    set_command_name(outfile, ncommand);

    // -------------------------------------------------
    token = strtok(NULL, " " "\n");
    date1 = convert_date_to_int(token);

    token = strtok(NULL, " " "\n");
    date2 = convert_date_to_int(token);
    // --------------------------------------------------
    ficheiro = fopen(outfile, "a");

    average_price = preco_medio_data(drivers_list, rides_list, cities_list, date1, date2);
    
    if (average_price){

        fprintf(ficheiro,"%.3f\n", average_price);    
    }

    fclose(ficheiro);
}

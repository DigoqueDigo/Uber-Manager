#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie6.h>



double calculate_average_distance(RIDES rides_list, CITIES cities_list, int N_CITIES, int date1, int date2, char *city){

    char *date_ride;
    double acc = 0;
    int sp, *positions, aux_date, count = 0;

    if (analyse_city(cities_list,city,N_CITIES) == 0) return acc;

    positions = lookup_cities_positions(cities_list,city,&sp,N_CITIES);

    for (int p = 0; p < sp; p++){

        if (analyse_ride(rides_list,positions[p])){

            date_ride = lookup_rides_date(rides_list,positions[p]);
            aux_date = convert_date_to_int(date_ride);

            if (date1 <= aux_date && aux_date <= date2){
               
                acc += lookup_rides_distance(rides_list,positions[p]);
                count++;
           }
        }
    }

    if (!count) return count;

    return (acc/count);
}



void resolve_querie6(char *command, int ncommand, RIDES rides_list, CITIES cities_list, int N_CITIES){

    FILE *ficheiro;

    char output_file[500] = "", city[500], *token;
    int date1, date2;
    double result;

    set_command_name(output_file,ncommand);

    token = strtok(command, " " "\n");
    token = strtok(NULL, " " "\n");

    strcpy(city,token);

    token = strtok(NULL, " " "\n");
    date1 = convert_date_to_int(token);

    token = strtok(NULL, " " "\n");
    date2 = convert_date_to_int(token);
    
    ficheiro = fopen(output_file,"w");

    result = calculate_average_distance(rides_list,cities_list,N_CITIES,date1,date2,city);

    if (result) fprintf(ficheiro, "%.3f\n", result);

    fclose(ficheiro);
}


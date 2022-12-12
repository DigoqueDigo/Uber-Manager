#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie5.h>



double average_price_date(DRIVERS drivers_list, RIDES rides_list, int N_RIDES, int date_1, int date_2){
    
    char *date_ride, car_class[500];
    double acc = 0;
    int dist, id, count = 0, date;

    for (int p = 1; p < N_RIDES; p++){

        if (analyse_ride(rides_list,p)){

            date_ride = lookup_rides_date(rides_list,p);
            dist = lookup_rides_distance(rides_list,p);
            id = lookup_rides_id_driver(rides_list,p);
    
            date = convert_date_to_int(date_ride);

            if (date_1 <= date && date <= date_2 && analyse_driver(drivers_list,id)){

                lookup_car_class(drivers_list,id,car_class);

                if (!strcasecmp(car_class,"basic")){
                    acc += (dist*TK_BASIC) + T_BASIC;
                }

                else if (!strcasecmp(car_class,"green")){
                    acc += (dist*TK_GREEN) + T_GREEN;
                }

                else if (!strcasecmp(car_class,"premium")){
                    acc += (dist*TK_PREMIUM) + T_PREMIUM;
                }

                count++;
            }
        }
    }


    return (acc/count);
}



void resolve_querie5(char* command, int ncommand, DRIVERS drivers_list, RIDES rides_list, int N_RIDES){
   
    FILE *ficheiro;
    
    int date_1, date_2;
    char outfile[500] = "", *token;

    set_command_name(outfile, ncommand);

    token = strtok(command, " " "\n");
    token = strtok(NULL, " " "\n");

    date_1 = convert_date_to_int(token);

    token = strtok(NULL, " " "\n");
    date_2 = convert_date_to_int(token);

    ficheiro = fopen(outfile, "w");

    fprintf(ficheiro, "%0.3f\n", average_price_date(drivers_list,rides_list,N_RIDES,date_1,date_2));

    fclose(ficheiro);
}
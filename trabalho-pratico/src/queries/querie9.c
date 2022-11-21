#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie9.h>


struct sort_tip{
    int id_ride;
    int ride_date_int;
    char *ride_date;
    int distance;
    char *city;
    double tip;
};


SORT_TIP init_sort_tip(){
    SORT_TIP new = malloc(CAP_SORT_TIP*sizeof(struct sort_tip));
    return new;
}


void free_sort_tip(SORT_TIP sort_tip_list, int N){
    
    for (int p = 0; p < N; p++){

        if (sort_tip_list[p].city != NULL){
            
            free(sort_tip_list[p].city);
            free(sort_tip_list[p].ride_date);
        }
    }

    free(sort_tip_list);
}


int fill_sort_tip(SORT_TIP *sort_tip_list, RIDES rides_list, int date_1, int date_2, int N_RIDES){

    double tip;
    char *date, *city;
    int date_int, distance, N = 0, size = CAP_SORT_TIP;

    for (int p = 1; p < N_RIDES; p++){

        date = lookup_rides_date(rides_list,p);

        if (date != NULL){

            date_int = convert_date_to_int(date);
            tip = lookup_rides_tip(rides_list,p);

            if (date_1 <= date_int && date_int <= date_2 && tip != 0){


                distance = lookup_rides_distance(rides_list,p);
                city = lookup_rides_city(rides_list,p);

                if (N >= size){
                    size *= 2;
                    *sort_tip_list = realloc(*sort_tip_list,size*sizeof(struct sort_tip));
                    
                    if (*sort_tip_list == NULL){
                        printf("REALLOC FAILED\n");
                        return -1;
                    }
                }

                (*sort_tip_list)[N].id_ride = p;
                (*sort_tip_list)[N].ride_date_int = date_int;
                (*sort_tip_list)[N].distance = distance;
                (*sort_tip_list)[N].tip = tip;

                (*sort_tip_list)[N].ride_date = strdup(date);
                (*sort_tip_list)[N].city = strdup(city);
                N++;
            }
        }
    }

    return N;
}



int compare_id_sort_tip(const void *a, const void *b){
    const struct sort_tip *x = (const struct sort_tip*) a;
    const struct sort_tip *y = (const struct sort_tip*) b;
    return y->id_ride - x->id_ride;
}


int compare_distance_sort_tip(const void *a, const void *b){
    const struct sort_tip *x = (const struct sort_tip*) a;
    const struct sort_tip *y = (const struct sort_tip*) b;
    return y->distance - x->distance;
}


int compare_date_sort_tip(const void *a, const void *b){
    const struct sort_tip *x = (const struct sort_tip*) a;
    const struct sort_tip *y = (const struct sort_tip*) b;
    return y->ride_date_int - x->ride_date_int;
}



void resolve_querie9(char *command,int ncommand, RIDES rides_list, int N_RIDES){

    FILE *ficheiro;

    char output_file[500] = "", *token;
    int date_1, date_2, N;

    SORT_TIP sort_tip_list = init_sort_tip();

    set_command_name(output_file,ncommand);

    ficheiro = fopen(output_file, "a");

    token = strtok(command," " "\n");
    token = strtok(NULL," " "\n");

    date_1 = convert_date_to_int(token);

    token = strtok(NULL," " "\n");
    date_2 = convert_date_to_int(token);

    N = fill_sort_tip(&sort_tip_list,rides_list,date_1,date_2,N_RIDES);

    sort_three_compare(sort_tip_list,N,sizeof(struct sort_tip),compare_distance_sort_tip,compare_date_sort_tip,compare_id_sort_tip);

    for (int p = 0; p < N; p++){
        
        fprintf(ficheiro, "%012d;%s;%d;%s;%.3f\n",
            sort_tip_list[p].id_ride,
            sort_tip_list[p].ride_date,
            sort_tip_list[p].distance,
            sort_tip_list[p].city,
            sort_tip_list[p].tip
        );

    }

    free_sort_tip(sort_tip_list,N);

    fclose(ficheiro);
}
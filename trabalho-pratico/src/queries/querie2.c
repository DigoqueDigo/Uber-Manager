#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie2.h>


struct sort_score{
    int id_driver;
    char *name;
    int recente_ride;
    double average_score;
};


SORT_SCORE init_sort_score(){
    SORT_SCORE new = malloc(CAP_SORT_SCORE*sizeof(struct sort_score));
    return new;
}


void free_sort_score(SORT_SCORE sort_score_list, int N){

    for (int p = 0; p < N; p++){

        free(sort_score_list[p].name);
    }

    free(sort_score_list);
}


void print_sort_score(SORT_SCORE list, int N){

    for (int p = 0; p < N; p++){

        printf("%012d;%s;%0.3f\n", list[p].id_driver, list[p].name, list[p].average_score);
    }
}


int fill_sort_score(SORT_SCORE *sort_score_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS){

    int N = 0, size = CAP_SORT_SCORE, *positions, sp, recente_date = -1;
    char name[50], *date;
    double score;

    for (int p = 1; p < N_DRIVERS; p++, score = 0, recente_date = -1){

        if (analyse_driver(drivers_list,p) && lookup_driver_accounts_status(drivers_list,p)){

            positions = lookup_driver_positions(drivers_list,p,&sp);

            if (sp != 0){

                for (int i = 0; i < sp; i++){

                    if (analyse_ride(rides_list,positions[i])){
                    
                        score += lookup_rides_score_driver(rides_list,positions[i]);
                        date = lookup_rides_date(rides_list,positions[i]);

                        if (recente_date < convert_date_to_int(date)) recente_date = convert_date_to_int(date);
                    }
                }

                lookup_driver_name(drivers_list,p,name);

                if (N >= size){

                    size *= 2;
                    *sort_score_list = realloc(*sort_score_list,size*sizeof(struct sort_score));
                }

                (*sort_score_list)[N].id_driver = p;
                (*sort_score_list)[N].name = strdup(name);
                (*sort_score_list)[N].recente_ride = recente_date;
                (*sort_score_list)[N++].average_score = score/sp;
            }
        }
    }

    return N;
}


int compare_score(const void *a, const void *b){
    const struct sort_score *x = (const struct sort_score*) a;
    const struct sort_score *y = (const struct sort_score*) b;
    return ((y->average_score > x->average_score) - (y->average_score < x->average_score));
}


int compare_score_recent_ride(const void *a, const void *b){
    const struct sort_score *x = (const struct sort_score*) a;
    const struct sort_score *y = (const struct sort_score*) b;
    return y->recente_ride - x->recente_ride;
}


int compare_score_id(const void *a, const void *b){
    const struct sort_score *x = (const struct sort_score*) a;
    const struct sort_score *y = (const struct sort_score*) b;
    return x->id_driver - y->id_driver;
}



void resolve_querie2(char *command,int ncommand, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS){

    FILE *ficheiro;

    int N, top;
    char output_file[500] = "", *token;
    
    SORT_SCORE list = init_sort_score();
    
    set_command_name(output_file,ncommand);

    ficheiro = fopen(output_file,"a");

    token = strtok(command," " "\n");
    token = strtok(NULL, " " "\n");

    top = atoi(token);


    N = fill_sort_score(&list,drivers_list,rides_list,N_DRIVERS);

    sort_three_compare(list,N,sizeof(struct sort_score),compare_score,compare_score_recent_ride,compare_score_id);

    for (int p = 0; p < top && p < N; p++){

        fprintf(ficheiro, "%012d;%s;%0.3f\n", list[p].id_driver, list[p].name, list[p].average_score);
    }

    free_sort_score(list,N);

    fclose(ficheiro);
}
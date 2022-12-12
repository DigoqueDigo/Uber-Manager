#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie3.h>


struct sort_distance{
    char *name;
    char *username;
    int distance;
    int recente_ride;
};


SORT_DISTANCE init_sort_distance(){
    SORT_DISTANCE new = malloc(CAP_DISTANCE*sizeof(struct sort_distance));
    return new;
}


void free_sort_distance(SORT_DISTANCE list, int N){
    for (int p = 0; p < N; p++){
        if (list[p].name != NULL){
            free(list[p].name);
            free(list[p].username);
        }
    }
    free(list);
}


int fill_sort_distance(USERS users_list, RIDES rides_list, SORT_DISTANCE *list){
    
    char name[500], username[500], *date;
    int recente_ride = 0, *positions, sp, aux;
    int total_distance = 0, N = 0, size = CAP_DISTANCE;
    USER start = NULL;

    for (int bucket = -1; bucket < BUCKET; total_distance = 0, recente_ride = 0, sp = 0){

        start = lookup_positions_and_name(users_list,start,&bucket,name,username,&positions,&sp);
        
        if (strcmp(name,"inactive")){

            for (int i = 0; i < sp; i++){

                if (analyse_ride(rides_list,positions[i])){

                    date = lookup_rides_date(rides_list,positions[i]);
                    aux =  convert_date_to_int(date);

                    if (aux > recente_ride) recente_ride = aux;

                    total_distance += lookup_rides_distance(rides_list,positions[i]);
                }
            }


            if (bucket != BUCKET){

                if (N >= size){
                    size *= 2;
                    *list = realloc(*list,size*sizeof(struct sort_distance));
                }

                (*list)[N].name = strdup(name);
                (*list)[N].username = strdup(username);
                (*list)[N].recente_ride = recente_ride;
                (*list)[N++].distance = total_distance;
            }

        }
    }

    return N;
}


int compare_distance_ride(const void *a, const void *b){
    const struct sort_distance *x = a, *y = b;
    return y->distance - x->distance;    
}


int compare_recente_ride(const void *a, const void *b){
    const struct sort_distance *x = a, *y = b;
    return y->recente_ride - x->recente_ride;
}


int compare_username(const void *a, const void *b){
    const struct sort_distance *x = a, *y = b;
    return (strcmp(x->username,y->username));
}


void resolve_querie3(char *command, int ncommand, USERS users_list, RIDES rides_list){

    FILE *ficheiro;

    int N, top;

    char output_file[500] = "", *token;

    set_command_name(output_file,ncommand);

    token = strtok(command, " ");
    token = strtok(NULL, " ");

    top = atoi(token);

    ficheiro = fopen(output_file, "w");

    SORT_DISTANCE list = init_sort_distance();

    N = fill_sort_distance(users_list,rides_list,&list);

    sort_three_compare(list,N,sizeof(struct sort_distance),compare_distance_ride,compare_recente_ride,compare_username);

    for (int p = 0; p < top; p++){

        fprintf(ficheiro, "%s;%s;%d\n", list[p].username, list[p].name, list[p].distance);
    }

    free_sort_distance(list,N);

    fclose(ficheiro);
}
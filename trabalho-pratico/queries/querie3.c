#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"querie3.h"


struct sort_distance{
    char *name;
    char *username;
    int distance;
    int recente_ride;
};


SORT_DISTANCE init_sort_distance(int N_RIDES){
    SORT_DISTANCE new = malloc(N_RIDES/2*sizeof(struct sort_distance));
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


void fill_sort_distance(USERS users_list, RIDES rides_list, SORT_DISTANCE list, int *N){
    char name[50], username[50], *date;
    int recente_ride = 0, *positions, sp, aux;
    int total_distance = 0;
    USER start = NULL;
    *N = 0;

    for (int bucket = -1; bucket < BUCKET; total_distance = 0, recente_ride = 0, sp = 0){
       
        start = lookup_positions_and_name(users_list,start,&bucket,name,username,&positions,&sp);
        
        if (strcmp(name,"inactive")){

            for (int i = 0; i < sp; i++){

                date = lookup_rides_date(rides_list,positions[i]);
                aux =  convert_date_to_int(date);

                if (aux > recente_ride) recente_ride = aux;

                total_distance += lookup_rides_distance(rides_list,positions[i]);
            }


            if (bucket != 8000){

                list[*N].name = strdup(name);
                list[*N].username = strdup(username);
                list[*N].recente_ride = recente_ride;
                list[*N].distance = total_distance;
                ++*N;
            }
        }
    }
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


void sort_distance_list(SORT_DISTANCE list, int N){
    
    int start = -1, last = 1;

    qsort(list,N,sizeof(struct sort_distance),compare_distance_ride);

    for (int p = 0; p < N-1; p++){

        if (start == -1 && list[p].distance == list[p+1].distance){
            start = p;
            last++;
        }

        else if (list[p].distance == list[p+1].distance) last++;

        else if (start != -1){
            qsort(list+start,last,sizeof(struct sort_distance),compare_recente_ride);
            last = 1;
            start = -1;
        }
    } 
    
    if (start != -1) qsort(list+start,last,sizeof(struct sort_distance),compare_recente_ride);
    
    for (int p = 0, start = -1, last = 1; p < N-1; p++){

        if (start == -1 && list[p].recente_ride == list[p+1].recente_ride){

            if (list[p].distance == list[p+1].distance){
                start = p;
                last++;
            }
        }

        else if (list[p].recente_ride == list[p+1].recente_ride){
            
            if (list[p].distance == list[p+1].distance) last++;
        }

        else if (start != -1){
            qsort(list+start,last,sizeof(struct sort_distance),compare_username);
            last = 1;
            start = -1;
        }
    }

    if (start != -1) qsort(list+start,last,sizeof(struct sort_distance),compare_username);
}




void resolve_querie3(char *command, int ncommand, USERS users_list, RIDES rides_list, int N_RIDES){

    FILE *ficheiro;

    int N = 0; // tamanho util da sort distance
    int top;

    char output_file[50] = "", *token;

    set_command_name(output_file,ncommand);

    token = strtok(command, " ");
    token = strtok(NULL, " ");

    top = atoi(token);

    ficheiro = fopen(output_file, "a");

    SORT_DISTANCE list = init_sort_distance(N_RIDES);

    fill_sort_distance(users_list,rides_list,list,&N);

    sort_distance_list(list,N);


    for (int p = 0; p < top; p++){

        fprintf(ficheiro, "%s;%s;%d\n", list[p].username, list[p].name, list[p].distance);
    }

    free_sort_distance(list,N);

    fclose(ficheiro);
}
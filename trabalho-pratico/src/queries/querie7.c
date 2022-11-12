#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie7.h>


/*
As cidades estão representadas por uma arvore binária,
sendo que cada nodo possui uma cidade e os indices em
que essa cidade aparece no array das rides

Para ordenadar os resultados é necessário converter a
arvore binária num array cd N elementos, onde N corresponde
ao numero de nodo da arvore
*/



struct driver_city{
    int id; // este id pretence ao driver
    int sp; // numero de viagens de um driver numa dada cidade
    char *name;
    double score_total;
    struct driver_city *esq, *dir;
};


struct driver_city_list{
    int id;
    char name[200];
    double score_average;
};



void push_driver_score(DRIVER_CITY *abin, int id, double score, char *name){

    while (*abin != NULL && (*abin)->id != id){

        if (id > (*abin)->id) abin = &((*abin)->dir);
        else abin = &((*abin)->esq);
    }

    if (*abin != NULL){
        (*abin)->score_total += score;
        (*abin)->sp++;
    }

    else{
        struct driver_city *new = malloc(sizeof(struct driver_city));
        new->esq = new->dir = NULL;
        new->id = id;
        new->sp = 1;
        new->score_total = score;
        new->name = strdup(name);
        *abin = new;
    }
}



void free_cities(DRIVER_CITY abin){
    
    if (abin != NULL){

        free_cities(abin->esq);
        free_cities(abin->dir);
        free(abin->name);
        free(abin);
    }
}



DRIVER_CITY fill_abin(RIDES rides_list, DRIVERS drivers_list, CITIES cities_list, char *city, int N_CITIES){
    
    DRIVER_CITY new = NULL;
    char *token, name[200];
    double score;
    int *positions, id, sp; // este id corresponde ao driver

    positions = lookup_cities_positions(cities_list,city,&sp,N_CITIES);

    if (positions != NULL){

        for (int p = 1; p < sp; p++){ //depois testar com o p a começar em zero

            token = lookup_rides_city(rides_list,positions[p]);

            if (token && !strcmp(token,city)){

                score = lookup_rides_score_driver(rides_list,positions[p]);
                id = lookup_rides_id_driver(rides_list,positions[p]);
                lookup_driver_name(drivers_list,id,name);

                if (lookup_driver_accounts_status(drivers_list,id)){

                    push_driver_score(&new,id,score,name);
                }
            }
        }
    }
    
    return new;
}



int count_nodes(DRIVER_CITY abin){
    if (abin == NULL) return 0;
    return (1 + count_nodes(abin->esq) + count_nodes(abin->dir));
}



void convert_abin_to_array(DRIVER_CITY abin, DRIVER_CITY_LIST array, int *index){
    
    if (abin != NULL){
        
        array[*index].id = abin->id;
        strcpy(array[*index].name,abin->name);
        array[*index].score_average = abin->score_total / abin->sp;

        ++*index;

        convert_abin_to_array(abin->esq,array,index);
        convert_abin_to_array(abin->dir,array,index);
    }
}



int compare_score_average(const void *a,const void *b){
    const struct driver_city_list *x = a, *y = b;
    return ((y->score_average > x->score_average) - (y->score_average < x->score_average));
}



int compare_id(const void *a, const void *b){
    const struct driver_city_list *x = a, *y = b;
    return (y->id - x->id);
}



void resolve_querie7(char *command, int ncommand, DRIVERS drivers_list,RIDES rides_list, CITIES cities_list, int N_CITIES){

    FILE *ficheiro;

    char output_file[500] = "", aux_id[30], *token;
    int N, Nodes;


    set_command_name(output_file,ncommand);

    token = strtok(command," " "\n");
    token = strtok(NULL, " " "\n");
    N = atoi(token);
    token = strtok(NULL, " " "\n"); // neste momento token == city


    ficheiro = fopen(output_file,"a");


    DRIVER_CITY abin = fill_abin(rides_list,drivers_list,cities_list,token,N_CITIES);


    Nodes = count_nodes(abin);

    DRIVER_CITY_LIST list = malloc(Nodes*sizeof(struct driver_city_list));

    Nodes = 0;

    convert_abin_to_array(abin,list,&Nodes);

    free_cities(abin);

    sort_two_compare(list,Nodes,sizeof(struct driver_city_list),compare_score_average,compare_id);

    for (int p = 0; p < N; p++){

        convert_id_to_string(aux_id,list[p].id);
        fprintf(ficheiro, "%s;%s;%.3f\n", aux_id, list[p].name, list[p].score_average);
    }

    free(list);

    fclose(ficheiro);
}
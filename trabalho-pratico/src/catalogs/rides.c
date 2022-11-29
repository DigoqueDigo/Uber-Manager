#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catalogs/rides.h>



struct ride{
    int id;
    char *date;
    int driver;
    char *user;
    char *city;
    short int distance;
    short int score_user;
    short int score_driver;
    float tip;
};


struct ride* init_ride_list(){
    struct ride *new = malloc(CAP_RIDES*sizeof(struct ride));
    return new;
}


void realloc_rides(RIDES *rides_list, int new_size){
    *rides_list = realloc(*rides_list,new_size*sizeof(struct ride));
}


void push_ride(RIDES lista, char *id, char *date, char *driver, char *user, char *city, char *distance, char *score_user, char *score_driver, char *tip){
    struct ride new;
    new.id = atoi(id);
    new.date = strdup(date);
    new.driver = atoi(driver);
    new.user = strdup(user);
    new.city = strdup(city);
    new.distance = atoi(distance);
    new.score_user = atoi(score_user);
    new.score_driver = atoi(score_driver);
    new.tip = atof(tip);
    lista[new.id] = new;
}


void free_rides(RIDES rides_list, int N_RIDES){
    for (int p = 0; p < N_RIDES; p++){
        if (rides_list[p].date != NULL){
            free(rides_list[p].date);
            free(rides_list[p].user);
            free(rides_list[p].city);
        }
    }
    free(rides_list);
}


// FUNÇÕES DE MANAGER


int analyse_ride(RIDES rides_list, int index){
    if (rides_list[index].date == NULL) return 0;
    return 1;
}


int lookup_id_driver(RIDES rides_list, int index){
    return rides_list[index].driver;
}


void lookup_rides_username(RIDES rides_list, int index, char *username){
    strcpy(username,rides_list[index].user); 
}


char* lookup_rides_date(RIDES rides_list, int index){
    return rides_list[index].date;
}


int lookup_rides_distance(RIDES rides_list, int index){
    return rides_list[index].distance;
} 


char* lookup_rides_city(RIDES rides_list, int index){
    return rides_list[index].city;
}


double lookup_rides_score_driver(RIDES rides_list, int index){
    return rides_list[index].score_driver;
}


int lookup_rides_id_driver(RIDES rides_list, int index){
    return rides_list[index].driver;
}


double lookup_rides_tip(RIDES rides_list, int index){
    return rides_list[index].tip;
}


int lookup_rides_score_user(RIDES rides_list, int index){
    return rides_list[index].score_user;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"rides.h"


//#id; date; driver; user; city; distance; score_user; score_driver; tip

struct ride{
    int id;
    char *date;
    int driver;
    char *user;
    char *city;
    int distance;
    int score_user;
    int score_driver;
    float tip;
};

struct ride* init_ride_list(){
    struct ride *new = malloc(1000100*sizeof(struct ride));
    return new;
}


RIDES realloc_rides(RIDES rides_list, int new_size){
    rides_list = realloc(rides_list,new_size*sizeof(struct ride));
    return rides_list;
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


void print_rides(RIDES lista){
    for (int p = 1; p < 1000001; p++){
        struct ride content = lista[p];
    
        printf("%d;%s;%d;%s;%s;%d;%d;%d;%.3f\n",
        content.id,
        content.date,
        content.driver,
        content.user,
        content.city,
        content.distance,
        content.score_user,
        content.score_driver,
        content.tip);
    }
}



// FUNÇÕES ÚTEIS À QUERIE 1


int lookup_id_driver(RIDES rides_list, int index){
    return rides_list[index].driver;
}


// flag 0 == user
// flag 1 == driver

void calculate_floats(RIDES rides_list, int index, char *car_class, double *score, double *money, int flag){
    if (flag) *score += rides_list[index].score_driver;
    else *score += rides_list[index].score_user;
    *money += rides_list[index].tip;
    if (!strcmp(car_class,"basic")) *money += T_BASIC + rides_list[index].distance * TK_BASIC;
    else if (!strcmp(car_class,"green")) *money += T_GREEN + rides_list[index].distance * TK_GREEN;
    else *money += T_PREMIUM + rides_list[index].distance * TK_PREMIUM;
}



void lookup_rides_username(RIDES rides_list, int index, char *username){
    strcpy(username,rides_list[index].user); 
}


char* lookup_rides_date(RIDES rides_list, int index){
    return rides_list[index].date;
}


int lookup_rides_distance(RIDES rides_list, int index){
    if (rides_list[index].date == NULL) return 0;
    return rides_list[index].distance;
} 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catalogs/drivers.h>


struct driver{
    int id;
    char *name;
    char *birth_date;
    char *gender;
    char *car_class;
    char *license_plate;
    char *city;
    char *account_creation;
    char *account_status;
    int sp;
    int size;
    int *positions;
};


DRIVERS init_drivers(){
    DRIVERS new = malloc(CAP_DRIVERS*sizeof(struct driver));
    return new;
}

void realloc_drivers(DRIVERS *drivers_list, int new_size){
    *drivers_list = realloc(*drivers_list,new_size*sizeof(struct driver));
}


void push_driver(DRIVERS lista, char *id, char *name, char *birth_date, char *gender, char *car_class, char *license_plate, char *city, char *account_creation, char *account_status){
    struct driver new;
    new.id = atoi(id);
    new.name = strdup(name);
    new.birth_date = strdup(birth_date);
    new.gender = strdup(gender);
    new.car_class = strdup(car_class);
    new.license_plate = strdup(license_plate);
    new.city = strdup(city);
    new.account_creation = strdup(account_creation);
    new.account_status = strdup(account_status);
    new.sp = 0;
    new.size = CAP_DRIVER;
    new.positions = malloc(new.size*sizeof(int));
    lista[new.id] = new;
}


void push_position_driver(DRIVERS lista, int position, char *driver_id){
    int index = atoi(driver_id);
    if (lista[index].name == NULL) return;
    if (lista[index].sp >= lista[index].size){
        lista[index].size *= 2;
        lista[index].positions = realloc(lista[index].positions,lista[index].size*sizeof(int));

    }
    lista[index].positions[lista[index].sp++] = position;
}


void push_null_driver(DRIVERS drivers_list, int index){
    drivers_list[index].name = NULL;
}


void free_drivers(DRIVERS drivers_list, int N_DRIVERS){
    for (int p = 1; p < N_DRIVERS; p++){
        if (drivers_list[p].name != NULL){
            free(drivers_list[p].name);
            free(drivers_list[p].birth_date);
            free(drivers_list[p].gender);
            free(drivers_list[p].car_class);
            free(drivers_list[p].license_plate);
            free(drivers_list[p].city);
            free(drivers_list[p].account_creation);
            free(drivers_list[p].account_status);
            free(drivers_list[p].positions);
        }
    }
    free(drivers_list);
}



// FUNÇÕES DE MANAGER

int analyse_driver(DRIVERS drivers_list, int index){
    if (drivers_list[index].name == NULL) return 0;
    return 1;
}


void lookup_car_class(DRIVERS drivers_list, int index, char *car_class){
    strcpy(car_class,drivers_list[index].car_class);
}


int* lookup_driver_positions(DRIVERS drivers_list, int index, int *sp){
    struct driver aux = drivers_list[index];
    *sp = aux.sp;
    return aux.positions;
}


void lookup_driver_name(DRIVERS drivers_list, int index, char *name){
    strcpy(name,drivers_list[index].name);
}


void lookup_driver_account_creation(DRIVERS drivers_list, int index, char *account_creation){
    strcpy(account_creation,drivers_list[index].account_creation);
}


void lookup_driver_gender(DRIVERS drivers_list, int index, char *gender){
    strcpy(gender,drivers_list[index].gender);
}


int lookup_driver_accounts_status(DRIVERS drivers_list, int index){
    if (!strcasecmp(drivers_list[index].account_status,"inactive")) return 0;
    return 1;
}


void lookup_driver_birth_date(DRIVERS drivers_list, int index, char *date){
    strcpy(date,drivers_list[index].birth_date);
}
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

DRIVERS realloc_drivers(DRIVERS drivers_list, int new_size){
    drivers_list = realloc(drivers_list,new_size*sizeof(struct driver));
    return drivers_list;
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


void print_drivers(DRIVERS lista){
    for (int p = 1; p < 10001; p++){
        printf("%d;%s;%s;%s;%s;%s;%s;%s;%s || ",
            lista[p].id,
            lista[p].name,
            lista[p].birth_date,
            lista[p].gender,
            lista[p].car_class,
            lista[p].license_plate,
            lista[p].city,
            lista[p].account_creation,
            lista[p].account_status);
        for (int i = 0; i < lista[p].sp; i++){
            printf("%d ", lista[p].positions[i]);
        }
        putchar('\n');
    }
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


void free_drivers(DRIVERS drivers_list, int N_DRIVERS){
    for (int p = 0; p < N_DRIVERS; p++){
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




// FUNÇÕES ÚTEIS À QUERIE 1

void lookup_car_class(DRIVERS drivers_list, int index, char *car_class){
    struct driver aux = drivers_list[index];
    strcpy(car_class,aux.car_class);
}


int* lookup_driver(DRIVERS drivers_list, int id, char *name, char *gender, char *birth_date, char *car_class, int *numero_viagens){
    struct driver aux = drivers_list[id];
    if (aux.name == NULL || !strcmp(aux.account_status,"inactive")) return NULL;
    strcpy(name,aux.name);
    strcpy(gender,aux.gender);
    strcpy(birth_date,aux.birth_date);
    strcpy(car_class,aux.car_class);
    *numero_viagens = aux.sp;
    return aux.positions;
}

// FUNÇÕES ÚTEIS À QUEIRE 8

int* lookup_driver_positions(DRIVERS drivers_list, int index, int *sp){
    struct driver aux = drivers_list[index];
    *sp = aux.sp;
    return aux.positions;
}


int lookup_driver_name(DRIVERS drivers_list, int index, char *name){
    if (drivers_list[index].name == NULL) return 0;
    strcpy(name,drivers_list[index].name);
    return 1;
}


void lookup_driver_account_creation(DRIVERS drivers_list, int index, char *account_creation){
    strcpy(account_creation,drivers_list[index].account_creation);
}


void lookup_driver_gender(DRIVERS drivers_list, int index, char *gender){
    if (drivers_list[index].gender == NULL) strcpy(gender,"invalid");
    strcpy(gender,drivers_list[index].gender);
}


int lookup_driver_accounts_status(DRIVERS drivers_list, int index){
    if (drivers_list[index].account_status == NULL || !strcmp(drivers_list[index].account_status,"inactive")) return 0;
    return 1;
}
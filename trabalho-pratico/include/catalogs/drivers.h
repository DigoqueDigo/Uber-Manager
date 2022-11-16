#ifndef DRIVERS_H
#define DRIVERS_H

#define CAP_DRIVER 100
#define CAP_DRIVERS 5000

typedef struct driver *DRIVERS;

DRIVERS init_drivers();

DRIVERS realloc_drivers(DRIVERS drivers_list, int new_size);

void push_driver(
    DRIVERS lista,
    char  *id,
    char *name,
    char *birth_date,
    char *gender,
    char *car_class,
    char *license_plate,
    char *city,
    char *account_creation,
    char *account_status
);


void push_position_driver(DRIVERS lista, int position, char *driver_id);

void free_drivers(DRIVERS drivers_list, int N_DRIVERS);

// MANAGER

void lookup_car_class(DRIVERS drivers_list, int index, char *car_class);

int* lookup_driver(
    DRIVERS drivers_list,
    int id,
    char *name,
    char *gender,
    char *birth_date,
    char *car_class,
    int *numero_viagens
);

int* lookup_driver_positions(DRIVERS drivers_list, int index, int *sp);

int lookup_driver_name(DRIVERS drivers_list, int index, char *name);

void lookup_driver_account_creation(DRIVERS drivers_list, int index, char *account_creation);

void lookup_driver_gender(DRIVERS drivers_list, int index, char *gender);

int lookup_driver_accounts_status(DRIVERS drivers_list, int index);

#endif
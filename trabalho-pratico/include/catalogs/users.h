#ifndef USERS_H
#define USERS_H

#define CAP_USER 10
#define BUCKET 8000

typedef struct user* USER;

typedef USER* USERS;

USERS init_users();

USER init_user(
    char *username,
    char *name,
    char *gender,
    char *birth_date,
    char *account_creation,
    char *pay_method,
    char *account_status
);

int hash_func(char *username);

void push_user_bucket(USER *lista, USER x);

void push_user(
    USERS lista,
    char *username,
    char *name,
    char *gender,
    char *birth_date,
    char *account_creation,
    char *pay_method,
    char *account_status
);

void push_position(USERS lista, int position, char *username);

void free_hash_table(USERS users_list);

void print_users(USERS lista);


// MANAGER

int* lookup_username(
    USERS users_list,
    char *username,
    char *name,
    char *genero,
    char *birth_date,
    int *numero_viagens
);


int lookup_user(
    USERS list,
    char *username,
    char *name,
    char *account_creation,
    char *gender
);


USER lookup_positions_and_name(
    USERS users_list,
    USER start,
    int *bucket,
    char *name,
    char *username,
    int **positions,
    int *sp
);

#endif
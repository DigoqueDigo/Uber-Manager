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


// MANAGER


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


int* lookup_user_positions(USERS users_list, char *username, int *sp);

void lookup_user_name(USERS users_list, char *username, char *name);

void lookup_user_birth_date(USERS users_list, char *username, char *date);

void lookup_user_gender(USERS users_list, char *username, char *date);

int lookup_user_account_status(USERS users_list, char *username);


#endif
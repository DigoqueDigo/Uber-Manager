#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catalogs/users.h>



struct user{
    char *username;
    char *name;
    char *gender;
    char *birth_date;
    char *account_creation;
    char *pay_method;
    char *account_status;
    int sp;
    int size;
    int *positions;
    struct user *prox;
};



USERS init_users(){
    USERS new = malloc(BUCKET*sizeof(USER));
    return new;;
}


USER init_user(char *username, char *name, char *gender, char *birth_date, char *account_creation, char *pay_method, char *account_status){
    USER new = malloc(sizeof(struct user));
    new->username = strdup(username);
    new->name = strdup(name);
    new->gender = strdup(gender);
    new->birth_date = strdup(birth_date);
    new->account_creation = strdup(account_creation);
    new->pay_method = strdup(pay_method);
    new->account_status = strdup(account_status);
    new->prox = NULL;
    new->sp = 0;
    new->size = CAP_USER;
    new->positions = malloc(new->size*sizeof(int));
    return new;
}


int hash_func(char *str){
    long hash = 5381;
    int c;

    for (int p = 0; str[p] != '\0'; p++){
        c = str[p];
        hash = ((hash << 5) + hash) + c;
    }
    
    if (hash < 0) hash = -hash;
    return hash % BUCKET;
}


void push_user_bucket(USER *lista, USER x){
    if (*lista == NULL){
        *lista = x;
        x->prox = NULL;
        }
    else{
        x->prox = *lista;
        *lista = x;
    }
}


void push_user(USERS lista, char *username, char *name, char *gender,char *birth_date, char *account_creation, char *pay_method, char *account_status){
    USER new = init_user(username,name,gender,birth_date,account_creation,pay_method,account_status);
    int x = hash_func(new->username);
    push_user_bucket(&lista[x],new);
}


void push_position(USERS lista, int position, char *username){
    int x = hash_func(username);
    USER bucket = lista[x];
    for (; bucket != NULL && strcmp(bucket->username,username) != 0; bucket = bucket->prox);
    if (bucket != NULL){
        if (bucket->sp >= bucket->size){
            bucket->size *= 2;
            bucket->positions = realloc(bucket->positions,bucket->size*sizeof(int));
        }
        bucket->positions[bucket->sp++] = position;
    }
}


void free_hash_table(USERS users_list){
    
    USER aux, temp;
    
    for (int p = 0; p < BUCKET; p++){

        aux = users_list[p];

        while (aux != NULL){
            
            temp = aux;
            aux = aux->prox;
            free(temp->name);
            free(temp->username);
            free(temp->gender);
            free(temp->birth_date);
            free(temp->account_creation);
            free(temp->pay_method);
            free(temp->account_status);
            free(temp->positions);
            free(temp); 
        }

        free(aux);
    }

    free(users_list);
}



// FUNÇÕES DE MANAGER


int lookup_user(USERS list, char *username, char *name, char *account_creation, char *gender){
    USER aux;
    int index = hash_func(username);
    for (aux = list[index]; aux != NULL && strcmp(username,aux->username) != 0; aux = aux->prox);
    if (aux == NULL || strcmp(aux->gender,gender) != 0 || !strcmp(aux->account_status,"inactive")) return 0;
    strcpy(name,aux->name);
    strcpy(account_creation,aux->account_creation);
    return 1;
}


USER lookup_positions_and_name(USERS users_list, USER start, int *bucket, char *name, char *username, int **positions, int *sp){
    
    if (start == NULL){

        for (*bucket = *bucket+1; users_list[*bucket] == NULL && *bucket < BUCKET; ++*bucket);

        if (*bucket == BUCKET) return NULL;

        start = users_list[*bucket];
    }

    if (!strcmp(start->account_status,"inactive")) strcpy(name,"inactive");
    
    else{
        strcpy(name,start->name);
        strcpy(username,start->username);
        *positions = start->positions;
        *sp = start->sp;
    }   

    return start->prox;
}


int* lookup_user_positions(USERS users_list, char *username, int *sp){
    
    int index = hash_func(username);
    USER aux = users_list[index];

    for (; aux != NULL && strcmp(aux->username,username) != 0; aux = aux->prox);

    if (aux == NULL) return NULL;

    *sp = aux->sp;
    return (aux->positions);
}


void lookup_user_name(USERS users_list, char *username, char *name){
    
    int index = hash_func(username);
    USER aux = users_list[index];

    for (; aux != NULL && strcmp(aux->username,username) != 0; aux = aux->prox);

    if (aux == NULL) return;

    strcpy(name,aux->name);
}


void lookup_user_birth_date(USERS users_list, char *username, char *date){

    int index = hash_func(username);
    USER aux = users_list[index];

    for (; aux != NULL && strcmp(aux->username,username) != 0; aux = aux->prox);

    if (aux == NULL) return;

    strcpy(date,aux->birth_date);
}


void lookup_user_gender(USERS users_list, char *username, char *gender){

        int index = hash_func(username);
    USER aux = users_list[index];

    for (; aux != NULL && strcmp(aux->username,username) != 0; aux = aux->prox);

    if (aux == NULL) return;

    strcpy(gender,aux->gender);
}


int lookup_user_account_status(USERS users_list, char *username){

    int index = hash_func(username);
    USER aux = users_list[index];

    for (; aux != NULL && strcmp(aux->username,username) != 0; aux = aux->prox);

    if (aux == NULL || !strcmp(aux->account_status,"inactive")) return 0;

    return 1;
}
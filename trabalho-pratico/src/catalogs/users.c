#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <catalogs/users.h>

// username;name;gender;birth_date;account_creation;pay_method;account_status


struct user{
    char *username;
    char *name;
    char *gender;
    char *birth_date;
    char *account_creation;
    char *pay_method;
    char *account_status;
    int sp;
    int size; // o tamanho inicial é 100
    int *positions;
    struct user *prox;
};

// O multiplicador do sizeof apenas necessitava de ser igual ao numero de buckets, ou seja, 500 neste caso


USERS init_users(){
    USERS new = malloc(100000*sizeof(USER));
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
    new->size = 10;
    new->positions = malloc(new->size*sizeof(int));
    return new;
}

// 8000 Buckets de linked_lists
// Também é nesta função que defino o número de buckets

int hash_func(char *username){
    int x = 0, p;
    for (p = 0; username[p] != '\0'; p++){
        x += username[p];
        x *= p;
    }
    x *= strlen(username);
    x = x % BUCKET;  // número de buckets
    if (x < 0) x = -x;
    return x;
}


// Insere sempre no inicio da lista

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


void print_users(USERS lista){
    for (int p = 0; p < BUCKET; p++){
        for (USER aux = lista[p]; aux != NULL; aux = aux->prox){
            printf("%s;%s;%s;%s;%s;%s;%s;",
                aux->username,
                aux->name,
                aux->gender,
                aux->birth_date,
                aux->account_creation,
                aux->pay_method,
                aux->account_status);
            for (int i = 0; i < aux->sp; i++){
                printf("%d ", aux->positions[i]);
            }
            putchar('\n');
        }
        printf(":::::::::::::::::::::::::::::::::\n");
    }
}





// FUNÇÕES ÚTEIS À QUERIE 1


// return 1 se encontrou o utilizador e colocou os dados

int* lookup_username(USERS users_list, char *username, char *name, char *gender, char *birth_date, int *numero_viagens){
    USER aux;
    int index = hash_func(username);
    for (aux = users_list[index]; aux != NULL && strcmp(aux->username,username) != 0; aux = aux->prox);
    if (aux == NULL || !strcmp(aux->account_status,"inactive")) return NULL;
    strcpy(name,aux->name);
    strcpy(gender,aux->gender);
    strcpy(birth_date,aux->birth_date); 
    *numero_viagens = aux->sp;
    return aux->positions;
}



// FUNÇões ÚTEIS À QUERIE 8

// função que guarda em três pointers o nome e a birth_date, returna 1 se consegui recolher os dados

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
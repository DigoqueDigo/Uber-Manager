#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie8.h>



struct sort_gender{
    int id_driver;
    char *name_driver;
    int account_creation_driver;
    char *account_driver;
    char *username;
    char *name_user;
    int account_creation_user;
    char *account_user;
    int id_ride;
};


SORT_GENDER init_sort_gender(int N_RIDES){
    SORT_GENDER new = malloc(N_RIDES/2*sizeof(struct sort_gender));
    return new;
}


void free_sort_gender(SORT_GENDER list, int N){
    for (int p = 0; p < N; p++){
        if (list[p].name_driver != NULL){
            free(list[p].name_driver);
            free(list[p].account_driver);
            free(list[p].username);
            free(list[p].name_user);
            free(list[p].account_user);
        }
    }
    free(list);
}


void push_sort_gender(SORT_GENDER list, int *N, int id_driver, char *name_driver, int account_creation_driver, char *username, char *name_user, int account_creation_user, int id_ride, char *account_driver, char *account_user){
    struct sort_gender new;
    new.id_driver = id_driver;
    new.account_creation_driver = account_creation_driver;
    new.account_creation_user = account_creation_user;
    new.name_driver = strdup(name_driver);
    new.username = strdup(username);
    new.name_user = strdup(name_user);
    new.id_ride = id_ride;
    new.account_driver = strdup(account_driver);
    new.account_user = strdup(account_user);
    list[*N] = new;
    ++*N;
}


void fill_sort_gender(USERS users_list, DRIVERS drivers_list, RIDES rides_list, SORT_GENDER list, int *N, char *gender, int N_DRIVERS){
    char driver_name[50], driver_account_creation[50], driver_gender[3];
    char user_name[50], username[50], user_account_creation[50];
    int *positions, sp;
    for (int p = 1; p < N_DRIVERS; p++){

        lookup_driver_gender(drivers_list,p,driver_gender);

        if (!strcmp(driver_gender,gender) && lookup_driver_accounts_status(drivers_list,p)){
            
            positions = lookup_driver_positions(drivers_list,p,&sp);
            lookup_driver_name(drivers_list,p,driver_name);
            lookup_driver_account_creation(drivers_list,p,driver_account_creation);
            
            for (int i = 0; i < sp; i++){
               
               
                lookup_rides_username(rides_list,positions[i],username);

                int aux = lookup_user(users_list,username,user_name,user_account_creation,gender);
                if (aux){

                    int aux_1 = convert_date_to_int(driver_account_creation);
                    int aux_2 = convert_date_to_int(user_account_creation);
                   
                    push_sort_gender(list,N,p,driver_name,aux_1,username,user_name,aux_2,positions[i],driver_account_creation,user_account_creation);
                }
            }
        }
    }
}


int cmprfunc_driver(const void *a, const void *b){
    const struct sort_gender *x = a, *y = b;
    return (x->account_creation_driver - y->account_creation_driver); 
}


int cmprfunc_user(const void *a,const void *b){
    const struct sort_gender *x = a, *y = b;
    return (x->account_creation_user - y->account_creation_user);
}


int cmprfunc_id_ride(const void *a, const void *b){
    const struct sort_gender *x = a, *y = b;
    return (x->id_ride - y->id_ride);
}


void resolve_querie8(char *command, int ncommand, USERS users_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS, int N_RIDES){
    
    FILE *ficheiro;

    char output_file[500] = "", *token;
    int age, N = 0;


    set_command_name(output_file,ncommand);

    token = strtok(command," " "\n");
    token = strtok(NULL, " " "\n");
    token = strtok(NULL, " " "\n");

    age = atoi(token);

    SORT_GENDER list = init_sort_gender(N_RIDES);

    if (command[2] == 'F'){

        fill_sort_gender(users_list,drivers_list,rides_list,list,&N,"F",N_DRIVERS);
    }

    else if (command[2] == 'M'){

        fill_sort_gender(users_list,drivers_list,rides_list,list,&N,"M",N_DRIVERS);
    }

    sort_three_compare(list,N,sizeof(struct sort_gender),cmprfunc_driver,cmprfunc_user,cmprfunc_id_ride);

    ficheiro = fopen(output_file, "a");

    for (int p = 0; p < N; p++){

        if (calculate_idade(list[p].account_driver) >= age && calculate_idade(list[p].account_user) >= age){

            fprintf(ficheiro, "%012d;%s;%s;%s\n", list[p].id_driver, list[p].name_driver,list[p].username,list[p].name_user);   
        }   
    }
    
    free_sort_gender(list,N);

    fclose(ficheiro);
}
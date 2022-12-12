#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie8.h>



struct sort_gender{
    int id_driver;
    char *name_driver;
    int account_creation_driver;
    char *username;
    char *name_user;
    int account_creation_user;
    int id_ride;
};


SORT_GENDER init_sort_gender(){
    SORT_GENDER new = malloc(CAP_GENDER*sizeof(struct sort_gender));
    return new;
}


void free_sort_gender(SORT_GENDER list, int N){
    for (int p = 0; p < N; p++){
        if (list[p].name_driver != NULL){
            free(list[p].name_driver);
            free(list[p].username);
            free(list[p].name_user);
        }
    }
    free(list);
}



int fill_sort_gender(USERS users_list, DRIVERS drivers_list, RIDES rides_list, SORT_GENDER *list, char *gender, int N_DRIVERS, int age){
    
    char driver_name[500], driver_account_creation[500], driver_gender[30];
    char user_name[500], username[500], user_gender[30], *user_account_creation;
    int *positions, sp, N = 0, temp, size = CAP_GENDER, index;
    
    for (int p = 1; p < N_DRIVERS; p++){

        if (analyse_driver(drivers_list,p)){

            lookup_driver_gender(drivers_list,p,driver_gender);
            lookup_driver_account_creation(drivers_list,p,driver_account_creation);

            temp = calculate_idade(driver_account_creation);
 

            if (temp >= age && !strcmp(driver_gender,gender) && lookup_driver_accounts_status(drivers_list,p)){

                positions = lookup_driver_positions(drivers_list,p,&sp);
                lookup_driver_name(drivers_list,p,driver_name);
            
                
                for (int i = 0; i < sp; i++){

                    
                    if (analyse_ride(rides_list,positions[i])){

                        lookup_rides_username(rides_list,positions[i],username);
                        index = hash_func(username);

                        
                        if (analyse_user(users_list,username,index)){
                        
                            lookup_user_gender(users_list,username,user_gender,index);

                            
                            if (!strcmp(user_gender,gender) && lookup_user_account_status(users_list,username,index)){

                                lookup_user_name(users_list,username,user_name,index);
                                user_account_creation = lookup_user_account_creation(users_list,username,index);

                    
                                if (calculate_idade(user_account_creation) >= age){

                                    int aux_1 = convert_date_to_int(driver_account_creation);
                                    int aux_2 = convert_date_to_int(user_account_creation);

                                    
                                    if (N >= size){

                                        size *= 2;
                                        *list = realloc(*list,size*sizeof(struct sort_gender));
                                    }                           

                                    (*list)[N].id_driver = p;
                                    (*list)[N].account_creation_driver = aux_1;
                                    (*list)[N].account_creation_user = aux_2;
                                    (*list)[N].name_driver = strdup(driver_name);
                                    (*list)[N].username = strdup(username);
                                    (*list)[N].name_user = strdup(user_name);
                                    (*list)[N++].id_ride = positions[i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return N;
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


void resolve_querie8(char *command, int ncommand, USERS users_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS){
    
    FILE *ficheiro;

    SORT_GENDER list = init_sort_gender();

    char output_file[500] = "", *token, gender[2];
    int age, N;

    gender[0] = command[2];
    gender[1] = '\0';

    set_command_name(output_file,ncommand);

    token = strtok(command," " "\n");
    token = strtok(NULL, " " "\n");
    token = strtok(NULL, " " "\n");

    age = atoi(token);

    ficheiro = fopen(output_file, "w");


    N = fill_sort_gender(users_list,drivers_list,rides_list,&list,gender,N_DRIVERS,age);

    sort_three_compare(list,N,sizeof(struct sort_gender),cmprfunc_driver,cmprfunc_user,cmprfunc_id_ride);

    for (int p = 0; p < N; p++){

        fprintf(ficheiro, "%012d;%s;%s;%s\n", list[p].id_driver, list[p].name_driver,list[p].username,list[p].name_user);   
    }
    
    free_sort_gender(list,N);

    fclose(ficheiro);
}
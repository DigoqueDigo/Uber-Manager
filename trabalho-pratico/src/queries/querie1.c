#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie1.h>




void calculate_user(USERS users_list, DRIVERS drivers_list, RIDES rides_list, FILE *ficheiro, char *username){
    
    int sp, *positions, id_driver, distance, age;
    char birth_date[100], gender[100], name[100], car_class[100];
    double average_score = 0,  money = 0, tip;

    positions = lookup_user_positions(users_list,username,&sp);

    if (positions == NULL || lookup_user_account_status(users_list,username) == 0) return;

    lookup_user_name(users_list,username,name);
    lookup_user_gender(users_list,username,gender);
    lookup_user_birth_date(users_list,username,birth_date);

    for (int p = 0; p < sp; p++){

        id_driver = lookup_rides_id_driver(rides_list,positions[p]);

        if (id_driver != -1){

            distance = lookup_rides_distance(rides_list,positions[p]);

            if (distance){

                average_score += lookup_rides_score_user(rides_list,positions[p]);

                lookup_car_class(drivers_list,id_driver,car_class);
                tip = lookup_rides_tip(rides_list,positions[p]);

                if (!strcasecmp(car_class,"basic")){

                    money += distance * TK_BASIC + T_BASIC + tip;
                }

                else if (!strcasecmp(car_class,"green")){

                    money += distance * TK_GREEN + T_GREEN + tip;
                }

                else if (!strcasecmp(car_class,"premium")){

                    money += distance * TK_PREMIUM + T_PREMIUM + tip;
                }
            }
        }
    }

    average_score /= sp;

    age = calculate_idade(birth_date);

    fprintf(ficheiro, "%s;%s;%d;%.3f;%d;%.3f\n", name, gender, age, average_score, sp, money);
}



void calculate_driver(DRIVERS drivers_list, RIDES rides_list, FILE *ficheiro, int id){
    
    int sp, *positions, distance, age;
    char birth_date[100], gender[100], name[100], car_class[100];
    double average_score = 0, money = 0, tip;

    if (lookup_driver_name(drivers_list,id,name) == 0) return;

    if (lookup_driver_accounts_status(drivers_list,id) == 0) return;

    positions = lookup_driver_positions(drivers_list,id,&sp);
    lookup_car_class(drivers_list,id,car_class);
    lookup_driver_gender(drivers_list,id,gender);
    lookup_driver_birth_date(drivers_list,id,birth_date);

    for (int p = 0; p < sp; p++){

        distance = lookup_rides_distance(rides_list,positions[p]);

        if (distance){

            tip = lookup_rides_tip(rides_list,positions[p]);
            average_score += lookup_rides_score_driver(rides_list,positions[p]);

            if (!strcasecmp(car_class,"basic")){

                money += distance * TK_BASIC + T_BASIC + tip;
            }

            else if (!strcasecmp(car_class,"green")){

                money += distance * TK_GREEN + T_GREEN + tip;
            }

            else if (!strcasecmp(car_class,"premium")){

                money += distance * TK_PREMIUM + T_PREMIUM + tip;
            }
        }
    }

    average_score /= sp;
    age = calculate_idade(birth_date);

    fprintf(ficheiro, "%s;%s;%d;%.3f;%d;%.3f\n", name, gender, age, average_score, sp, money);
}



void resolve_querie1(char *commands, int ncommand, USERS lista, DRIVERS drivers_lista, RIDES rides_lista, int N_DRIVERS){

    FILE *ficheiro;

    int valor;
    char output_file[500] = "", *token;

    set_command_name(output_file,ncommand);

    token = strtok(commands, " " "\n");
    token = strtok(NULL, " " "\n");

    valor = check_id(token);
    
    ficheiro = fopen(output_file, "a");

    if (valor){

        valor = atoi(token);

        if (valor < N_DRIVERS) calculate_driver(drivers_lista,rides_lista,ficheiro,valor);
    }

    else calculate_user(lista,drivers_lista,rides_lista,ficheiro,token);

    fclose(ficheiro);
}
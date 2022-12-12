#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie1.h>




void calculate_user(USERS users_list, DRIVERS drivers_list, RIDES rides_list, FILE *ficheiro, char *username){
    
    int sp, *positions, id_driver, distance, age, index = hash_func(username);
    char birth_date[100], gender[100], name[100], car_class[100];
    double average_score = 0,  money = 0, tip;

    if (analyse_user(users_list,username,index) == 0 || lookup_user_account_status(users_list,username,index) == 0) return;

    lookup_user_name(users_list,username,name,index);
    lookup_user_gender(users_list,username,gender,index);
    lookup_user_birth_date(users_list,username,birth_date,index);

    positions = lookup_user_positions(users_list,username,&sp,index);

    for (int p = 0; p < sp; p++){

        if (analyse_ride(rides_list,positions[p])){

            distance = lookup_rides_distance(rides_list,positions[p]);
            average_score += lookup_rides_score_user(rides_list,positions[p]);

            tip = lookup_rides_tip(rides_list,positions[p]);
            id_driver = lookup_rides_id_driver(rides_list,positions[p]);

            if (analyse_driver(drivers_list,id_driver)){

                lookup_car_class(drivers_list,id_driver,car_class);

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

    if (sp > 0) average_score /= sp;

    age = calculate_idade(birth_date);

    fprintf(ficheiro, "%s;%s;%d;%.3f;%d;%.3f\n", name, gender, age, average_score, sp, money);
}



void calculate_driver(DRIVERS drivers_list, RIDES rides_list, FILE *ficheiro, int id){
    
    int sp, *positions, distance, age, class = -1;
    char birth_date[100], gender[100], name[100], car_class[100];
    double average_score = 0, money = 0, tip;

    if (analyse_driver(drivers_list,id) == 0 || lookup_driver_accounts_status(drivers_list,id) == 0) return;

    lookup_car_class(drivers_list,id,car_class);
    lookup_driver_gender(drivers_list,id,gender);
    lookup_driver_birth_date(drivers_list,id,birth_date);
    lookup_driver_name(drivers_list,id,name);

    if (!strcasecmp(car_class,"basic")) class = 0;

    else if (!strcasecmp(car_class,"green")) class = 1;

    else if (!strcasecmp(car_class,"premium")) class = 2;

    positions = lookup_driver_positions(drivers_list,id,&sp);

    for (int p = 0; p < sp; p++){

        if (analyse_ride(rides_list,positions[p])){

            distance = lookup_rides_distance(rides_list,positions[p]);
            tip = lookup_rides_tip(rides_list,positions[p]);
            average_score += lookup_rides_score_driver(rides_list,positions[p]);

            switch (class){

                case 0:
                    money += distance * TK_BASIC + T_BASIC + tip;
                    break;

                case 1:
                    money += distance * TK_GREEN + T_GREEN + tip;
                    break;

                case 2:
                    money += distance * TK_PREMIUM + T_PREMIUM + tip;
                    break;
            }
        }
    }

    if (sp > 0) average_score /= sp;
    
    age = calculate_idade(birth_date);

    fprintf(ficheiro, "%s;%s;%d;%.3f;%d;%.3f\n", name, gender, age, average_score, sp, money);
}



void resolve_querie1(char *command, int ncommand, USERS users_list, DRIVERS drivers_list, RIDES rides_list, int N_DRIVERS){

    FILE *ficheiro;

    int valor;
    char output_file[500] = "", *token;

    set_command_name(output_file,ncommand);

    token = strtok(command, " " "\n");
    token = strtok(NULL, " " "\n");

    valor = check_id(token);
    
    ficheiro = fopen(output_file, "w");

    if (valor){

        valor = atoi(token);

        if (valor < N_DRIVERS) calculate_driver(drivers_list,rides_list,ficheiro,valor);
    }

    else calculate_user(users_list,drivers_list,rides_list,ficheiro,token);

    fclose(ficheiro);
}
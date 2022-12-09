#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parsing/parser.h>



void set_user_line(char **linha, char *string, USERS lista){
    
    int p = 0, valid = 1;
    
    char *token = strtok(string, ";" "\n");

    for (; token && p < CAP_LINE_USER && valid; token = strtok(NULL, ";" "\n"), p++){

        switch (p){

            case 0:
                if (check_username(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 1:
                if (check_name(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 2:
                if (check_gender(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 3:
                if (check_date(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 4:
                if (check_account_creation(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 5:
                if (check_pay_method(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 6:
                if (check_account_status(token)) linha[p] = strdup(token);
                else valid = 0;
                break;
        }
    }

    if (p == 7 && token == NULL){
        
        push_user(lista,
            linha[0],
            linha[1],
            linha[2],
            linha[3],
            linha[4],
            linha[5],
            linha[6]);
    }

    if (!valid) p--;

    for (int i = 0; i < p; free(linha[i++]));
}



int set_driver_line(char **linha, char *string, DRIVERS lista){
    
    int p = 0, valid = 1;

    char *token = strtok(string, ";" "\n");

    for (; token && p < CAP_LINE && valid; token = strtok(NULL, ";" "\n"), p++){

        switch (p){

            case 0:
                if (check_id(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 1:
                if (check_name(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 2:
                if (check_date(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 3:
                if (check_gender(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 4:
                if (check_car_class(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 5:
                if (check_license_plate(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 6:
                if (check_city(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 7:
                if (check_account_creation(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 8:  
                if (check_account_status(token)) linha[p] = strdup(token);
                else valid = 0;
                break;
        }  
    }

    if (p == CAP_LINE && token == NULL){
        
        push_driver(lista,
            linha[0],
            linha[1],
            linha[2],
            linha[3],
            linha[4],
            linha[5],
            linha[6],
            linha[7],
            linha[8]);
    }

    if (!valid) p--;

    for (int i = 0; i < p; free(linha[i++]));

    return (p == CAP_LINE && valid);
}



int set_ride_line(char **linha, char *string, RIDES lista, USERS lista_users, DRIVERS lista_drivers, CITIES cities_list, int *N_CITIES){
    
    int p = 0, valid = 1;

    char *token = strtok(string, ";" "\n");

    for (; token && p < CAP_LINE && valid; token = strtok(NULL, ";" "\n"), p++){

        switch (p){

            case 0:
                if (check_id(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 1:
                if (check_date(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 2:
                if (check_id(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 3:
                if (check_username(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 4:
                if (check_city(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 5:
                if (check_distance(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 6:
                if (check_id(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 7:
                if (check_id(token)) linha[p] = strdup(token);
                else valid = 0;
                break;

            case 8:
                if (check_tip(token)) linha[p] = strdup(token);
                else valid = 0;
                break;
        }
    }

    if (p == CAP_LINE){

        int index = atoi(linha[0]);

        push_position(lista_users,index,linha[3]);

        push_position_driver(lista_drivers,index,linha[2]);

        push_city(cities_list,linha[4],index,N_CITIES);

        push_ride(lista,
            linha[0],
            linha[1],
            linha[2],
            linha[3],
            linha[4],
            linha[5],
            linha[6],
            linha[7],
            linha[8]);
    }

    if (!valid) p--;

    for (int i = 0; i < p; free(linha[i++]));

    return (p == CAP_LINE && valid);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"parser.h"



struct line{
    char *data;
};


int set_driver_line(LINE linha, char *string, DRIVERS lista){
    int p;
    char *token;

    token = strtok(string, ";" "\n");

    for (p = 0; token != NULL; token = strtok(NULL, ";" "\n"), p++){
       
        if (p >= 9) return 0;

        switch (p){

            case 0:
                if (check_id(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 1:
                if (check_name(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 2:
                if (check_date(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 3:
                if (check_gender(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 4:
                if (check_car_class(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 5:
                if (check_license_plate(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 6:
                if (check_city(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 7:
                if (check_account_creation(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 8:  
                if (check_account_status(token)) linha[p].data = strdup(token);
                else return 0;
                break;
        }  
    }
    if (p == 9 && token == NULL){
        
        push_driver(lista,
            linha[0].data,
            linha[1].data,
            linha[2].data,
            linha[3].data,
            linha[4].data,
            linha[5].data,
            linha[6].data,
            linha[7].data,
            linha[8].data);
        
        return 1;
    }
    
    return 0;

}


void print_driver_line(LINE line){
    for (int p = 0; p < 9; p++){
        printf("%s;", line[p].data);
    }
    putchar('\n');
}


void destroy_driver_line(LINE line){
    for (int p = 0; p < 9; p++){
        free(line[p].data);
    }
}


int set_user_line(LINE linha, char *string, USERS lista){
    int p;
    char *token;
    
    token = strtok(string, ";" "\n");

    for (p = 0; token != NULL; token = strtok(NULL, ";" "\n"), p++){

        if (p >= 7) return 0;

        switch (p){

            case 0:
                if (check_username(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 1:
                if (check_name(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 2:
                if (check_gender(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 3:
                if (check_date(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 4:
                if (check_account_creation(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 5:
                if (check_pay_method(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 6:
                if (check_account_status(token)) linha[p].data = strdup(token);
                else return 0;
                break;
        }
    }

    if (p == 7 && token == NULL){
        
        push_user(lista,
            linha[0].data,
            linha[1].data,
            linha[2].data,
            linha[3].data,
            linha[4].data,
            linha[5].data,
            linha[6].data);
        
        return 1;
    }
    
    return 0;
}


void print_user_line(LINE line){
    for (int p = 0; p < 7; p++){
        printf("%s;", line[p].data);
    }
    putchar('\n');
}


void destroy_user_line(LINE line){
    for (int p = 0; p < 7; p++){
        free(line[p].data);
    }
}


int set_ride_line(LINE linha, char *string, RIDES lista, USERS lista_users, DRIVERS lista_drivers){
    int p;
    char *token;
    
    token = strtok(string, ";" "\n");

    for (p = 0; p < 9 && token != NULL; token = strtok(NULL, ";" "\n"), p++){

        switch (p){

            case 0:
                if (check_id(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 1:
                if (check_date(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 2:
                if (check_id(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 3:
                if (check_username(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 4:
                if (check_city(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 5:
                if (check_id(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 6:
                if (check_id(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 7:
                if (check_id(token)) linha[p].data = strdup(token);
                else return 0;
                break;

            case 8:
                if (check_tip(token)) linha[p].data = strdup(token);
                else return 0;
                break;
        }
    }

    if (p == 9){

        int index = atoi(linha[0].data);


        push_position(lista_users,index,linha[3].data);

        push_position_driver(lista_drivers,index,linha[2].data);


        push_ride(lista,
            linha[0].data,
            linha[1].data,
            linha[2].data,
            linha[3].data,
            linha[4].data,
            linha[5].data,
            linha[6].data,
            linha[7].data,
            linha[8].data);

        return 1;
    }
    return 0;
}
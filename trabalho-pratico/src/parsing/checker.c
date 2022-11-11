#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <parsing/checker.h>


int check_id(char *string){
    if (string[0] == '\0') return 0;
    for (int p = 0; string[p] != '\0'; p++){
        if (isdigit(string[p]) == 0) return 0;
    }
    return 1;
}

int check_name(char *string){
    if (string[0] == '\0') return 0;
    for (int p = 0; string[p] != '\0'; p++){
        if (isdigit(string[p]) > 0) return 0;
    }
    return 1;
}

int check_date(char *string){
    if (strlen(string) != 10) return 0;
    if (string[2] != '/' || string[5] != '/') return 0;
    string[2] = '\0'; string[5] = '\0';
    int a = atoi(string), b = atoi(string+3), c = atoi(string+6);
    if (a < 1 || a > 31) return 0;
    if (b < 1 || b > 12) return 0;
    if (c < 1 || c > 2022) return 0;
    string[2] = '/'; string[5] = '/';
    return 1;
}


int check_gender(char *string){
    if (string[0] == 'F' || string[0] == 'M') return 1;
    return 0;
}


int check_car_class(char *string){
    if (!strcasecmp(string,"green") || !strcasecmp(string,"premium") || !strcasecmp(string,"basic")) return 1;
    return 0;
}


int check_city(char *string){
    if (string[0] == '\0') return 0;
    for (int p = 0; string[p] != '\0'; p++){
        if (isdigit(string[p])) return 0;
    }
    return 1;
}


int check_account_creation(char *string){
    return check_date(string);
}


int check_account_status(char *string){
    if (!strcasecmp(string,"active") || !strcasecmp(string,"inactive")) return 1;
    return 0;
}


int check_license_plate(char *string){
    int conta_dig = 0, conta_al = 0;
    if (strlen(string) != 8) return 0;
    else if (string[2] != '-' || string[5] != '-') return 0;
    for (int p = 0; string[p] != 0; p++){
        if (isdigit(string[p])) conta_dig++;
        else if (isalpha(string[p])) conta_al++;
    }
    if (conta_dig == 2 && conta_al == 4) return 1;
    else if (conta_dig == 4 && conta_al == 2) return 1;
    return 0;
}


int check_pay_method(char *string){
    if (!strcmp(string,"cash") || !strcmp(string,"credit_card") || !strcmp(string,"debit_card")) return 1;
    return 0;
}


int check_username(char *string){
    if (string[0] == '\0') return 0;
    for (int p = 0; string[p] != '\0'; p++){
        if (string[p] == ' ') return 0;
    }
    return 1;
}


int check_tip(char *string){
    for (int p = 0; string[p] != '\0'; p++){
        if (!isdigit(string[p]) && string[p] != '.') return 0;
    }
    return 1;
}
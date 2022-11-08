#ifndef CHECKER_H
#define CHECKER_H


/*
As funções retornam sempre uma determinada componente
da linha seja valida e zero caso seja inválida
*/

int check_id(char *string);

int check_name(char *string);

int check_date(char *string);

int check_gender(char *string);

int check_car_class(char *string);

int check_city(char *string);

int check_account_creation(char *string);

int check_account_status(char *string);

int check_license_plate(char *string);

int check_pay_method(char *string);

int check_username(char *string);

int check_tip(char *string);

#endif
#ifndef FIXTURES_H
#define FIXTURES_H

#include"users.h"
#include"drivers.h"
#include"rides.h"


int calculate_idade(char *birth_date);

void creat_date(int age, char *string);

void convert_id_to_string(char *string, int id);

int convert_date_to_int(char *string);

void set_command_name(char *command, int N);

#endif
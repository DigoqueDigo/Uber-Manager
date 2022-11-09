#ifndef PARSER_H
#define PARSER_H

#include <parsing/checker.h>
#include <catalogs/users.h>
#include <catalogs/rides.h>
#include <catalogs/drivers.h>


typedef struct line *LINE;


// retorna 1 se a linha de input estava bem formada

int set_driver_line(LINE linha, char *string, DRIVERS lista);

void print_driver_line(LINE line);

void destroy_driver_line(LINE line);

int set_user_line(LINE linha, char *string, USERS lista);

void print_user_line(LINE line);

void destroy_user_line(LINE line);

int set_ride_line(LINE line, char *string, RIDES lista, USERS lista_users, DRIVERS lista_drivers);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queries/querie1.h>


/*
    USER
    nome;genero;idade;avaliacao_media;numero_viagens;total_gasto

    DRIVER
    nome;genero;idade;avaliacao_media;numero_viagens;total_auferido

*/


int calculate_user(USERS users_list, DRIVERS drivers_list, RIDES rides_list, char *username, char *name, char *gender, char *birth_date, int *numero_viagens, double *score, double *money){
    int id_driver;
    int *positions = lookup_username(users_list,username,name,gender,birth_date,numero_viagens);
    char car_class[10];
    if (positions == NULL) return 0;
    for (int p = 0; p < *numero_viagens; p++){
        id_driver = lookup_id_driver(rides_list,positions[p]);
        lookup_car_class(drivers_list,id_driver,car_class);
        calculate_floats(rides_list,positions[p],car_class,score,money,0);
    }
    *score /= *numero_viagens;
    return 1;
}


int calculate_driver(DRIVERS drivers_list, RIDES rides_list, int id, char *name, char *gender, char *birth_date, int *numero_viagens, double *score, double *money){
    char car_class[10];
    int *positions = lookup_driver(drivers_list,id,name,gender,birth_date,car_class,numero_viagens);
    if (positions == NULL) return 0;
    for (int p = 0; p < *numero_viagens; p++){
        calculate_floats(rides_list,positions[p],car_class,score,money,1);
    }
    *score /= *numero_viagens;
    return 1;
}


// o valor é uma variavel que diz se estou a tratar de um id ou username

void resolve_querie1(char *commands, int ncommand, USERS lista, DRIVERS drivers_lista, RIDES rides_lista, int N_DRIVERS){

    FILE *ficheiro;

    int idade, numero_viagens, valor;

    double score = 0, money = 0; 

    char output_name[40], output_genero[3], birth_date[12], *token = strtok(commands, " " "\n");

    char output_file[500] = "";

    set_command_name(output_file,ncommand);

    
    token = strtok(NULL, " " "\n");

    valor = check_id(token);
    
    ficheiro = fopen(output_file, "a");

    if (valor){

        valor = atoi(token);

        if (valor < N_DRIVERS && calculate_driver(drivers_lista,rides_lista,valor,output_name,output_genero,birth_date,&numero_viagens,&score,&money)){

            idade = calculate_idade(birth_date);

            fprintf(ficheiro, "%s;%s;%d;%.3f;%d;%.3f\n", output_name, output_genero, idade, score, numero_viagens, money);            

        }
    }

    else{
        
        if (calculate_user(lista,drivers_lista,rides_lista,token,output_name,output_genero,birth_date,&numero_viagens,&score,&money)){

            idade = calculate_idade(birth_date);

           fprintf(ficheiro, "%s;%s;%d;%.3f;%d;%.3f\n", output_name, output_genero, idade, score, numero_viagens, money);
        }
    }

    fclose(ficheiro);
}
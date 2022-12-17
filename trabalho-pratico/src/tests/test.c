#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <tests/test.h>


struct test{
    char *query;
    char *expected;
    char *obtained;
    double time;
    short int checker;
};


TESTS init_tests(){
    TESTS new = malloc(CAP_TESTS*sizeof(struct test));
    return new;
}


void realloc_tests(TESTS *tests_list, int new_size){
    *tests_list = realloc(*tests_list,new_size*sizeof(struct test));
}


void push_test(TESTS *tests_list, char *query, double time, int *N_TESTS, int *SIZE_TESTS){

    if (*N_TESTS >= *SIZE_TESTS){

        *SIZE_TESTS *= 2;
        realloc_tests(tests_list,*SIZE_TESTS);
    }

    (*tests_list)[*N_TESTS].query = strdup(query);
    (*tests_list)[*N_TESTS].time = time;

    ++*N_TESTS;
}


void push_test_comparation(TESTS tests_list, int index, short int checker, char *obtained, char *expected){
    
    if (!checker){
        
        tests_list[index].obtained = strdup(obtained);
        tests_list[index].expected = strdup(expected);
    }
    
    tests_list[index].checker = checker;
}


void free_tests(TESTS tests_list, int N_TESTS){

    for (int p = 0; p < N_TESTS; p++){
        
        free(tests_list[p].query);
        
        if (!tests_list[p].checker){
            
            free(tests_list[p].obtained);
            free(tests_list[p].expected);
        }
    }

    free(tests_list);
}


void print(char *sintax, FILE *ficheiro, ...){

    char aux_sintax[20], *token;

    strcpy(aux_sintax,sintax);
    token = strtok(aux_sintax, ",");

    va_list arguments;
    va_start(arguments,ficheiro); 

    if (ficheiro == NULL){

        for (int p = 0; token; token = strtok(NULL, ","), p++){

            if (token[0] == 's') printf("%s", va_arg(arguments,char*));

            else if (token[0] == 'd') printf("%d", va_arg(arguments,int));

            else if (token[0] == 'f') printf("%f", va_arg(arguments,double));
        }
    }
        
    else{

        for (int p = 0; token; token = strtok(NULL, ","), p++){

            if (token[0] == 's') fprintf(ficheiro, "%s", va_arg(arguments,char*));

            else if (token[0] == 'd') fprintf(ficheiro, "%d", va_arg(arguments,int));

            else if (token[0] == 'f') fprintf(ficheiro, "%f", va_arg(arguments,double));
        }
    }

    va_end(arguments);
}


void print_tests(TESTS tests_list, int N_TESTS, double *catalogs_time, char *test_file){

    FILE *ficheiro = NULL;

    double total_time = 0.0;

    int correct = 0, columns = 205;

//  columns = get_terminal_columns();

    if (test_file != NULL){

        ficheiro = fopen(test_file,"w");

        if (ficheiro == NULL){

            perror(test_file);
            return;
        }
    }

    for (int p = 0; p < N_TESTS; p++){

        total_time += tests_list[p].time;
        
        print_separator_line(columns,ficheiro);

        print("s,d,s,s,s", ficheiro, "\n\nTeste:\t\t\t", p+1, "\nQuery:\t\t\t", tests_list[p].query, "\n");

        if (tests_list[p].checker){

            print("s", ficheiro, "Execução:\t\tVálida\n");
            print("s,f,s", ficheiro, "Tempo:\t\t\t", tests_list[p].time, " segundos\n\n");
            
            correct++;
        }

        else{

            print("s", ficheiro, "Execução:\t\tInválida\n");
            print("s,f,s", ficheiro, "Tempo:\t\t\t", tests_list[p].time, " segundos\n");
            print("s,s,s", ficheiro, "Linha obtida:\t\t", tests_list[p].obtained, "\n");
            print("s,s,s", ficheiro, "Linha esperada:\t\t", tests_list[p].expected, "\n\n");
        }
    }

    print_separator_line(columns,ficheiro);

    print("s", ficheiro, "\n\nSUMÁRIO TEMPORAL\n\n");
    print("s,f,s", ficheiro, "Recolha dos utilizadores:\t", catalogs_time[0], " segundos\n");
    print("s,f,s", ficheiro, "Recolha dos condutores:\t\t", catalogs_time[1], " segundos\n");
    print("s,f,s", ficheiro, "Recolha das viagens/cidades:\t", catalogs_time[2], " segundos\n");
    print("s,f,s", ficheiro, "Execução das queries:\t\t", total_time, " segundos\n");
    print("s,f,s", ficheiro, "Validação dos resultados:\t", catalogs_time[3], " segundos\n");
    print("s,f,s", ficheiro, "Tempo total de execução:\t", catalogs_time[4], " segundos\n\n");

    print_separator_line(columns,ficheiro);

    print("s", ficheiro, "\n\nSUMÁRIO FINAL\n\n");
    print("s,d,s,d,s", ficheiro, "Queries corretas: ", correct, "/", N_TESTS, "\n");
    print("s,d,s,d,s", ficheiro, "Queries incorretas: ", N_TESTS-correct, "/", N_TESTS, "\n\n");

    print_separator_line(columns,ficheiro);

    if (ficheiro != NULL) fclose(ficheiro);
}
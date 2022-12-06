#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        free(tests_list[p].obtained);
        free(tests_list[p].expected);
    }

    free(tests_list);
}


void print_tests(TESTS tests_list, int N_TESTS){

    for (int p = 0; p < N_TESTS; p++){
        
        printf("\n-----------------------------------------\n\n");

        printf("Query:\t%s\n", tests_list[p].query);

        if (tests_list[p].checker){

            printf("Execução:\tVálida");
            printf("Tempo:\t%f\n", tests_list[p].time);
        }

        else{

            printf("Execução:\tInválida");
            printf("Linha obtida:\t%s", tests_list[p].obtained);
            printf("Linha esparada:\t%s", tests_list[p].expected);
        }
    }
}


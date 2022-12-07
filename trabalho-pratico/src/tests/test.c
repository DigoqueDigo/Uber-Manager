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
        
        if (!tests_list[p].checker){
            
            free(tests_list[p].obtained);
            free(tests_list[p].expected);
        }
    }

    free(tests_list);
}


void print_tests(TESTS tests_list, int N_TESTS){

    int correct = 0;

    for (int p = 0; p < N_TESTS; p++){
        
        printf("\n-----------------------------------------------------------------------\n\n");

        printf("%d\nQuery:\t\t\t%s\n", p+1, tests_list[p].query);

        if (tests_list[p].checker){

            printf("Execução:\t\tVálida\n");
            printf("Tempo:\t\t\t%f segundos\n", tests_list[p].time);
            
            correct++;
        }


        else{

            printf("Execução:\t\tInválida\n");
            printf("Tempo:\t\t\t%f segundos\n", tests_list[p].time);
            printf("Linha obtida:\t\t%s\n", tests_list[p].obtained);
            printf("Linha esparada:\t\t%s\n", tests_list[p].expected);
        }
    }

    printf("\n-----------------------------------------------------------------------\n\n");

    printf("SUMÁRIO FINAL\n\n");
    printf("Queries válidas: %d/%d\n", correct, N_TESTS);
    printf("Queries válidas: %d/%d\n", N_TESTS-correct, N_TESTS);

    printf("\n-----------------------------------------------------------------------\n\n");
}


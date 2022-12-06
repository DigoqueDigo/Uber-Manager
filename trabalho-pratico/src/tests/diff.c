#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tests/diff.h>



int compare_two_files(FILE *source, FILE *test){

    char source_line[1000], test_line[1000];

    while (fgets(source_line, 1000, source) && fgets(test_line, 1000, test)){

        if (strcmp(source_line,test_line)) return 0;
    }

    if (feof(source) && fgets(test_line, 1000, test)) return 0;

    if (!feof(source) || !feof(test)) return 0;

    return 1;
}


void set_all_comparations(TESTS tests_list, int N_TESTS, char *test_path){

    FILE *source, *test;

    char source_name[500], test_name[500];
    int checker;


    for (int p = 0; p < N_TESTS; p++){

        set_outfile_name(source_name,p+1,"Resultados");
        set_outfile_name(test_name,p+1,test_path);

        source = fopen(source_name, "r");
        test = fopen(test_name, "r");
    
        
        if (source == NULL || test == NULL){

            if (source == NULL) perror(source_name);

            else perror(test_name);

            return;
        }

        
        checker = compare_two_files(source,test);

        push_test_checker(tests_list,p,checker);

        fclose(source);
        fclose(test);
    }
}
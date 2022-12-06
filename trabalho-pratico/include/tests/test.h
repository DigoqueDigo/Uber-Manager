#ifndef TEST_H
#define TEST_H


#define CAP_TESTS 10

typedef struct test *TESTS;


TESTS init_tests();

void realloc_tests(TESTS *tests_list, int new_size);

void push_test(TESTS *tests_list, char *query, double time, int *N_TESTS, int *SIZE_TESTS);

void push_test_checker(TESTS tests_list, int index, short int checker);

void free_tests(TESTS tests_list, int N_TESTS);

#endif
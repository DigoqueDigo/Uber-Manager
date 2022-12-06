#ifndef DIFF_H
#define DIFF_H

#include <fixtures.h>
#include <tests/test.h>


int compare_two_files(FILE *source, FILE *test);

void set_all_comparations(TESTS tests_list, int N_TESTS, char *test_path);

#endif
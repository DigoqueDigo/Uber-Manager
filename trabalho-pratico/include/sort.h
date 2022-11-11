#ifndef SORT_H
#define SORT_H



void sort_two_compare(
    void *array, // array que se pretende ordenar
    int N, // numero de elementos do array
    size_t size, // tamanho (em bytes) de cada elemento do array
    int (*comp1)(const void*, const void*), // primeira função de comparação
    int (*comp2)(const void*, const void*) // segunda função de comparação caso persistam empates
);


void sort_three_compare(
    void *array, // array que se pretende ordenar
    int N, //numero de elementos do array
    size_t size, // tamanho (em bytes) de cada elemento do array
    int (*comp1)(const void*, const void*), // primeira função de comparação
    int (*comp2)(const void*, const void*), // segunda função de comparação
    int (*comp3)(const void*, const void*) // terceira função de comparação
);

#endif
#ifndef SORT_H
#define SORT_H


/**
 \file sort.h
 \brief Módulo para a ordenação de estruturas de dados
*/


/**
 * @brief Função que ordena um array conforme duas funções de comparação
 * 
 * @param array array que será ordenado conforme as funções de compararação
 * @param N comprimento do array
 * @param size tamanho em bytes de cada elemento do array
 * @param comp1 primeira função de comparação
 * @param comp2 segunda função de comparação
 */
void sort_two_compare(
    void *array,
    int N,
    size_t size,
    int (*comp1)(const void*, const void*),
    int (*comp2)(const void*, const void*)
);


/**
 * @brief Função que ordena um array conforme três funções de comparação
 * 
 * @param array array que será ordenado conforme as funções de compararação
 * @param N comprimento do array
 * @param size tamanho em bytes de cada elemento do array
 * @param comp1 primeira função de comparação
 * @param comp2 segunda função de comparação
* @param comp3 terceira função de comparação
 */
void sort_three_compare(
    void *array,
    int N,
    size_t size,
    int (*comp1)(const void*, const void*),
    int (*comp2)(const void*, const void*),
    int (*comp3)(const void*, const void*)
);

#endif
#include <stdio.h>
#include <stdlib.h>



void sort_two_compare(void *array, int N, size_t size, int (*comp1)(const void*, const void*), int (*comp2)(const void*, const void*)){

    int start = -1, last = 1;

    unsigned char *ptr = (unsigned char*) array;

    qsort(array,N,size,comp1);

    for (int p = 0, index = 0; p < N-1; p++, index += size){

        if (start == -1 && !comp1(ptr+index,ptr+index+size)){
            
            start = index;
            last++;
        }

        else if (!comp1(ptr+index,ptr+index+size)) last++;

        else if (start != -1){

            qsort(ptr+start,last,size,comp2);
            start = -1;
            last = 1;
        }
    }

    if (start != -1) qsort(ptr+start,last,size,comp2);

}



void sort_three_compare(void *array, int N, size_t size, int (*comp1)(const void*, const void*), int (*comp2)(const void*, const void*), int (*comp3)(const void*, const void*)){

    int start = -1, last = 1;

    unsigned char *ptr = (unsigned char*) array;

    sort_two_compare(array,N,size,comp1,comp2);

    for (int p = 0, index = 0; p < N-1; p++, index += size){

        if (start == -1 && !comp2(ptr+index,ptr+index+size) && !comp1(ptr+index,ptr+index+size)){

            start = index;
            last++;
        }

        else if (!comp2(ptr+index,ptr+index+size) && !comp1(ptr+index,ptr+index+size)) last++;

        else if (start != -1){

            qsort(ptr+start,last,size,comp3);
            start = -1;
            last = 1;
        }
    }

    if (start != -1) qsort(ptr+start,last,size,comp3);

}
#include <stdio.h>
#include <stdlib.h>
#include "dataStructure.h"

int main() {

    unsigned int index;

    // Test intArray_create
    intArray_t* arr = intArray_create(10);
    intArray_append(arr, 1);
    intArray_append(arr, 220);
    intArray_append(arr, 40);
    intArray_append(arr, 0);

    intArray_sort(arr);
    intArray_print(arr);
    
    free(arr);
    arr = NULL;

    return 0;
}
/*
* Filename: scrambled.c
*
* Description: determines whether two arrays are contain the same values, 
               regardless of order

* Author: Jerry Meng
*
* Date: June 4th, 2025
*/

#include <stdio.h>
#define SIZE 100

// Scrambled function

unsigned int scrambled( int arr1[], int arr2[], unsigned int size ){

    // Range is [0, 99], therefore we need 100 spots to hold all possible values in range
    int frequency_counter[SIZE] = {0};

    // 1st Test: Check if arrays are empty
    if(size == 0){
        return 1;
    }

    // 2nd Test: counts the # of times a value shows up
    for(int i = 0; i < size; i++){
        // Count # of times each value appears in arr1[]
        frequency_counter[arr1[i]]++;
    }

    for(int i = 0; i < size; i++){
        // Count # of times each value appears in arr2[]
        frequency_counter[arr2[i]]--;
    }

    for(int i = 0; i < SIZE; i++){
        // Each value must be 0 to indicate same arrays
        if(frequency_counter[i] != 0){
            return 0;
        }
    }

    // If 2nd test passes, return 1
    return 1;
}

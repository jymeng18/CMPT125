/*
* Filename: reverse.c
*
* Description: reverses the contents of an array of 10 integers in-place
*
* Author: Jerry Meng
*
* Date: May 30, 2025
*/

#define SIZE 10
#include <stdio.h>

int main(void){

    // Initialize an array with size 10
    int numbers[SIZE];
    for(int i = 0; i < SIZE; i++){
        numbers[i] = 0;
    }

    // Prompt user to enter 10 integers
    printf("Please, enter 10 integers then press Enter: ");
    for(int i = 0; i<10; i++){
        scanf("%d", &numbers[i]);
    }
    
    // Display content of array before reversing
    printf("Content of array before reversing:");
    for(int i = 0; i<10; i++){
        printf(" %d", numbers[i]);
    }
    printf("\n"); 

    // Reverse contents in the array 'numbers'
    for(int i = 0; i<5; i++){
        int tempNum = numbers[i];
        numbers[i] = numbers[9-i];
        numbers[9-i] = tempNum;
    }

    // Display reversed content of array 'numbers'
    printf("Content of array after reversing:");
    for(int i = 0; i<10; i++){
        printf(" %d", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
/*
* Name: JM
*
* Desc: User enters a set of integers, program outputs the sum of the odd ints
*
* Date: June 2025
*
* Filename: odd_sums.c
*/

#include <stdio.h>

// Declare function for user inputs
int oddSum(int arr1[], int size){

    int sum = 0;

    for(int i = 0; i < size; i++){
        if(arr1[i] % 2 != 0){
            sum += arr1[i];
        }
    }
    return sum;
}

int main(void){

    const int ARRAY_SIZE = 8;
    int userInputs[ARRAY_SIZE];

    int result;

    printf("Enter 8 integers: \n");
    for(int i = 0; i<ARRAY_SIZE; i++){
        result = scanf("%d", &userInputs[i]);

        if(result == 0){
            printf("User not well-behaved - Try again");
            return 1;
        }
    }

    printf("User entered: \n");
    for(int i = 0; i<ARRAY_SIZE; i++){
        printf("%d ", userInputs[i]);
    }

    // Call function oddSum
    printf("\nSum of all odd ints: %d\n", oddSum(userInputs, 8));
   
    return 0;
    
}
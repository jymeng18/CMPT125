/*
* Filename: verticalHistogram.c
*
* Description: 

* Author: Jerry Meng
*
* Date: June 4th, 2025
*/

#include <stdio.h>
#define SIZE 80

int main(void){

    // Intialize an array size of 80
    int user_inputs[SIZE];
    int user_input_counter = 0; // width of histogram
    int length = 0;

    // Prompt user to enter a set of integers, no more then 80
    printf("Please, enter integers (>=0) then press Enter and CTRL d: ");
    while(user_input_counter < SIZE && (scanf("%d", &user_inputs[user_input_counter]) == 1)){

        // Read in all user input
        user_input_counter++;
    }
    
    // Obtain length (largest value)
    for(int i=0; i<user_input_counter; i++){
        if(user_inputs[i] > length){
            length = user_inputs[i];
        } 
    }

    // Testing 
    printf("Length: %d, Width: %d\n", length, user_input_counter);

    for(int row = length; row > 0; row--){
        for(int col=0; col<user_input_counter; col++){

           if(user_inputs[col] >= row){
            printf("#");
           }
           else{
            printf(" ");
           }
        }
        printf("\n");
    }
    
    return 0;
}
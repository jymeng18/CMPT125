/*
* Filename: loop
*
* Description: 

* Author: Jerry Meng
*
* Date: May 24, 2025
*/

#include <stdio.h>
#include <math.h>

int main(void){

    float floatingValue;

    // Ask user to enter a floating point value
    printf("Please, enter a floating point value: ");

    // Read user input data and address to floatingValue
    int result = scanf("%f", &floatingValue);

    // Check that user is well behaved
    while(1){

        // Handle EOF inputs
        if(result == EOF){
            printf("\n");
            printf("Done.\n");
            return -1;
        }

        // Handle invalid inputs
        else if(result != 1){
            printf("Done1.\n");
            return -1;
        }

        // Exit loop if not errors
        else{

            break;
        }
    }

    // Display results for: smallest integer larger than or equal to user input value
    printf("The smallest integer larger than or equal to %.6f is %.0f.\n", floatingValue, ceil(floatingValue));

    // Display results for: nearest integer to its value (rounded away from zero)
    printf("The nearest integer to %.6f is %.0f.\n", floatingValue, round(floatingValue));

    // Display results for: largest integer smaller than or equal to user input value
    printf("The largest integer smaller than or equal to %.6f is %.0f.\n", floatingValue, floor(floatingValue));

    return 0;

}
/*
* Filename: moreScanf
*
* Description: values.c - Continued 
*
* Author: Jerry Meng
*
* Date: May 23rd, 2025
*/

#include <stdio.h>
#include <math.h>

int main(void){

    float floatingValue;

    // Ask user to enter a floating point value
    printf("Please, enter a floating point value: ");

    // Read user input data and address to floatingValue
    int result = scanf("%f", &floatingValue);

    // Ensure user is well behaved
    if (result != 1){
        printf("scanf error: (%d) | User is trolling \n", result);
        return 1; // Return 1 to indicate error
    }

    // Display results for: smallest integer larger than or equal to user input value
    printf("The smallest integer larger than or equal to %.6f is %.0f.\n", floatingValue, ceil(floatingValue));

    // Display results for: nearest integer to its value (rounded away from zero)
    printf("The nearest integer to %.6f is %.0f.\n", floatingValue, round(floatingValue));

    // Display results for: largest integer smaller than or equal to user input value
    printf("The largest integer smaller than or equal to %.6f is %.0f.\n", floatingValue, floor(floatingValue));

    return 0;

}
/*
* Filename: value
*
* Description: This program reads a floating point value from the user and
               prints: 
                -the smallest integer larger than or equal to the input value
                -the nearest integer (rounded away from zero) 
                -the largest integer smaller then or equal to the input value

* Author: Jerry Meng
*
* Date: May 22nd, 2025
*/

#include <stdio.h>
#include <math.h>

int main(void){

    float inputValue;

    // Ask user to enter a floating point value
    printf("Please, enter a floating point value: ");

    // Read users input
    scanf("%f", &inputValue);

    // Print the ceiling (smallest integer >= input)
    printf("The smallest integer larger than or equal to %.6f is %.0f.\n", inputValue, ceil(inputValue));

    // Print the rounded value (away from zero)
    printf("The nearest integer to %.6f is %.0f.\n", inputValue, round(inputValue));

    // Print the floor (largest integer <= input )
    printf("The largest integer smaller than or equal to %.6f is %.0f.\n", inputValue, floor(inputValue));

    return 0;

}
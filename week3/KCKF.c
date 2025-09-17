/*
 * Filename: KCKF.c
 *
 * Description: Ask the user for the conversion type: Kelvin -> Celsius or Kelvin -> Fahrenheit
 *              Ask the user for a temperature.
 *              Make sure the temperature is valid (no < 0.0 K)
 *              Convert this temperature to the other temperature 
 *              based on the selected conversion type.
 *
 * Author: AL
 * Date: May 2025
 */

#include <stdio.h>

int main( void ) {
	
    const char CELSIUS = 'C';
    // const char FAHRENHEIT = 'F';
    const double ABS_ZERO_IN_CELSIUS = -273.15;

    char choice = CELSIUS;
    float kelTemp = 0.0;
    float celTemp = 0.0;
    float fahTemp = 0.0;
		
    printf("To convert it to Celsius ... Enter C\n");
    printf("To convert it to Fahrenheit ... Enter F\n");
    printf("Your choice: ");
    scanf("%c", &choice );

    printf("Please, enter a Kelvin temperature: ");  // refactor code
    scanf("%f", &kelTemp );

`   if ( kelTemp >= 0.0 ) {
        if ( choice == CELSIUS ) {

            // Convert fahTemp to celTemp
            celTemp =  kelTemp + ABS_ZERO_IN_CELSIUS;
                
            printf("%0.1f Kelvin => %0.1f Celsius\n", kelTemp, celTemp); 
        } 
        else { // asumme choice == FAHRENHEIT 

            // Convert celTemp to fahTemp
            fahTemp = (kelTemp + ABS_ZERO_IN_CELSIUS) * 9.0/5 + 32;
                
            printf("%.1f Kelvin => %.1f Fahrenheit\n", kelTemp, fahTemp); 
        }
    }
    else
        printf("%.1f Kelvin is an invalid temperature! Try again!\n", kelTemp); 
	
    return 0;
}

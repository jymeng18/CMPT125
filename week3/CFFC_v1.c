/*
 * Filename: CFFC_v1.c - version 1
 *
 * Description: Ask the user for the conversion type: C -> F or F -> C
 *              Ask the user for a temperature.
 *              Convert this temperature to the other temperature 
 *              based on the selected conversion type.
 *              C -> F conversion: °F = (°C × 9/5) + 32
 *              F -> C conversion: °C = 5/9 × (°F - 32)
 *
 * Author: AL
 * Date: May 2025
 */

#include <stdio.h>

int main( void ) {

    const char CELSIUS = 'C';
    char choice = CELSIUS;
    float celTemp = 0.0;
    float fahTemp = 0.0;

    printf("To convert temperature from Celsius to Fahrenheit ... Enter F\n");
    printf("To convert temperature from Fahrenheit to Celsius ... Enter C\n");
    printf("Your choice: ");
    scanf("%c", &choice);

    if ( choice == CELSIUS ) { 

        // New section
        printf("Please, enter a temperature in Fahrenheit: ");
        scanf("%f", &fahTemp );

        // Convert fahTemp to celTemp
        celTemp =  5.0/9 * (fahTemp - 32);
            
        printf("%0.1f Fahrenheit => %0.1f Celsius\n", fahTemp, celTemp); 
    }
    else {  // Assume choice == Fahrenheit ('F')
	
        // We already implemented this section (CtoF_v2.c)
        printf("Please, enter a temperature in Celsius: ");
        scanf("%f", &celTemp );

        // Convert celTemp to fahTemp
        fahTemp = celTemp * 9.0/5 + 32;
            
        printf("%.1f Celsius degree => %.1f Fahrenheit.\n", celTemp, fahTemp); 
    }
  
    return 0;
}
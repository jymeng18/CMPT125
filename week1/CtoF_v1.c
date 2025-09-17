
/*
* FileName: CtoF_v1
*
* Description: Convert a celsius temperature to a fahrenheit temperature 
                Formula: *C x 9/5 + 32 = F

* Author: AL
*
* Date: May 2025
 */

#include <stdio.h>

int main( void ) 
{
  // Get a C temperature
  float celTemp = 2.0; // Celsius Temperature 
  float farTemp = 0.0; // Fahrenheit Temperature 

  // Convert it to fahrenheit 
  farTemp = celTemp * 9/5 + 32;

  //Can also be done this way
  //farTemp = 32 + (float) 9/5 * celTemp;


  // Print Result
  printf("Celsius %.1f ==> %.1f Fahrenheit\n", celTemp, farTemp); // %f is a format specifier

  return 0; 


}

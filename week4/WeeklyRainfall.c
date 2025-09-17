/*
 * Filename: WeeklyRainFall.c
 *
 * Description: Sum the daily rainfall for a week 
 *              and print the resulting total weekly rainfall.      
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

int main( void ) {
   
  const unsigned int DAYS_IN_WEEK = 7;
  float dailyRainFall = 0.0;    // User input
  float weeklyRainFall = 0.0;   // Running sum

  for ( unsigned int day = 1; day <= DAYS_IN_WEEK; day++ ) { // day = day + 1 OR day += 1

    // Prompt user and read daily rainfall from user
    printf( "Please, enter daily rainfall for day %d in cm: ", day );    
    
    // If valid user input ...
    if ( scanf("%f", &dailyRainFall ) == 1 ) {

      // Add daily rainfall to running sum
      weeklyRainFall += dailyRainFall;  // weeklyRainFall = weeklyRainFall + dailyRainFall;
    } 
    else {  // If invalid user input ...

      // Notify user
      printf( "Invalid input.\n" );
      break; // TO BE USED SPARINGLY!
    }
  }
  
  // Print the resulting total weekly rainfall.      
  printf( "Weekly rainfall is %0.2f cm\n", weeklyRainFall );

  return 0;
}

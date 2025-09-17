/*
 * printStarPatternRecursively.c
 * 
 * Class Description: Recursive C function that prints a pattern of stars 
 *                    on stdout (the computer monitor screen).
 *                    The pattern is a vertical triangle.
 *
 * Author: AL
 * Date: August 025
 */

#include <stdio.h>

void printStarPatternRecursively( unsigned int numOfStars, unsigned int maxOfStars ) {

  // Base case
  if ( numOfStars > maxOfStars ) return;
  
  // Do a little sprinkling of stars
  for ( unsigned int i = 1; i <= numOfStars; i++ ) printf( "*" );
  
  printf( "\n" );

  // Recursive case
  printStarPatternRecursively( numOfStars + 1, maxOfStars );

  // Do a bit more sprinkling of stars
  for ( unsigned int i = 1; i <= numOfStars; i++ ) printf( "*" );
 
  printf( "\n" );
  
  return;

}
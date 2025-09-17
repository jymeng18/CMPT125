/*
 * Filename: Identical_Arrays.c - version 2
 *
 * Description: Determines whether two arrays are identical or not.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

#define ARRAY_SIZE 5

int main( void ) {

    // Test case 1 - identical
    char arrayChar1[] = {'a','b','c','d','e','\0'};
    char arrayChar2[] = {'a','b','c','d','e','\0'};

    // Test case 2 - not identical
    // char arrayChar1[] = {'a','b','c','d','e','\0'};
    // char arrayChar2[] = {'a','b','c','d','f','\0'};

    int identical = 1;  // true

    // Determine whether two arrays are identical
    // Stop the loop when not identical- without "break"!
    for ( unsigned int index = 0; index < ARRAY_SIZE && identical == 1; index++ ) {
      if ( arrayChar1[index] != arrayChar2[index] ) {
          printf("These two arrays are not identical!\n");
          identical = 0;  // set to false
      }
    }
    if ( identical == 1) printf("These two arrays are identical!\n");
    return 0;
}
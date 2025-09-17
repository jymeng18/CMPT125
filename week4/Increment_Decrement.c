/*
 * Filename: Identical_Arrays.c - version 1
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
    int arrayInt1[] = {1,2,3,4,5};
    int arrayInt2[] = {1,2,3,4,5};

    // Test case 2 - not identical
    // int arrayInt1[] = {1,2,3,4,5};
    // int arrayInt2[] = {1,2,3,4,6};

    int identical = 1;  // true

// WAY 1 - using "break" <- NOT GREAT! 
// Any other way to make condition evaluate to false?
    // Determine whether two arrays are identical - Stop the loop when not identical 
    for ( unsigned int index = 0; index < ARRAY_SIZE; index++ ) {
      if ( arrayInt1[index] != arrayInt2[index] ) {
          printf("These two arrays are not identical!\n");
		  break;
      }
    }
    // When execution flow reaches this point, 
    // we have no idea whether arrays are identical or not,
    // So, we can't printf("These two arrays are identical!\n");
    
// WAY 2 - without using "break" <- GREAT! DO THIS INSTEAD!
    // Determine whether two arrays are identical - Stop the loop when not identical
    for ( unsigned int index = 0; index < ARRAY_SIZE && identical; index++ ) {
      if ( arrayInt1[index] != arrayInt2[index] ) {
          printf("These two arrays are not identical!\n");
          identical = 0;  // set to false
      }
    }
    // When execution flow reaches this point, 
    // we know whether arrays are identical or not 
    // by the value of "identical"
    if ( identical ) printf("These two arrays are identical!\n");
    return 0;
}
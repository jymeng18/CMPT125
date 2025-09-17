/*
 * Filename: Toying_with_Arrays.c
 *
 * Description: Toying with arrays.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

int main( void ) {
  const unsigned int ARRAY_SIZE = 5;
  int intArray[ARRAY_SIZE];
  int intArray2[] = {10,11,12,13,14};

  // Printing intArray - initialized?
  printf("\nPrinting intArray\n");
  for ( unsigned int index = 0; index < ARRAY_SIZE; index++) {
    printf("%d ", intArray[index]);  
  }

  // Initializing intArray
  printf("\n\nInitializing intArray\n");
  for ( unsigned int index = 0; index < ARRAY_SIZE; index++ ) {
    intArray[index] = index;
  }

  // Printing initialized intArray
  printf("\nPrinting intArray\n");
  for ( unsigned int index = 0; index < ARRAY_SIZE; index++ ) {
    printf("%d ", intArray[index]);
  }
 
  printf("\n\n");   
  return 0;
}

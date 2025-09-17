/*
 * Filename: pointerNotation.c
 *
 * Description: Lab 3 - Exercise 4
 *
 * Author: AL and modified by Jerry Meng
 * Date: June 2025
 */
 
 #include <stdio.h>
 
int main( void ) {
  const unsigned int ARRAY_SIZE = 5;
  int intArray[ARRAY_SIZE];
	
  // Printing intArray - initialized?
  printf("\nPrinting intArray\n");
  for ( unsigned int index = 0; index < ARRAY_SIZE; index++ ) {

    // Modified Code JM
    printf("%d ", *(intArray + index));
  }

  // Initializing intArray
  printf("\n\nInitializing intArray\n");
  for ( unsigned int index = 0; index < ARRAY_SIZE; index++ ) {

    // Modified Code JM
    *(intArray + index) = index;
  }

  // Printing initialized intArray
  printf("\nPrinting intArray\n");
  for ( unsigned int index = 0; index < ARRAY_SIZE; index++ ) {

    // Modified Code JM
    printf("%d ", *(intArray + index));
  }
 
  printf("\n\n");   
  return 0;
}
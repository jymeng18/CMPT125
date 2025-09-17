/*
 * Filename: Automatic_Arrays.c
 *
 * Description: Demonstrating stack frames when an array
 *              is declared automatically and manipulated.              
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

void printArray( int anArray[ ], unsigned int arraySize ) {

  for( unsigned int index = 0; index < arraySize; index++ ) {
    printf( "array[%d] = %d\n", index, anArray[index] );
  }
  return;
}

void initArray( int * anArray, unsigned int arraySize ) {

  for( unsigned int index = 0; index < arraySize; index++ ) {
    anArray[index] = index;
  }
  return;
}

int main( void ) { 

  const unsigned int ARRAY_SIZE = 5; 
  int intArray[ARRAY_SIZE];           // indices: 0,1,2,3,4

  // Printing intArray
  printf("Printing intArray before initializing it:\n");
  printArray( intArray, ARRAY_SIZE );

  // Initializing intArray
  printf("\n\nInitializing intArray\n");
  initArray( intArray, ARRAY_SIZE );

  // Printing intArray
  printf("Printing intArray after initializing it:\n");
  printArray( intArray, ARRAY_SIZE );
  
  return 0;
}

/*
 * Filename: Dynamic_Arrays.c
 *
 * Description: Demonstating dynamic memory allocation.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdlib.h>
#include <stdio.h>

int * getArray( unsigned int maxsize ) {

  // Dynamically allocate memory for array
  int * anArray = malloc( maxsize * sizeof(int) );
	
  // Check pointer validity 
  if ( anArray == NULL ) {
    perror( "allocating a maxsize * sizeof(int) array failed" );  // or printf(...)
    exit(1);
  }
	
  // Initialize the array
  for( unsigned int index = 0; index < maxsize; index++ )
    anArray[index] = index;

  return anArray;
}

void printArray( int anArray[ ], unsigned int arraySize ) {

  for ( unsigned int index = 0; index < arraySize; index++ ) 
    printf( "array[%d] = %d\n", index, anArray[index] );

  return;
}

int main( void ) { 

  const unsigned int SIZE = 5; 
  int * intArray;

  // Allocate intArray
  printf("Allocate and initialize intArray!\n");
  intArray = getArray( SIZE );

/*  or   
	// Allocate intArray
    printf("Allocate intArray before initializing it:\n");
    int * intArray = getArray( intArray, SIZE );
*/	
	
  // Printing intArray
  printf("Printing intArray:\n");
  printArray( intArray, SIZE );
	
  // Deallocate array
  free( intArray );
  
  // Avoid dangling pointer
  intArray = NULL;
    
  return 0;
}


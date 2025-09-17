/*
 * Filename: randomOfRandom.c
 *
 * Description: For you to discover what this program does.
 *
 * Author: 
 * Modification Date: June 2025
 */

#include <stdio.h>  // for printf()
#include <stdlib.h> // for rand()
#include <time.h>   // for time()

/* Reads size (an integer) from stdin and returns a pointer to an array
   of integers of length size, containing random values between 0 and
   size-1 inclusive. Sets *reportSize (which must not be NULL) to indicate
   the size of the array. */
int * get_random_number_of_random_numbers( unsigned int * reportSize ) {
  // User enters a number for the array size - this number (size-1) upperly 
  // bounds the values utilised to initialize the elements of this array 
  printf( "Enter the size of the array as an integer: " );
  
  unsigned int size = 0;
  if ( scanf( "%d", &size ) != 1 ) { // Always check I/O for errors
    perror( "Reading an integer (size) failed" );
    exit(1);
  }
  
  // Explicitly allocate space for an array of ints
  int * theArray = malloc( size * sizeof(int) );
  
  // Always check a system call for errors
  if ( theArray == NULL ) {
    perror( "Allocating a random-size array (malloc) failed" );
    exit(1);
  }
  
  // Fill the array with random numbers
  for ( unsigned int i = 0; i < size; i++ ) 
    theArray[i] = rand() % size;
  
  *reportSize = size;
  
  return theArray;
}	

int main( void ) {

  // Intialize the random number generator with the current time in seconds
  srand( time(0) );
  
  // I can't know in advance how large anArray will be
  unsigned int size = 0;			
  int * anArray = get_random_number_of_random_numbers( &size );			

  printf( "The size of the array is %u and the array contains:\n", size );
  printf( "[" );
  for ( unsigned int i = 0; i < size; i++ )
    printf( " %d", anArray[i] );

  printf( " ]\n" );
  
  // De-allocate the memory allocated by malloc
  free( anArray );
  anArray = NULL;

  return 0;
}	       

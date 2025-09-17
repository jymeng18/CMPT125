/*
 * Filename: get_name_dynamic.c
 *
 * Description: Function get_name() gets the 
 *              name of the user.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>   // for printf()
#include <stdlib.h>  // for malloc(), free(), exit()

char * get_name( int maxsize ) {

  // Get an array to hold the name of the user
  char * line = malloc( maxsize * sizeof(char) );
	
  // Check pointer validity 
  if ( line == NULL ) {
    perror( "allocating a maxsize * sizeof(char) array failed" );
    exit(1);
  }
	
	// Prompt the user for their name
  printf( "Please enter your name: " );
	
  // Reads at most maxsize-1 chars from stdin, 
  // up to first newline, EOF or error.
  // We ALWAYS check for I/O errors
  if ( fgets( line, maxsize, stdin ) == NULL ) {
    perror( "failed to read a name" );
    exit(1);
  }

  return line;
}	

int main( void ) {

  // Solution 2:
  // Should be enough space for a name
  const unsigned int SIZE = 1024;
  char * name = get_name( SIZE );

  // Echo user's name
  printf( "Your name is %s", name );

  // When we are done with "name", we release
  // (deallocate) its memory on the heap
  free( name );
  
  // Avoid dangling pointer
  name = NULL;

  return 0;
}	       

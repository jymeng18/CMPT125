/*
 * Filename: get_name_parent.c
 *
 * Description: Function get_name() gets the 
 *              name of the user.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h> 

void get_name( char line[], int maxlen ) {

  // Prompt the user for their name
  printf( "Please enter your name: " );

  // Reads at most maxlen-1 chars from stdin, 
  // up to first newline, EOF or error. 
  // We ALWAYS check for I/O errors.
  if( fgets( line, maxlen, stdin ) == NULL ) {
    perror( "failed to read a name" );
    line[0] = '\0';  // or exit(1);
  }
  
  return; 
}

int main( void ) {

  // Solution 1:
  // Should be enough space for a name
  const unsigned int SIZE = 1024;  // min 6 if input is "Anne\n\0"
  char name[SIZE];
  
  get_name( name, SIZE );

  // Echo user's name
  printf( "Your name is %s", name );

  return 0;
}     


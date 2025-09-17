/*
 * Filename: Testing_Scope.c
 *
 * Description: Testing how variable/constant scope works.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h>

int main( void ) {
  const int LIMIT = 10;
  int test = 99;

  for ( unsigned int step = 0; step < LIMIT; step++ ) {
    if ( step % 2 == 0 ) {
      short twice = step * 2;
      printf( "1: step %d is even, and twice = %hi ... and ", step, twice );
    }
    // Would the following C statement compile? If not, can you debug it?
    printf( "2: step %d is even, and twice = %hi ... and ", step, twice);
    printf( "test = %d.\n", test );
  }

  // Would the following C statement compile? If not, can you debug it?
  printf( "3: step %d is even, and twice = %hi ... and ", step, twice);
  printf( "LIMIT is %d and the last test = %d.\n", LIMIT, test );
  return 0;
}

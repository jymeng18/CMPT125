/*
* Filename: testDriver.c
*
* Desc: Test Cases for InRectangle.c 
*
* Name: Jerry Meng
*
* Date: June 20, 2025
*/


#include <stdio.h>
#include "InRectangle.h"

#define POINTS 2
#define CORNERS 4
 
int main( int argc, char* argv[] ) {

  // Define a rectangle from (1,1) to (2,2)
  float rect[CORNERS] = {1.0, 1.0, 2.0, 2.0 };
  
  // Test Case 1
  // Define a point that is inside the rectangle
  float p_in[POINTS] = { 1.5, 1.5 };

  printf( "Test Case 1\n" );
  printf( "\tTest Data: rectangle: (1.0, 1.0) and (2.0, 2.0), point: (1.5, 1.5)\n" );
  printf( "\tExpected Result: point is in the rectangle!\n" );

  if( InRectangle( p_in, rect ) == 0 ) {
    puts( "\nTest Case 1 - error: should return true for point (1.5, 1.5)." );
    return 1; // indicate error
  }
  else printf( "\tActual Result: point is in the rectangle!\n" );
 
  // Test Case 2
  // Define a point that is outside the rectangle
  float p2_in[POINTS] = {10.0, 9.0};

  printf("Test Case 2\n");
  printf("\tTest Data: rectangle: (1.0, 1.0) and (2.0, 2.0), point: (10.0, 9.0)\n");
  printf("\tExpected Result: point is not in the rectangle!\n");

  if( InRectangle( p2_in, rect ) == 1){
    puts( "\nTest Case 2 - error: should return false for point (10.0, 9.0).");
    return 1; // indicate error
  }
  else printf("\tActual Result: point is not in the rectangle!\n");
 
  // Test Case 3
  // Define a point that is on the edge of the rectangle
  float p3_in[POINTS] = {1.5, 1.0};

  printf("Test Case 3\n");
  printf("\tTest Data: rectangle: (1.0, 1.0) and (2.0, 2.0), point: (1.5, 1.0)\n");
  printf("\tExpected Result: point is in the rectangle!\n");

  if( InRectangle( p3_in, rect ) == 0){
    puts( "\nTest Case 3 - error: should return true for point (1.5, 1.0).");
    return 1; // indicate error
  }
  else printf("\tActual Result: point is in the rectangle!\n");
  
  // Test Case 4
  // Define a point outside but aligned with rectangle edges
  float p4_in[POINTS] = {1.5, 0.5};

  printf("Test Case 4\n");
  printf("\tTest Data: rectangle: (1.0, 1.0) and (2.0, 2.0), point: (1.5, 0.5)\n");
  printf("\tExpected Result: point is not in the rectangle!\n");

  if(InRectangle(p4_in, rect) == 1){
    puts("\nTest Case 4 - error: should return false for point (1.5, 0.5).");
    return 1; // indicate error
  }
  else printf("\tActual Result: point is not in the rectangle!\n");
  
  return 0; // all tests passed
}

/*
 * D103-D104
 * Filename: CodingQuiz1.c
 *
 * Description: Simple operations on raster images
 *
 * Completed by: Jerry Meng
 * Completion Date: July 2025
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  OPERATIONS ON A PIXEL
*/
           
/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
                   unsigned int cols, 
                   unsigned int rows,
                   unsigned int x,
                   unsigned int y )
{
  // Validate the parameters
  assert( array != NULL );
  assert( x < cols );
  assert( y < rows ); 
  return array[ y * cols + x ];
}

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour )
{
  // Validate the parameters
  assert( array != NULL ); 
  assert( x < cols );
  assert( y < rows );
  array[ y * cols + x ] = colour;
  return;
} 
						
/* ---------------------- Coding Quiz 1 ---------------------- */
/* Given a pixel located at coordinates (x,y) in the raster image array[], 
   print the colour of the pixel located directly to the right of this given pixel,
   in the raster image, on stdout. Your function must print this pixel colour
   as part of the following output statement:
   "The colour of the pixel to the right of the pixel located at coordinates (__,__) is __." 
   Make sure you fill in the three blanks when printing the above output statement.
   This output statement must be printed on its own line.
*/
void print_right_pixel( const uint8_t array[],
                        unsigned int cols, 
                        unsigned int rows,
                        unsigned int x,
                        unsigned int y )
{
  // Put your code here
  int index;
  int index_right;
  uint8_t right_pixel;

  // Obtain indexes
  index = y * cols + x;
  
  // Ensure we aren't at the bottom right corner(pixel to the right doesnt exist)
  if(index == rows - 1 && index == cols - 1){
    printf("There is nothing to the right!");
    return;
  }
  else{
    index_right = index + 1; // the right of the index is just incremented by 1 
  }

  // Obtain our right pixel
  right_pixel = array[index_right];

  // Display final results 
  printf("The colour of the pixel to the right of the pixel located at coordinates (%d, %d) is %d.\n", x, y, right_pixel);

  return;
} 				 		

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t * copy( const uint8_t array[], 
                unsigned int cols, 
                unsigned int rows )
{
  // Validate the parameter
  assert( array != NULL );

  uint8_t * copyPtr = malloc( cols * rows * sizeof(uint8_t) );
  if ( !copyPtr ) {
    perror( "Call to malloc failed\n" );
    exit(1);
  }
  memcpy( copyPtr, array, cols * rows * sizeof(uint8_t) );
  
  return copyPtr;
}

/* ---------------------- Quiz 2 ---------------------- */
/* Multiply every pixel by "scale_factor", in order to brighten or
   darken the image. Resulting values are rounded to the nearest
   integer (0.5 rounded up) and any resulting value over 255 is
   thresholded (i.e., set) to 255.
*/
void scale_brightness( uint8_t array[],
                       unsigned int cols,
                       unsigned int rows,
                       double scale_factor )
{
  // Put your code here
  for(int i = 0; i < rows * cols; i++){

      array[i] = array[i] * scale_factor;
      
      // If value > 255
      if(array[i] > 255){
        // Threshold at 255
        array[i] = 255;
      }
      else{

        // Round resulting pixels after scaling
        array[i] = round(array[i]);
      }
  }
  return; 
}
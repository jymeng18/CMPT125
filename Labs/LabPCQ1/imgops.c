/*
 * Filename: imgops.c
 *
 * Description: 10 simple operations on raster images
 *
 * Author: RV - 2014
 * Modified by: AL - 2025
 *
 * Completed by: Jerry Meng
 * Completion Date: June 29th, 2025
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
  // Parameter validation
  assert( x < cols );
  assert( y < rows );
	
  // Converting (x,y) -> index
  return array[x + y * cols];
}
	

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour ) 
{
  // Parameter validation
  assert( x < cols );
  assert( y < rows );
	
  // Converting (x,y) -> index
  array[x + y * cols] = colour; 
  return;
} 

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to zero 0 (black). */
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  for(int i = 0; i < rows * cols; i++){
    array[i] = 0;
  }
  return;
}

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
               unsigned int cols, 
               unsigned int rows )
{
  uint8_t * arrayCopied = malloc(cols * rows * sizeof(uint8_t));

  // Ensure memory is allocated
  if(arrayCopied != NULL){

    // Copy every value
    for(int i = 0; i < cols * rows; i++){
      arrayCopied[i] = array[i];
    }
    return arrayCopied;
  }
  else
    return NULL;
}

/* Return the darkest colour that appears in the image. */
uint8_t darkest( const uint8_t array[], 
                 unsigned int cols, 
                 unsigned int rows )
{
  uint8_t darkest_colour = array[0];

  for(int i = 0; i < cols * rows; i++){
    if(array[i] < darkest_colour){
      darkest_colour = array[i];
    }
  }

  return darkest_colour; 
}

/* Return the lightest colour that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	              unsigned int cols, 
	              unsigned int rows )
{
  uint8_t lightest_colour = array[0];

  for(int i = 0; i < rows * cols; i++){
    if(array[i] > lightest_colour){
      lightest_colour = array[i];
    }
  }
  return lightest_colour;
}

/* Replace every instance of pre_colour with post_colour. */
void replace_colour( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_colour,
                    uint8_t post_colour )
{
  for(int i = 0; i < cols * rows; i++){
    if(array[i] == pre_colour){

      // Replace pre_colour with post_colour
      array[i] = post_colour;
    }
  }
  return;
}

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows )
{
  // Put your code here
  int index;
  int mirror_index;
  uint8_t temp;

  for(int x = 0; x < rows; x++){
    for(int y = 0; y < cols / 2; y++){

      // Get left index
      index = x * cols + y;

      // Get mirrored index
      mirror_index = x * cols + (cols - 1 - y);

      // Swap pixels 
      temp = array[index];
      array[index] = array[mirror_index];
      array[mirror_index] = temp;
    }
  }
  return;
}


/* Find the coordinates (x,y) of the first pixel with a value that
   equals colour. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_colour( const uint8_t array[],              
                  unsigned int cols, 
                  unsigned int rows,
                  uint8_t colour,
                  unsigned int *x,
                  unsigned int *y )
{
  int index;

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){

      // Search left to right, top to bottom
      index = i * cols + j;
      if(array[index] == colour){

        // Obtain coordinates (x,y)
        *x = j;
        *y = i; 
        return 1;
      }
    }
  }
  return 0; // colour was not found in array 
}

/* Invert the image such that black becomes white and vice
   versa and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
             unsigned int cols, 
             unsigned int rows )
{
  for(int i = 0; i < cols * rows; i++){
    array[i] = 255 - array[i]; // invert
  }
  return;
}

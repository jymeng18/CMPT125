/*
 * Filename: testDriver.c
 *
 * Description: Test functions from imgops.c
 * 
 * Author: RV - 2014
 * Modified by: AL - 2025
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"


int main( int argc, char* argv[] ) {

  // Windowing system setup
  const unsigned int winwidth  = 500;
  const unsigned int winheight = 500;

  // Declaring variables modelling a raster image:
  unsigned int imgwidth  = winwidth / 4;
  unsigned int imgheight = winheight / 4 ;
  uint8_t * img = NULL;
  
// initialize the graphics system
  // ********************************************************
  // Get a first window
  draw_startup( (char*)"Window 1", winwidth, winheight );

  if( argc == 2 ) // if a filename was specified
  {
    uint32_t depth=0;
    int alpha=0;
    if( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 )
    {
      printf( "failed to load image %s\n", argv[1] );
      exit(1);
    }
  }
  else // no filename specified: create a blank image
  {
    // allocate an array for our image
    img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
    if( img == NULL )
    {
      printf( "failed to allocate memory for image.\n" );
      exit(1);
    }

    // set the whole array to zero (black)
    memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));
  }

  // Testing get_pixel(...)
  // printf("The width and height of image is: %d and %d.\n", imgwidth, imgheight);
  // // Test Case 1: bottom right corner (imgwidth-1,imgheight-1) looks very dark so colour ~0
  // printf("Test Case 1 - Testing get_pixel(...) with (%d,%d):\n", imgwidth-1,imgheight-1);
  // unsigned int theX = imgwidth-1;
  // unsigned int theY = imgheight-1; 
  // printf("The colour of the pixel at (%d,%d) is %d\n", theX, theY,  
  //         get_pixel(img, imgwidth, imgheight, theX, theY));

  // // Test Case 2: using coordinates outside of the array: (imgwidth*2,imgheight*2)
  // printf("Test Case 2 - Testing get_pixel(...) with (%d,%d):\n", imgwidth*2,imgheight*2);
  // theX = imgwidth*2;
  // theY = imgheight*2;
  // printf("The colour of the pixel at (%d,%d) is %d\n", theX, theY,  
  //         get_pixel(img, imgwidth, imgheight, theX, theY));

  // // Testing set_pixel(...)
  // // Test Case 3: set top left corner pixel (0,0) to black (0)
  // printf("Test Case 3 - Testing set_pixel(...) setting (0,0) to black (0):\n");
  // theX = 0;
  // theY = 0; 
  // set_pixel(img, imgwidth, imgheight, theX, theY, 0);

  // // Test Case 4: using coordinates outside of the array: (imgwidth*2,imgheight*2)
  // printf("Test Case 4 - Testing set_pixel(...) setting (%d,%d) to black (0):\n", imgwidth*2,imgheight*2);
  // theX = imgwidth*2;
  // theY = imgheight*2;
  // set_pixel(img, imgwidth, imgheight, theX, theY, 0);

  // Draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  printf( "Original image\n" );
  draw_image_grey( img, imgwidth, imgheight );
  
  // ********************************************************
  // Get more windows if needed by copying, pasting and modifying the above code
  // ********************************************************
  
  // ********************************************************
  
  // Finalize the graphics system, freeing its resources
  draw_shutdown();

  // Every malloc() should have a matching free()
  free(img);
   
  // Let's get in the habit of setting all freed pointers to NULL
  img = NULL;
  
  return 0;
}
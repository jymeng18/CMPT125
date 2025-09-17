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

  if( argc == 2 ) // if a filename was specified at the command line
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

  // Draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  printf( "Original image\n" );
  draw_image_grey( img, imgwidth, imgheight );

  // Test Case 2
  // printf(" Blacked Image\n");
  // zero(img, imgwidth, imgheight);
  // draw_image_grey( img, imgwidth, imgheight );

  // Test Case 3
  // printf(" Copied Image\n");
  // copy( img, imgwidth, imgheight);
  // draw_image_grey( img, imgwidth, imgheight);

  // Test Case 4
  //printf("Darkest Colour In IMG: %u\n", darkest( img, imgwidth, imgheight));

  // Test Case 5
  //printf("Lightest Colour in IMG: %u\n", lightest( img, imgwidth, imgheight ));

  // Test Case 6
  // printf("Replaced Colours IMG\n");
  // replace_colour(img, imgwidth, imgheight, 0, 255);
  // draw_image_grey(img, imgwidth, imgheight);

  // Test Case 7
  // printf("Flipped Horizontally IMG\n");
  // flip_horizontal(img, imgwidth, imgheight);
  // draw_image_grey(img, imgwidth, imgheight);

  // Test Case 8
  // unsigned int x_coord;
  // unsigned int y_coord;
  // int found = locate_colour(img, imgwidth, imgheight, 255, &x_coord, &y_coord);
  // printf("Returned: %d, (x,y) = (%d, %d)\n", found, x_coord, y_coord);

  // Test Case 9
  // printf("Invert IMG: \n");
  // invert(img, imgwidth, imgheight);
  // draw_image_grey(img, imgwidth, imgheight);

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
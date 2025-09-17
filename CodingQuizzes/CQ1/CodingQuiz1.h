/*
 * D103-D104
 * Filename: CodingQuiz1.h
 *
 * Description: Simple operations on raster images
 *
 * Completed by: <Put your name here>
 * Completion Date: July 2025
 */

/*-------------------------------------------------
  OPERATIONS ON A PIXEL 
*/
           
/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
                   unsigned int cols, 
                   unsigned int rows,
                   unsigned int x,
                   unsigned int y );

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour );
				
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
                        unsigned int y );	
				  
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
                unsigned int rows );

/* ---------------------- Coding Quiz 1 ---------------------- */
/* Multiply every pixel by "scale_factor", in order to brighten or
   darken the image. Resulting values are rounded to the nearest
   integer (0.5 rounded up) and any resulting value over 255 is
   thresholded (i.e., set) to 255.
*/
void scale_brightness( uint8_t array[],
                       unsigned int cols,
                       unsigned int rows,
                       double scale_factor );

/* 
 * Filename: Demo_File_IO.c
 *
 * Description: Demo how to open a file, write to a file and close a file.
 *
 * Author: AL
 * Date: July 2025
 */

#include <stdlib.h> // for malloc() and for rand()
#include <time.h>   // for time()
#include <string.h> // for strlen()
#include <stdio.h> 
#include <assert.h>

#include "dataStructure.h"

/* Binary file */
/* The idea is to write "size", "elementCount" and all elements 
   in "data" to a binary file. */

intArrayResult_t intArray_write_to_bin( intArray_t * ia, const char * filename ) {
  
  // Parameter Validation
  assert( ia != NULL ); 
  assert( filename != NULL );   

  // Open file for writing
  FILE * theFile = fopen( filename, "w" ); 
  if ( theFile == NULL ) return INTARR_ERROR;

  // First we write the size of our data structure
  if ( fwrite( &ia->size, sizeof(unsigned int), 1, theFile ) != 1 ) {
    fclose( theFile );  // Always match fopen(...) with a fclose(...)
    return INTARR_ERROR;
  }
  
  // Then we write the number of elements in our data structure
  if ( fwrite( &ia->elementCount, sizeof(unsigned int), 1, theFile ) != 1 ) {
    fclose( theFile );  // Always match fopen(...) with a fclose(...)
    return INTARR_ERROR;
  }
 
  // Finally we write the elements - if there are any to write (if data structure not empty)
  if ( ia->elementCount > 0 ) {
    if ( fwrite( ia->data, sizeof(int), ia->elementCount, theFile ) != ia->elementCount ){
      fclose( theFile );  // Always match fopen(...) with a fclose(...)
      return INTARR_ERROR;
    }
  }

  // Always match fopen(...) with a fclose(...)
  fclose( theFile );
  return INTARR_OK;
}

intArray_t * intArray_load_from_bin( const char * filename ) {

  // Parameter Validation
  assert( filename != NULL );

  // Open file for reading
  FILE * theFile = fopen( filename, "r" ); 
  if ( theFile == NULL ) return NULL;
    
  // First we read the size of our data structure
  unsigned int size;
  if ( fread( &size, sizeof(size), 1, theFile ) != 1 ) {
    fclose( theFile );  // Always match fopen(...) with a fclose(...)
    return NULL;
  }
  
  // Then we read the number of elements
  unsigned int elementCount;
  if ( fread( &elementCount, sizeof(elementCount), 1, theFile ) != 1 ) {
    fclose( theFile );  // Always match fopen(...) with a fclose(...)
    return NULL;
  }
  
  // Then we create our data structure with the size we read from the file
  intArray_t * ia = intArray_create(size);
  if ( ia == NULL ) {
    fclose( theFile );
    return NULL;  // Always match fopen(...) with a fclose(...)
  }   

  // Finally we read the elements - if there are any to read (if data structure not empty)
  if ( elementCount > 0 ) {
    if ( fread( ia->data, sizeof(int), elementCount, theFile ) != elementCount ) {
      fclose( theFile );  // Always match fopen(...) with a fclose(...)
      return NULL; 
    }    
  }
  
  // Update data structure with actual elementCount;
  ia->elementCount = elementCount;
  
  // Always match fopen(...) with a fclose(...)
  fclose( theFile );
  return ia;
}
 

// Test Driver 
int main( int argc, char * argv[] ) {

  const unsigned int SIZE = 10;
  
  printf("Creating data structure\n"); 
  intArray_t * test_ia = intArray_create( SIZE );
  if ( test_ia ==  NULL ) {
    printf("test_ia ==  NULL\n");
    return INTARR_ERROR;
  } 
  
  // Put random data in the array
  printf("Populating data structure with random data\n");
  // Intialize the random number generator with the current time in seconds
  srand( time(NULL) );

  // Fill data structure with random numbers
  for ( unsigned int i = 0; i < test_ia->size; i++ ) {
    intArray_append( test_ia, ( rand() % test_ia->size ) ); 
  }

  printf("Printing test_ia\n"); 
  intArray_print( test_ia );

  // Write data structure to a binary file  
  printf("Storing data structure into the binary file %s\n", argv[1] ); 
  if ( intArray_write_to_bin( test_ia, argv[1] ) != 0 )
    puts("Storing test_ia into the binary file did not work!"); 

  printf("Loading bin_test_ia from the binary file %s\n", argv[1] );
  intArray_t * bin_test_ia = intArray_load_from_bin( argv[1] );
  if ( bin_test_ia == NULL )
    puts("Storing test_ia into the binary file did not work!");
  else { 
    printf("Printing the data structure read from the file\n"); 
    intArray_print( bin_test_ia );

    printf("Destroy the data structure read from the file\n");
    intArray_destroy( bin_test_ia );
  }

  printf("Printing test_ia\n"); 
  intArray_print( test_ia );
  
  // Testing intArray_remove(...)
  printf("Removing first element of test_ia\n"); 
  intArray_remove( test_ia, 0 );
  
  printf("Printing test_ia\n"); 
  intArray_print( test_ia );

  printf("Destroy data structure\n");  
  intArray_destroy( test_ia );
  
  return INTARR_OK;
}

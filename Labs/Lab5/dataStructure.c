/* 
 * dataStructure.c
 *
 * Provides a bound-checked data structure made of an array of integers
 * in which duplicated elements are allowed.
 *
 * The interface of this data structure includes several utility 
 * functions that operate on this array of integers as well as 
 * file i/o functions: saving into and loading from json files. 
 * 
 * Do not change the dataStructure.h file.
 *
 * Author: RV + AL Modified by Jerry Meng
 * Modified Date: July 2025 
*/

#include <stdlib.h> // for malloc()
#include <stdio.h>  // for file i/o calls
#include <string.h> // for strlen()
 
#include "dataStructure.h"


/* 
 * Description: Creates a new intArray_t data structure 
 *              with initial array size "size". If successful
 *              (i.e. size is > 0 and memory allocation succeeds), 
 *              returns a pointer to a newly-allocated intArray_t. 
 *              If unsuccessful, returns a NULL pointer.
 * Time Efficiency: O(1)
 */
intArray_t * intArray_create( unsigned int size ) {

  // Validate the parameter "size"
  if ( size == 0 ) return NULL;
  
  // Allocate memory on the heap for intArray_t struct 
  intArray_t * ia = malloc( sizeof( intArray_t ) );
  if ( ia != NULL ) {

    // Set its field "size"
    ia->size = size;

    // Allocate memory on the heap for array
    ia->data = malloc( size * sizeof(int) );
    if ( ia->data == NULL ) {
      free( ia );
      ia = NULL;
    }
	  else
	  // Set its field "elementCount" to zero -> empty array
	  ia->elementCount = 0;
  }
  return ia;
}

/* 
 * Description: Frees all memory allocated for "ia". 
 *              If the pointer "ia->data" is NULL, it does not attempt 
 *              to free it. Returns INTARR_OK.
 *              If the pointer "ia" is NULL, it returns INTARR_BADPARAM. 
 * Time Efficiency: O(1)
 */ 
intArrayResult_t intArray_destroy( intArray_t * ia ) {

  intArrayResult_t result = INTARR_BADPARAM;
  
  // If heap memory has been allocated for intArray_t struct ...
  if ( ia != NULL ) {
  
    // If heap memory has been allocated for array ...
    if ( ia->data != NULL ) {
      // ... then free it
      free( ia->data );  // check returned value from free(...)
      ia->data = NULL;
    }
  
    // ... then free it.
    free( ia ); // check returned value from free(...)
    ia = NULL;
	result = INTARR_OK;
  }

  return result;
}

/* Description: Appends "newElement" and returns INTARR_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns INTARR_ERROR.
 *              If "ia" is NULL, returns INTARR_BADPARAM. 
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_append( intArray_t * ia, int newElement ) {
	
  // Check that ia, and our dynamically allocated array is not NULL
  if( ia == NULL || ia->data == NULL ){
    return INTARR_BADPARAM;
  }
  
  // Check that our newElement can be appended
  if( (ia->elementCount) >= (ia->size) ){
    return INTARR_ERROR;
  }

  // Passed all tests, we can append
  ia->data[ia->elementCount] = newElement;
  ia->elementCount++;
	
  return INTARR_OK;
}					

/* Description: Removes the element at "indexToBeRemoved" in the data structure
 *              and returns INTARR_OK. If the data structure was initially sorted,
 *              it does not remain sorted after removing the element at "indexToBeRemoved".
 *              If "ia" is NULL or "indexToBeRemoved" is out of bounds, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 *              If "ia->elementCount" is 0, returns INTARR_BADPARAM. 
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_remove( intArray_t * ia, unsigned int indexToBeRemoved ) {

  // Check ia and indexToBeRemoved are valid
  if(ia == NULL || ia->elementCount <= indexToBeRemoved){
    return INTARR_BADPARAM;
  }

  // Check that our allocated memory was valid
  if(ia->data == NULL){
    return INTARR_BADPARAM;
  }

  if(ia->elementCount == 0){
    return INTARR_BADPARAM;
  }

  // All test cases passed, now remove element at indexToBeRemoved
  ia->data[indexToBeRemoved] = ia->data[ia->elementCount - 1]; // Move last element over to removed element
  ia->elementCount--;

  return INTARR_OK;
}

/* Description: Modifies (overwrites) the element at "index" with "newElement"
 *              and returns INTARR_OK. If "ia" is NULL or "index" is out of bounds,
 *              returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time Efficiency: O(1)
 */
intArrayResult_t intArray_modify( intArray_t * ia, int newElement, unsigned int index ) {
	
  // Verify parameters
  if(ia == NULL || index >= ia->elementCount){
    return INTARR_BADPARAM;
  }

  if(ia->data == NULL){
    return INTARR_BADPARAM;
  }

  // All parameter tests passed, proceed with modifying
  ia->data[index] = newElement;

  return INTARR_OK;
}
							
/* Description: Finds the first occurrence of "targetElement" in the data structure,
 *              sets "*index" to its index and returns INTARR_OK. If "targetElement" 
 *              does not occur in the data structure, leaves "*index" unmodified 
 *              and returns INTARR_NOTFOUND. If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(n)
 */
intArrayResult_t intArray_find( intArray_t * ia, int targetElement, unsigned int * index ) {
  
  // Verify Parameters

  if(ia == NULL){
    return INTARR_BADPARAM;
  }

  if(ia->data == NULL){
    return INTARR_BADPARAM;
  }

  if(index == NULL){
    return INTARR_BADPARAM;
  }

  // Search through array for targetElement
  for(unsigned int i = 0; i < ia->elementCount; i++){
    if(ia->data[i] == targetElement){
      *index = i;
      return INTARR_OK;
    }
  }

  // targetElement was not found
  return INTARR_NOTFOUND;
}

/* Description: Sorts the data structure by value in ascending sort order 
 *              (smallest to largest), such that data[i] < data[i+1] for all valid i, 
 *              then returns INTARR_OK. If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 *              Works in-place: content of "ia" is sorted on return. 
 *              Sorts the array using the Bubble Sort algorithm.
 * Time efficiency: O(n^2)
 * Space efficiency: O(1) - Bubble Sort is an "in-place" algorithm.
 */
intArrayResult_t intArray_sort( intArray_t * ia ) {
  
  // Parameter Validation
  if(ia == NULL){
    return INTARR_BADPARAM;
  }

  // Implement Bubble Sort
  for(unsigned int i = 0; i < ia->elementCount - 1; i++){
    for(unsigned int j = 0; j < ia->elementCount - 1 - i; j++){

      // Compare 1st and 2nd Element
      if(ia->data[j] > ia->data[j+1]){

        // Swap them
        int temp = ia->data[j];
        ia->data[j] = ia->data[j+1];
        ia->data[j+1] = temp;
      }
    }
  }
  return INTARR_OK;
}
							
/* Description: Returns a copy of "ia", allocating new storage 
 *              for this copy data (we call this a "deep copy"). 
 *              If unsuccessful (i.e. memory allocation for the copy fails, 
 *              or "ia" is NULL), returns a NULL pointer. 
 *              If "ia->data" is NULL, returns a NULL pointer. 
 */
intArray_t * intArray_copy( const intArray_t * ia ) {

  // Validate Parameters
  if(ia == NULL || ia->data == NULL){
    return NULL;
  }

  intArray_t * copy_ia = intArray_create(ia->size);

  // Ensure memory was allocated correctly
  if(copy_ia == NULL){
    return NULL;
  }

  // size is already copied over, now copy over elementCount
  copy_ia->elementCount = ia->elementCount;

  // Copy over remaining data
  memcpy(copy_ia->data, ia->data, ia->size * sizeof(int));
  return copy_ia;
}

/* Description: Prints the content of the struct to which "ia" points
 *              using the following format (if "ia" was pointing to 
 *              a struct of data type intArray_t containing an array of
 *              size 10 with 6 elements: 8, -45, 27, 0, -22 and 13):
 *              Printing intArray_t of size 10 with 6 elements
 *                  array: 8 -45 27 0 -22 13 (end)
 *              Note that the string "array: " is printed with an indentation
 *              of one tab. Then, returns INTARR_OK. 
 *              If "ia" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 * Time Efficiency: O(n)
 */
intArrayResult_t intArray_print( intArray_t * ia ) {

  // Parameter Validation
  if(ia == NULL || ia->data == NULL){
    return INTARR_BADPARAM;
  }
	
  // Print contents of array
  printf("Printing intArray_t of size %d with %d elements\n    array: ", ia->size, ia->elementCount);
  for(unsigned int i = 0; i < ia->elementCount; i++){
    printf("%d ", ia->data[i]);
  }
  printf("(end)\n");
  
  return INTARR_OK;  // You are free to modify this return statement.
}


/* Description: If the array is not empty, writes (saves) "ia->elementCount"
 *              then the entire array "ia->data" into a file called by the 
 *              value of the parameter "filename" in a JSON text file format 
 *              (explained below) which can be loaded by the function 
 *              intArray_load_from_json(...). Returns INTARR_OK on success.
 *              Returns INTARR_ERROR on failure, for example, when attempting 
 *              to write (save) an empty array in the output file.
 *              If "ia" or "filename" is NULL, returns INTARR_BADPARAM.
 *              If "ia->data" is NULL, returns INTARR_BADPARAM.
 *
 * Example: The following lines are a valid JSON file content 
 *          produced by first saving "elemenCount" (3), then
 *          each of the 3 elements contained in the array
 *          (100, 200, 300) into a file:
 * [ 
 *  3,
 *  100, 
 *  200, 
 *  300 
 * ]
 * 
 * Example: Below is another valid JSON format, which can also be used
 *          to save the same data described above: 
 * 
 * [ 3, 100, 200, 300 ]
 * 
 * Note: Whatever format you decide to use, make sure your function
 *       intArray_load_from_json(...) can read it. 
 */
intArrayResult_t intArray_write_to_json( intArray_t * ia, const char * filename ) {

  // Validate parameters
  if(ia == NULL || filename == NULL){
    return INTARR_BADPARAM;
  }
  if(ia->data == NULL){
    return INTARR_BADPARAM;
  }

  if(ia->elementCount == 0){
    return INTARR_ERROR;
  }

  // Write to Json file
  FILE * theFile = fopen(filename, "w");
  if(theFile == NULL){
    return INTARR_ERROR;
  }

  // Write in file json format
  fprintf(theFile, "[ %u", ia->elementCount);

  // Write each element
  for(unsigned int i = 0; i < ia->elementCount; i++){
    fprintf(theFile, ", %d", ia->data[i]); // this will skip the very first element
  }
  fprintf(theFile, " ]\n");
  fclose(theFile);
  
  return INTARR_OK;
}

/* Description: Loads a new intArray_t data structure from the file called 
 *              by the value of the parameter "filename", that was previously 
 *              saved using intArray_write_to_json(...). Note that the file 
 *              cannot contain an intArray_t data structure with an empty array.
 *              Returns a pointer to a newly allocated data structure on success 
 *              or NULL on failure. 
 *              If "filename" is NULL, returns NULL (not INTARR_BADPARAM).
 */
intArray_t * intArray_load_from_json( const char * filename ) {

  // Parameter Validation
  if(filename == NULL){
    return NULL;
  }

  FILE * theFile = fopen(filename, "r"); // want to read file
  if(theFile == NULL){
    return NULL;
  }

  // Check the startig char '['
  char bracket;
  if(fscanf(theFile, " %c", &bracket) != 1 || bracket != '['){
    fclose(theFile);
    return NULL;
  }

  // Obtain # of elements(This will obtain the very first value of the array, 
  // because it holds the # of elements in that array
  unsigned int counter;
  if(fscanf(theFile, " %u", &counter) != 1){
    fclose(theFile);
    return NULL;
  }

  // Ensure it is not an empty array(unlikely this will execute)
  if(counter == 0){
    fclose(theFile);
    return NULL;
  }

  // Create newly allocated array to return
  intArray_t * newArray = intArray_create(counter);
  if(newArray == NULL){
    fclose(theFile);
    return NULL;
  }

  // Load data into newly allocated array
   for(unsigned int i = 0; i < counter; i++){
      if(fscanf(theFile, " ,%d", &newArray->data[i]) != 1){
        fclose(theFile);
        return NULL;
      }
   }

   // Check the final bracket ']'
   if(fscanf(theFile, " %c", &bracket) != 1){
    fclose(theFile);
    return NULL;
   }

  newArray->elementCount = counter;

  fclose(theFile);
  return newArray;
}

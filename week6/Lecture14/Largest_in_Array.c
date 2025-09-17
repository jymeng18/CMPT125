/*
 * Filename: Largest_in_Array.c
 *
 * Description: Functions to find largest
 *              and smallest element in array.
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h> // for printf() and scanf()

// Description: Returns the largest element in array
//              using array notation.
int largest_arr( int arr[], unsigned int len ) {

    int largest = arr[0];
	for ( unsigned int i = 1; i < len; i++ )
    	if( arr[i] > largest ) largest = arr[i];

    return largest;
}

// Description: Returns the largest element in array
//              using pointer notation.
int largest_ptr( int * arr, unsigned int len ) {

    int largest = *arr; // Points at first element
	arr++;

	for ( unsigned int i = 1; i < len; i++ ){
    	if( *arr > largest ) largest = *arr;
    	arr++;
	}

    return largest;
}

// Description: Returns the largest element in array
//              using pointer notation.
int largest_ptr_2( int * arr, unsigned int len ) {

    int largest = *arr; // First element of array arr

	for ( unsigned int i = 1; i < len; i++ ){
    	if( *(arr + i) > largest ) largest = *(arr + i);
	}

    return largest;
}

int main( void ) {

	const unsigned int SIZE = 10;

	// Test Case 1:
    int arr[SIZE] = { 3, 6, 9, 2, 0, 8, 4, 8, 1, 5 };

  // Echo Test Case 1 - test data to stdout
    for ( unsigned int i = 0; i < SIZE; i++ ) {
    	printf( "arr[%u] = %d, ", i, arr[i] );
    }

	printf("\nLargest is\n");
	printf("\tlargest_arr: %d\n", largest_arr( arr, SIZE ));
	printf("\tlargest_ptr: %d\n", largest_ptr( arr, SIZE ));
	printf("\tlargest_ptr_2: %d\n", largest_ptr_2( arr, SIZE ));

    return 0;
}


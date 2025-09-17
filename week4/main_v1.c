/*
 * Filename: main_v1_2.c
 *
 * Description: Create a largest functions and a smallest function.
 *              largest returns the larger of its two parameters
 *              smallest returns the smaller of its two parameters
 *
 * Author: AL
 * Date: June 2025
 */

#include <stdio.h> // for printf() and scanf()

int largest( int int1, int int2 );
int smallest( int int1, int int2 );

int main( void )
{
    int num1 = 0;
    int num2 = 0;

    printf("Please, enter two integers: ");
    if ( scanf("%d %d", &num1, &num2 ) == 2) {
        printf( "Largest of %d and %d is %d\n", num1, num2, largest( num1, num2 ));
        printf( "Smallest of %d and %d is %d\n", num1, num2, smallest( num1, num2 ));
    }

    return 0;
}

// Description: Returns the larger of its two parameters
int largest( int int1, int int2 ) {

    int larger = int2;

    if ( int1 > int2 ) larger = int1;

    return larger;
}

// Description: Returns the smaller of its two parameters
int smallest( int int1, int int2 ) {

    int smaller = int2;

    if ( int1 < int2 ) smaller = int1;

    return smaller;
}
/*
* Filename: bits
*
* Description: Displays the memory size (in bits) of ten(10) numerical 
               data types
*
* Author: Jerry Meng
*
* Date: May 22nd, 2025
*/

#include <stdio.h>

int main(void)
{   
    // Obtain and display all our values using sizeof() and printf
    printf("unsigned char is stored in: %lu bits\n", sizeof(unsigned char) * 8);
    printf("signed char is stored in: %lu bits\n", sizeof(signed char) * 8);
    printf("unsigned short is stored in: %lu bits\n", sizeof(unsigned short) * 8);
    printf("signed short is stored in: %lu bits\n", sizeof(signed short) * 8);
    printf("unsigned int is stored in %lu bits\n", sizeof(unsigned int) * 8);
    printf("signed int is stored in %lu bits\n", sizeof(signed int) * 8);
    printf("float is stored in %lu bits\n", sizeof(float) * 8);
    printf("double is stored in %lu bits\n", sizeof(float) * 8);
    printf("unsigned long is stored in %lu bits\n", sizeof(unsigned long) * 8);
    printf("signed long is stored in %lu bits\n", sizeof(signed long) * 8);
    
    // Ensure program runs correctly
    return 0;

}




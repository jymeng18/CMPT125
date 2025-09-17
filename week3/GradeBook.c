/*
 * Filename: GradeBook.c
 *
 * Description: Grade book application: given a grade, prints the corresponding letter grade.
 *
 * Author: AL
 * Date: May 2025
 */

#include <stdio.h>

int main( void )
{
    const int MINGRADE = 0;
    const int MAXGRADE = 100;
    int grade = 0;

    printf("Please, enter a grade from %d to %d: ", MINGRADE, MAXGRADE);
    scanf("%d", &grade );

    if ( grade < 0 || grade > 100 )
        printf("%d is an invalid grade. Range of valid grades is [%d .. %d]. Please, try again!\n", grade, MINGRADE, MAXGRADE); 
    else
        if ( grade >= 90 )
            printf("%d => A\n", grade);
        else 
            if ( grade >= 80 )
                printf("%d => B\n", grade);
            else 
                if ( grade >= 70 )
                    printf("%d => C\n", grade);
                else 
                    if ( grade >= 60 )
                        printf("%d => D\n", grade);
                    else
                        if ( grade >= 50 )
                            printf("%d => E\n", grade);
                        else
                            printf("%d => F\n", grade);

    return 0;
}
/*
 * Filename: GradeBook_while.c
 *
 * Description: Grade book application: given a grade, 
 *              prints the corresponding letter grade.
 *
 * Author: AL
 * Date: May 2025
 */

#include <stdio.h>

int main( void ) {
	
  const int MIN_GRADE = 0;
  const int MAX_GRADE = 100;
  int grade = 0;
  int result = 0;

  // prompt user for input
  printf("Please, enter a grade from %d to %d: ", MIN_GRADE, MAX_GRADE);   
  
  // read user input
  while ( ( result = scanf("%d", &grade ) ) == 1 ) {

    // validate user input
    if ( grade < MIN_GRADE || grade > MAX_GRADE )
      printf("%d is an invalid grade. Range of valid grades is [%d .. %d]. Please, try again!\n", 
              grade, MIN_GRADE, MAX_GRADE); 
    else
      // convert grade to letter grade
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
			
    printf("Please, enter a grade from %d to %d: ", MIN_GRADE, MAX_GRADE); 
  }

  printf("\nBye!\n");
  return 0;
}
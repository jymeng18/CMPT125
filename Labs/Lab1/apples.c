/*
* Filename: apples
*
* Description: Predicts how many whole bags of apples can be produced 
  given the number of apples available

* Author: Jerry Meng
*
* Date: May 24, 2025
*/

#include <stdio.h>

int main(void)
{

    int total_apples;
    int apples_per_bag; 

    // Prompt user to enter number of apples available, and number of apples each bag can hold
    printf("Please, enter the number of apples available and the number of apples each bag holds: ");

    // Ensure user enters two integer inputs
    while(scanf("%d %d", &total_apples, &apples_per_bag) == 2)
        {

        // Calculate number of full bags and leftover apples
        int full_bags = total_apples / apples_per_bag;
        int apples_leftover = total_apples % apples_per_bag;
    
        // Display the user input and results
        printf("Number of apples available => %d, number of apples each bag holds => %d.\n", 
                total_apples, apples_per_bag);
        printf("Number of bags produced => %d, number of apples left over => %d.\n", 
                full_bags, apples_leftover);

        // At end of loop, ask user to enter inputs again
        printf("Please, enter the number of apples available and the number of apples each bag holds: ");

        }

        // When reached EOF, terminate program
        printf("\nDone.\n");
        return 0;
}


    



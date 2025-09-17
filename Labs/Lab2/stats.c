/*
* Filename: stats.c
*
* Description: 

* Author: Jerry Meng
*
* Date: May 29, 2025
*/

#include <stdio.h>

int main(void)
{

    float userValue = 0;
    float minValue = 0;
    float maxValue = 0;
    float meanValue = 0;
    int loopCount = 0;

    // Prompt for user inputs until user hits EOF
    printf("Please enter a number between -100000.00  and 100000.00: ");

    while(scanf("%f", &userValue) == 1)
    {
    
        // Ensure that user entered a value within the range
        if (userValue < -100000 || userValue > 100000){
            printf("%.2f is invalid!\n", userValue);
        }

        else{

            // Add user value to meanValue
            meanValue += userValue;

            // Count the # of times we have looped
            loopCount += 1;
        
            // Check to see if userValue is greater then maxValue
            if(userValue > maxValue){   
                maxValue = userValue;    
            }
            else if(userValue < minValue){
                minValue = userValue;
            }
        }
        
        printf("Please enter a number between -100000.00  and 100000.00: ");
    }

    if(loopCount != 0){
        // After uses hits Ctrl+d, display results
        printf("Min: %.2f, max: %.2f, mean: %.2f\n", minValue, maxValue, meanValue/loopCount);
    }
    else{
        printf("\nUser entered nothing!\n");
    }

    return 0;
}

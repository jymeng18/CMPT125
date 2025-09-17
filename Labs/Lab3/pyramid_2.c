/*
* Filename: pyramid_2c
*
* Description: displays the "side" of a pyramid
*
* Author: Jerry Meng
*
* Date: June 6th, 2025
*/

#include <stdio.h>
#include <math.h>

int main(void){

    int width, breath, height;
    int left, right;

    // Get user input
    printf("Please, enter 3 integers between 1 and 50 (incl.): ");
    scanf("%d %d %d", &width, &breath, &height);
    
    // Validate width
    if (width < 1 || width > 50) {
        printf("Invalid input width (%d)!\n", width);
        return 1;
    }
    
    // Validate breath
    if (breath < 1 || breath > 50) {
        printf("Invalid input breath (%d)!\n", breath);
        return 1;
    }
    
    // Validate height
    if (height < 1 || height > 50) {
        printf("Invalid input height (%d)!\n", height);
        return 1;
    }
    
    // Display side view of triangle

    // Rows(height)
    for(int j = height-1; j>=0; j--){
        left = floor(j * (width/(2.0*height)));
        right = ceil((width-1) - j * (width/(2.0*height)));

        // Width
        for(int x = 0; x<width; x++){

            if(x == left || x == right){
                printf("#");
            }
            else if(x > left && x < right && j != 0){
                printf(".");
            }
            else if(j == 0){
                printf("#");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    return 0;
}
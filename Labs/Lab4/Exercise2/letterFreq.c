/*
* Filename: letterFreq.c
*
* Desc: 
*
* Name: Jerry Meng
*
* Date: June 19, 2025
*/

#define SIZE 26
#include <stdio.h>

int main(void){

    float freq = 0.0;
    char letter;
    int count = 0;
    int current_character;
    int frequency_count[SIZE] = {0};

    while((current_character = getchar()) != EOF){

        // Check each character for letters
        if((current_character >= 'a' && current_character <= 'z') || 
        (current_character >= 'A' && current_character <= 'Z')){

            if(current_character >= 'A' && current_character <= 'Z'){

                // Change all letter occurences into lower
                current_character += 32;
            }

            // Count how many letters were read
            count += 1;

            // Store into array
            frequency_count[current_character - 'a']++;
        }
    }

    // After EOF, display results
    for(int i = 0; i < SIZE; i++){

        // First check that it occured (!= 0)
        if(frequency_count[i] != 0){
            
            letter = (char)i + 97;
            freq = frequency_count[i] / (float)count;
        
            printf( "%c %.4f\n", letter, freq);
        }
    }

    return 0;
}
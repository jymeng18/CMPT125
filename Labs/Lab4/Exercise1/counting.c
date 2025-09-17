/*
* Filename: counting.c
*
* Desc: counts the number of characters, words, and lines
*        read from stdin until EOF is reached
*
* Name: Jerry Meng
*
* Date: June 19, 2025
*/

#include <stdio.h>

int is_word(int current_char_value){

    // Handle upper and lower case situations

    // First Case: read char is the start, end, or middle of a word
    if(current_char_value >= 'a' && current_char_value <= 'z'){
        return 1;
    }
    if(current_char_value >= 'A' && current_char_value <= 'Z'){
        return 1;
    }

    // Second Case: read char is an apostrophe(39)
    if(current_char_value == 39){
        return 1;
    }

    // If program reaches here, read char was not a word
    return 0; 
}

int main(void){
    
    unsigned long charCount = 0, wordCount = 0, lineCount = 0; 
    int current_character; 
    int is_in_word = 0; // To check if a previous character was a "non-word"
   
    // Note: The return type of getchar() is int. Returns the ASCII value of the character as an int
    while((current_character = getchar()) != EOF){
        
        // To reach here, implies that there must be a char
        charCount++;

        // Count new line chars
        if(current_character == '\n'){
            lineCount++;
        }

        // Count words
        if((is_word(current_character)) == 1){

            // Previous character must not be a word
            if(is_in_word == 0){
                wordCount++;
                is_in_word = 1;
            }    
        }
        else
           is_in_word = 0; 
    }

    // Display results
    printf("%lu %lu %lu\n", charCount, wordCount, lineCount);

    return 0; 
}
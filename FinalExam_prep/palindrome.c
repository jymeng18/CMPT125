/*
 * palindromeChecker.c
 * 
 * Description: C function that determines when a string is a palindrome or not.
 *              A palindrome is a word that reads the same in both directions, right-to-left and left-to-right.
 *              Here are some examples: nun, madam, racecar, civic, deified, level, ...
 *              Don’t forget about our Good Programming Style (GPS).
 *              Note that words of length 1 are palindromes.
 *
 * Author: AL
 * Date: August 2025
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

int palindromeChecker( const char * aWord ) {

  unsigned int len = strlen( aWord );
  unsigned int middle = floor( len / 2 );

  // To check whether a word is a palindrome, I traverse half the
  // word, making sure that its matching pairs of characters are equal.
  // Matching pairs of characters: aWord[0] and aWord[len-1], aWord[1] and aWord[len-2], etc.   
  for ( unsigned int i = 0; i < middle; i++ ) {

    // As soon as I detect that "aWord" is not a palindrome
    // matching pairs of characters are not equal ...
    if ( ! ( aWord[i] == aWord[ len - 1 - i ] ) ) 

      // ... I return "false".
      return 0; // false
  }

  // If all matching pairs of characters in "aWord" are equal, 
  // then "aWord" is indeed a palindrome. I return "true".
  return 1; // true
}
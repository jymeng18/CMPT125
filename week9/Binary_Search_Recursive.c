/* 
 * Filename: BinarySearch_Recursive.c
 *
 * Description: Recursive Binary Search function and test driver.
 *
 * Modified: AL 
 *
 * Modification Date: July 2025
 */
 
#include <stdio.h>
#include <math.h>

// Recursive implementation of Binary Search algorithm
// Returns the first location (index) where target is found 
// in given array theData[low..high], otherwise returns -1
int binarySearch( int * theData, unsigned int low, unsigned int high, int target ) {
  const int NOT_FOUND = -1;
  unsigned int result;

  // Base Case
  if (low > high) 
    // If we have not yet found target, 
    // then target is not in "theData"
    return NOT_FOUND;
      
  // Compute the index of the middle element
  int mid = floor( (low + high) / 2 );

  // Have we found target?
  // Yes!
  if ( theData[mid] == target ) return mid;

  // No yet!
  // Target greater than middle element, 
  // so let's ignore left half
  if ( theData[mid] < target ) {
    result = binarySearch( theData, mid + 1, high, target );
	return result;
  }
    
  // No yet!
  // Target lesser than middle element, 
  // so let's ignore right half
  if ( theData[mid] > target ) {
    result = binarySearch( theData, low, mid - 1, target );
    return result;
  }
}

// Driver code
int main(void) {
    
	// Test Case 1
	int theData[] = { 2, 3, 4, 10, 40, 45, 52, 67, 88, 97 };
    int target = 88;
    unsigned int n = 10;
	
	// Test Case 2 - Can you create a test case that would represent 
	//               the Worst Case Scenario of Binary Search?
	
	
    int result = binarySearch(theData, 0, n - 1, target);
	
	// Has Binary Search found the target element?
    (result == -1) ?
      printf("Target %d is not found in theArray.\n", target):
      printf("Target %d is found in theArray at index %d.\n", target, result);
	  
    return 0;
}
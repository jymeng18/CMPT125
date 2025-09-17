#include <stdio.h>
#include <math.h>

int binarySearch(int * data, unsigned int size, int target){

    int low = 0;
    int high = size - 1;
    
    // Base case
    while(low <= high){

        int mid_index = floor(low + high / 2);
        
        if(data[mid_index] == target) return mid_index;

        if(data[mid_index] > target){
            high = mid_index - 1;
        }
        if(data[mid_index] < target){
            low = mid_index + 1;
        }
    }
    return -1;
}


// Driver code
int main(void) {
    
	// Test Case 1
	int theData[] = { 2, 3, 4, 10, 40, 45, 52, 67, 88, 97 };
    int target = 88;
    unsigned int n = 10;
	
	// Test Case 2 - Can you create a test case that would represent 
	//               the Worst Case Scenario of Binary Search?
	
	
    int result = binarySearch(theData, n, target);
	
	// Has Binary Search found the target element?
    (result == -1) ?
      printf("Target %d is not found in theArray.\n", target):
      printf("Target %d is found in theArray at index %d.\n", target, result);
	  
    return 0;
}
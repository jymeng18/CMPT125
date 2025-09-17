// Write a function void swap(int *a, int *b) that swaps the values of two integers using pointers. 
// Test it in main() by scanning two integers and printing the result after swapping 

#include <stdio.h>

void swap(int *a, int *b){

    int tempVal = *a; 
    *a = *b;
    *b = tempVal;
}

int main(void){

    int x = 10;
    int y = 5;

    // Before swapping:
    printf("Int X: %d, Int Y: %d\n", x, y);

    swap(&x, &y);

    // After Swapping
    printf("After Swapping: Int X: %d, Int Y: %d\n", x, y);

    return 0;
}
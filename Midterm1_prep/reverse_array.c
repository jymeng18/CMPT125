
// Write a function void reverse(int arr[], int size) that reverses the elements of an integer array in-place. 
// Use a while loop and pointer notation.

#include <stdio.h>

void reverse(int arr[], int size){

    int reversed[size];

    for(int i = 0; i < size; i++){
        reversed[i] = arr[size - i - 1];
    }

    for(int i = 0; i < size; i++){
        printf("%d ", reversed[i]);
    }

}

int main(void){

    int arr[] = {1, 2, 3, 4, 5};
    int SIZE = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, SIZE);

    return 0;
}
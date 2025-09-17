#include <stdio.h>

void bubbleSort(int arr[], int size) {
// 1st iteration starts at first element, comparing with 2nd element, 
// 2nd iteration starts at 2nd element comparing with 3rd element ...   
    for (int i = 0; i < size - 1; i++) { 
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sort: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("After sort:  ");
    printArray(arr, size);

    return 0;
}

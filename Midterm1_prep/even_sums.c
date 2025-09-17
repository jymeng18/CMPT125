// Write a program that reads two integers start and end using scanf, 
// then prints the sum of all even numbers between them (inclusive). Use a for loop.

#include <stdio.h>

int main(void){

    int start;
    int end;
    int sum = 0;

    printf("Enter 2 integer values: ");
    scanf("%d %d", &start, &end);

    for(int i = start; i < end + 1; i++){
        if(i % 2 == 0){
            sum += i;
        }
    }
    printf("SUM: %d", sum);

    return 0;
}
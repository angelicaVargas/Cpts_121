/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Homework 03
* Date: September 24, 2021
* Description: This program asks the user to input a number to create the length of an array and 
* calculates the sum and average of the array. 
* The program then asks the user to input a number between 1 to 1,000 and finds how many times 
* that number appears in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    unsigned int MAX, i;
    int sum, user_number, count = 0;
    double average;

    printf("Enter the size of the array: ");
    scanf("%d", &MAX); 
    int num[MAX];

    for(i = 0; i < MAX; i++) {
        num[i] = 0;
    }
    srand((unsigned int) time(NULL));
    for(i = 0; i < MAX; i++) {
        num[i] = (abs(rand()) % 1000) + 1;
    }
    for(i = 0; i < MAX; i++) {
        sum = sum + num[i];
    }
        average = (double)sum / MAX;
        printf("Sum: %d \nAverage: %lf \n", sum, average);

        printf("Enter a number between 1 and 1,000: ");
        scanf("%d", &user_number);

    for (i = 0; i < MAX; i++) {
        if (num[i] == user_number) {
            count++;
    }
    }
    printf("The number %d appears %d times on the array.\n", user_number, count);
    return 0;
}

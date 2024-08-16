/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab2 Task1
* Date: September 2, 2021
* Description: This program prints out a simple small calculation.
*/

#include <stdio.h>

int main(void)
{
        int number1_int = 0, number2_int = 0;
        double number1_float = 0.0, number2_float = 0.0;

        printf("Enter two integer values: ");
        scanf("%d%d", &number1_int, &number2_int);

        printf("Enter two floating-point values: ");
        scanf("%lf%lf", &number1_float, &number2_float);

	printf("Addition of two integers is %d\n", number1_int + number2_int);

	printf("Subtraction of two floats is  %.4lf\n", number2_float - number1_float);
  	
	printf("Multiplication of an integer and float number is %d\n", number1_int * number2_int);

	printf("Division of two integers is %d\n", number1_int / number2_int);

	printf("Division of an integer and a float number is %d and %.4lf\n", number1_int / (int) number2_float, number1_int / number2_float);

	printf("An integer divided by a float number is %.4lf\n", (float)number1_int / number2_int);

	printf("The mod of the two floats is %d\n", (int)number1_float % (int)number2_float);

	printf("Even or odd: Number 1: %d and Number 2: %d\n", number1_int % 2, number2_int % 2);

        return 0;
}

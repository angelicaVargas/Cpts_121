/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab2 Task1
* Date: September 2, 2021
* Description: Creating a lab working directory: Third order polynomial equation. 
*/

#include <stdio.h>

int main(void)
{
	double a, b, c, d, x;
	double equation;	

	printf("Input your 'a' value in a decimal form: ");
	scanf("%lf", &a); 	

	printf("Input your 'b' value in a decimal form: ");
        scanf("%lf", &b);

	printf("Input your 'c' value in a decimal form: ");
        scanf("%lf", &c);

	printf("Input your 'd' value in a decimal form: ");
        scanf("%lf", &d);
	
	printf("Input your 'x' value in a decimal form: ");
        scanf("%lf", &x);
	
	equation = 3 * a * (x * x * x) + (1/4) * b * (x * x) + 10 * c * (x) + (-5) * d;

	printf("The 'y' value is %lf\n", equation);

	return 0;
}


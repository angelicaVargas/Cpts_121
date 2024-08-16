/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab2 Task1
* Date: September 2, 2021
* Description: Creating a lab working directory: Circumference of a circle.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main(void)
{
	double circumference, radius;

	printf("Enter the radius: ");
	scanf("%lf", &radius);

	circumference = 2 * PI * radius;

	printf("The circumference is %lf\n", circumference);

	return 0;
}	

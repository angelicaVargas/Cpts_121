/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab2 Task1
* Date: September 2, 2021
* Description: Creating a lab working directory: Joule's Law. 
*/

#include <stdio.h>

int main(void)
{
	double voltage, resistance;

	printf("Input the values for voltage and resistance: ");
	scanf("%lf%lf", &voltage, &resistance);

	printf("The power value is %lf\n", (voltage * voltage) / resistance);

	return 0;
}

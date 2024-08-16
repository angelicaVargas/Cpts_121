/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab3 Task2
* Date: September 10, 2021
* Description: Collatz conjecture - no matter what value of 'n' you start with, you will end up with 1 
*/
#include <stdio.h>
int main()
{
	int n;

	printf("Enter n: ");
	scanf("%d", &n);

	if(n < 0)
        {
	printf("Error. Enter a positive number.");
        
	return 0;
	
	} else {
	
	while (n > 1)
	{
	if(n % 2 == 0)
	{
	n = n/2;
	printf("%d\n", n);
	
	} else {
	
	n = n * 3 + 1;
	printf("%d\n", n); }
	}
	return 0;
	}
}

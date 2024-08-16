#include <stdio.h>

int main(void)
{
	double dbl = -49.14141;
	int j = 99;

	printf("%lf\n", dbl); //6 digits after the decimal point
	printf("%.10lf\n", dbl); //10 digits after the decimal point
	printf("%20lf\n", dbl); //20 spaces before the number
	printf("%d\n", j); //prints an integer
	printf("%10d\n", j); //prints integer with 10 before it
	printf("%010d\n", j); //prints 10 zeros before the integer

	return 0;
}


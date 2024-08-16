#include <stdio.h>
#define PI 3.141592653

int main(void)
{
	double radius, circumference;

	printf("Enter a radius: ");
	scanf("%lf", &radius);
	circumference = 2 * PI * radius;
	printf("Circumference: %lf\n", circumference);

	return 0;
}

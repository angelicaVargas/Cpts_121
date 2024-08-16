/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab3 Task1
* Date: September 17, 2021
* Description: Pascal’s triangle: This will work with any positive value of MAX_ROWS. This one
* produces cool-looking results on an 80-character width console, but
* you might want to set it to a lower value like 5 while debugging.
*/

#include <stdio.h>
#define MAX_ROWS 16

int main(void)
{
	int oldRow[MAX_ROWS+1], newRow[MAX_ROWS+1];
	int m, n;

	for(n=0; n<=MAX_ROWS-1; n++) {
        for(m=0; m<=n; m++) {
			if (m == 0) {
				newRow[m] = 1;
			}
			else if (m == n) {
				newRow[m] = 1;
			}
			else
			{
				newRow[m] = oldRow[m] + oldRow[m-1];
			}
		}
		for (m=0; m<=n; m++) {
			printf("%d ", newRow[m]);
			oldRow[m] = newRow[m];
		}
	
		printf("\n");
	}
	return 0;
}

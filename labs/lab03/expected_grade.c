/*
* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021; Lab Section 02
* Programming Assignment: Lab3 Task1
* Date: September 10, 2021
* Description: Finding the minimum final test grade for a given expected final grade
*/

#include <stdio.h>
int main(void)
{
	double score1, score2, score3, score4;
	char final_score_letter;
	int final_score;

	printf("Enter score 1: ");
	scanf("%lf", &score1);

	printf("Enter score 2: ");
        scanf("%lf", &score2);

	printf("Enter score 3: ");
        scanf("%lf", &score3);

	printf("Enter letter: ");
        scanf(" %c", &final_score_letter);

	if(score1<0 && score2<0 && score3<0)
	{	

	printf("Error...");
	return 0;

        }
	
	else {

        if (final_score_letter == 'A')
                final_score = 90;

        else if (final_score_letter == 'B')
                final_score = 80;

        else if (final_score_letter == 'C')
                final_score = 70;

	else if (final_score_letter == 'D')
                final_score = 60;

	else
                final_score = 0;
        }

        score4 = 4 * final_score - score1 - score2 - score3;

        printf("The minimum numerical grade for the fourth score to get a final grade %c is %.2lf.", final_score_letter, score4);

        return 0;
}

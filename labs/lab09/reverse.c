/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Lab 09
* Date: October 22, 2021
* Description: This program reverses strings.
*/

#include <stdio.h>

char string_reverse(char word[]) {

    int k = 0, max;
    while(word[k] != '\0') {
        k++;
    }
    max = k;

    //finding max
    char temp;
    int i = 0;

    for(int i = 0; i < max/2; i++) {
        temp = word[i];
        word[i] = word[max - 1 - i];
        word[max - 1 - i] = temp;
    }
        return printf("%s\n", word);
}

int main()
{
    char word1[40];
    printf("Please enter a word: ");
    scanf("%s", word1);

    string_reverse(word1);

    return 0;
}

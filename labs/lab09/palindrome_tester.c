/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Lab 09
* Date: October 22, 2021
* Description: This program detects palindromes. 
*/

#include <stdio.h> 
#include <string.h> // for strlen()
#include <ctype.h> // for tolower()
#define MAX_LINE_LENGTH 1024 // assume no lines longer than this int isAPalindrome(char line[])

int isAPalindrome(char line[]) {

    int i, j;
    char buf[MAX_LINE_LENGTH];
    strcpy(buf, line);
    i = 0;
    j = strlen(buf)- 1;

    while(i < j) {
        if (tolower(buf[i]) != tolower(buf[j])) {
            return 0; //line is not a palindrome
        }
        i++;
        j--;
    }
    return 1; //line is a palindrome)
}

int main(void) {
    char word[MAX_LINE_LENGTH];
    printf("Enter a word: ");

    fgets(word, MAX_LINE_LENGTH, stdin);
    word[strcspn(word, "\n")] = 0;

    if(isAPalindrome(word) == 1) {
        printf("%s is a palindrome\n", word);
    } else {
        printf("%s is not a palindrome\n", word);
    }
    return 0;
}

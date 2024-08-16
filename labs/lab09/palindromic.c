/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Lab 09
* Date: October 22, 2021
* Description: This program creates a palindromic "filter"
* and reads a series of input to print only those who are
* palindromes to stardard output
*/

#include <stdio.h> // for standard I/O functions #include <string.h>// for strlen()
#include <string.h>
#include <ctype.h> // for tolower()
#define MAX_LINE_LENGTH 1024 // assume no lines longer than this 
// remove everything that isn't a letter from `buf`, shortening
// it as necessary

void removeNonLetters(char buf[]) {

    int i = 0, j = 0; 
    while(buf[j] != '\0') {
        if(isalpha(buf[j]) != 0) {
            buf[i] = buf[j];
            i++;
        }
        j++;
    }
    buf[i] = '\0';
}

int isAPalindrome(char line[]) {

    int i = 0, j = 0;
    char buf[MAX_LINE_LENGTH];
    strcpy(buf, line);
    removeNonLetters(buf);
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

    char line[MAX_LINE_LENGTH];
    printf("Enter a word: ");

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) { 

        removeNonLetters(line);
        isAPalindrome(line);

        if((strlen(line) >= 3) && (isAPalindrome(line)) == 1) {
            printf("%s", line);
        }
    }
        return 0;
}
/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Lab 1
* Date: November 5, 2021
* Description: This program helps players of crossword-like
* word-spelling games to find words (scraml).
*/

#include <stdio.h>
#include <string.h>

/*
 * scrabl -- prompt the user for letters and find all words containing
 *           them
 * All buffers and words should be this size.
 */

#define BUFFER_SIZE 1024

int wordIsLegal(char word[BUFFER_SIZE], char letters[BUFFER_SIZE])
{
    char buffer[BUFFER_SIZE];
    int foundVowel = 0;
    char *strchr(const char *s, int c);
    char ch;
    int i = 0;
    char vowels[] = "aeiouwy";
    
    strcpy(buffer, letters); 

    for(i = 0; i < strlen(word); i++) {
        ch = word[i];
        char *ch_p;
        ch_p = strchr(buffer, ch);

        if(ch_p == NULL) {
            break;
        }
        if(strchr(vowels, ch) != 0) {
            foundVowel = 1;
        }
        *ch_p = ' '; //set the character at 'ch`'s position in 'buffer' to ' '
        }

    if ((i == strlen(word)) && (foundVowel = 1) && (strlen(word) >= 2))
        return 1; //true
    else
        return 0; //false
}

int main(void)
{
    char word[BUFFER_SIZE];
    char letters[BUFFER_SIZE];

    int countWords = 0;

    printf("Enter your letters: ");
    scanf("%s", letters);

    FILE *f_p;
    f_p = fopen("words.txt", "r");
    

    while (fscanf(f_p, "%s", word) != EOF) { 
        if(wordIsLegal(word, letters) == 1) {
            printf("%s\n", word);
            countWords++;
        }
    }
    printf("%d\n", countWords); //report 'countWords' words found

    fclose(f_p); //close the file

    return 0;
}
 
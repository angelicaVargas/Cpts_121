/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Homework 06
* Date: November 4, 2021
* Description: This program creates an array of structs
* and prints it.
*/

#include <stdio.h>
#include <string.h>

/*
 * First, we #define sizes of every string (char array) attribute in
 * the database. This is its maximum length plus one (and its minimum
 * width for table printing purposes).
 */

#define NAME_SIZE 15
#define FILM_SIZE 50
#define WEAKNESS_SIZE 25
#define DEFEATED_BY_SIZE 30

/* add additional *_SIZE #define's according to the table above */

/*
 * This "struct" declares all information we want to maintain in the
 * "monster" database. All strings have the #define'd sizes given
 * above.
 */

typedef struct {
    char name[NAME_SIZE];
    char film[FILM_SIZE];
    int year;
    char weakness[WEAKNESS_SIZE];
    char defeatedBy[DEFEATED_BY_SIZE];
    double rating;

    /*
     * Add additional elements according to the table above and using
     * the *_SIZE #define's (for the char arrays only).
     */

} Monster;

/*
 * Initialize an array of structs to form the database.
 */
Monster monsters[] = {
    {
        /* We'll initialize the first structure by position. */
        "Count Dracula",
        "Dracula",
        1931,
        "wooden stake",
        "Van Helsing",
        7.6,
    },
    {
        /*
         * We'll initialize the second stucture by attribute name,
         * rearranging the order just to show we can do it.
         */
        .rating=8.0,
        .film="Frankenstein",
        .weakness="fire",
        .name="The Monster",
        .year=1931,
        .defeatedBy="villagers",
    },
};


void monster_print(Monster monster)
/* print a "monster" */
{
    int colonIndent = 15; /* set this empirically so the ':'s line up */

    /*
     * The following shows a good way to print out attributes: one per
     * line with the attribute name appearing as "ragged left"
     * followed by a ':'.
     */

    printf("%*s: %s\n",   colonIndent, "Name", monster.name);
    printf("%*s: %s\n",   colonIndent, "Film", monster.film); 
    printf("%*s: %d\n",   colonIndent, "Year", monster.year);
    printf("%*s: %s\n",   colonIndent, "Weakness", monster.weakness);
    printf("%*s: %s\n",   colonIndent, "Defeated By", monster.defeatedBy);
    printf("%*s: %.1lf\n",   colonIndent, "Rating", monster.rating);

    /*
     * Add additional printf() calls similar to the one above. Be sure
     * to use the format that matches the attribute type.
     */
}

int main(void)
{
    for(int i = 0; monsters[i].name[0] != 0; i++) {
        monster_print(monsters[i]);
        printf("\n");
    }
    /*
     * for each `monster[i]` in the `monsters` array (as long as
     *  `monster[i].name[0] != 0`)
     *     print it using monster_print()
     *     print an extra newline to separate outputs
     */

    return 0;
}

/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Homework 05
* Date: November 4, 2021
* Description: This program sorts turns a cvs file
* and prints it out into an HTML output.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 15
#define film_SIZE 50
#define weakness_SIZE 25
#define defeatedBy_SIZE 30
#define MAX_MONSTERS 1024 /* should be big enough */

typedef struct {
    char name[NAME_SIZE];
    char film[film_SIZE];
    int year;
    char weakness[weakness_SIZE];
    char defeatedBy[defeatedBy_SIZE];
    double rating;

} Monster;

Monster monsters[MAX_MONSTERS];

int foundColumnName(char columnName[], char followedBy)
/* helper function used to read an expected column name */
{
    char buffer[2048]; /* longer than the longest possible column name */

    if (scanf("%[^,\n]s",  buffer) != 1     /* didn't read one item */
        || strcmp(buffer, columnName) != 0  /* doesn't match `columnName` */
        || getchar() != followedBy) {       /* not followed by expected char */
        return 0;
    }
    return 1;
}


int scanCsvHeader(void)
/* scans a CSV-compatible "monster" header for compatibility */
{
 
    if (!foundColumnName("Name", ','))
        return 0;

    if (!foundColumnName("Film", ','))
        return 0;

    if (!foundColumnName("Year", ','))
        return 0;

    if (!foundColumnName("Weakness", ','))
        return 0;

    if (!foundColumnName("Defeated by", ','))
        return 0;

    if (!foundColumnName("Rating", '\n'))

        return 0;
    else
        return 1;    
}


int scanCsvRow(Monster *monster)
/* reads a Monster row from a CSV file */
{
    if (scanf("%[^,\n]s",  monster->name) != 1)
        return 0;
    getchar(); /* skip the following comma or newline (we could check this) */
    
    if (scanf( "%[^,\n]s", monster->film) != 1)
        return 0;
    getchar();

    if (scanf("%d",  &monster->year) != 1)
        return 0;
    getchar();

    if (scanf("%[^,\n]s", monster->weakness) != 1)
        return 0;
    getchar();

    if (scanf("%[^,\n]s", monster->defeatedBy) != 1)
        return 0;
    getchar();

    if (scanf("%lf",  &monster->rating) != 1)
        return 0;
    getchar(); /* should be end of line */

    return 1;
}


int loadDatabase(void)
/* reads a CSV monster database on standard input, returns the number of members */
{
    int count = 0;

    if (!scanCsvHeader())
        return 0;
    for (;;) {
        if (!scanCsvRow(&monsters[count]))
            break;
      count++;
    }
    monsters[count].name[0] = '\0';
    return count;
}


int compareMonstersByYear(const void *monster0_vp, const void *monster1_vp)
{

    const  Monster *monster0_p = monster0_vp;
    const  Monster *monster1_p = monster1_vp;

    /* sort monsters by year of film release */
    return monster0_p->year - monster1_p->year;
}

void monster_printHtmlTableHeader(void)
/* print the header for an HTML table of monster */
{
	printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */
    printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */

	printf("<div class='rTableHead'><strong>Name</strong></div>\n");
    printf("<div class='rTableHead'><strong>Film</strong></div>\n");
    printf("<div class='rTableHead'><strong>Year</strong></div>\n");
    printf("<div class='rTableHead'><strong>Weakness</strong></div>\n");
    printf("<div class='rTableHead'><strong>Defeated By</strong></div>\n");
    printf("<div class='rTableHead'><strong>Rating</strong></div>\n");
 
    printf("</div>\n"); /* HTML table rows end with this tag */
}

void monster_printHtmlTableRow(Monster monster)
/* print the data in "monster" as an HTML row */
{
    printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */

    printf("<div class='rTableCell'>%s</div>\n", monster.name);
    printf("<div class='rTableCell'>%s</div>\n", monster.film);
    printf("<div class='rTableCell'>%d</div>\n", monster.year);
    printf("<div class='rTableCell'>%s</div>\n", monster.weakness);
    printf("<div class='rTableCell'>%s</div>\n", monster.defeatedBy);
    printf("<div class='rTableCell'>%.1lf</div>\n", monster.rating);

    printf("</div>\n"); /* HTML table rows end with this tag */
}

void monster_printHtmlHeader()
/* print the header for HTML*/
{
		printf("<!DOCTYPE html>\n"
		"<html>\n"
		"<head>\n"
		"<style>\n"
        ".rTable {\n"
        "display: table;\n"
        "width: 100%%;\n"
        "}\n"
        ".rTableRow {\n"
        "display: table-row;\n"
        "}\n"
        ".rTableHead {\n"
        "display: table-cell;\n"
        "padding: 3px 10px;\n"
        "border: 1px solid #999999;\n"
        "}\n"
        ".rTableCell {\n"
        "display: table-cell;\n"
        "padding: 3px 10px;\n"
        "border: 1px solid #999999;\n"
        "}\n"
		"</style>\n"
		"</head>\n"
		"<body>");	
}

void monster_printHtmlBottom()
/* print the Bottom for HTML*/
{
	printf(
        "</body>\n"
        "</html>\n");
}

int main(void)
{
    int monsterCount;

    monsterCount = loadDatabase();
    if (monsterCount > 0) {
        qsort(monsters, monsterCount, sizeof(Monster),
              compareMonstersByYear);
    }
   monster_printHtmlHeader();
    
    printf("<div class='rTableRow'>"); 
    monster_printHtmlTableHeader();
  
    for(int i=0; monsters[i].name[0] != '\0'; i++) {
        monster_printHtmlTableRow(monsters[i]);
    }

    printf("</div>"); 
    monster_printHtmlBottom();
    
    return 0;
}

#include <stdio.h>
#include <string.h>

/*
 * Copy the Monster structure definition here.
 */

#define NAME_SIZE 15
#define FILM_SIZE 50
#define WEAKNESS_SIZE 25
#define DEFEATED_BY_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    char film[FILM_SIZE];
    int year;
    char weakness[WEAKNESS_SIZE];
    char defeatedBy[DEFEATED_BY_SIZE];
    double rating;

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

void monster_printHtmlTableHeader(void)
/* print the header for an HTML table of monster */
{
	printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */
    printf("<div class='rTableRow'>\n"); /* HTML table rows begin with this tag */
    /*
     * Here's how to print the first column, which is "Name":
     */
	printf("<div class='rTableHead'><strong>Name</strong></div>\n");
    /*
     * Insert additional printf()s for the other column names, in
     * order.
     */
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
    printf("<div class='rTableCell'>%s</div>\n",  monster.name);
    
    /*
     * Insert additional printf()s for the other attribute values, in
     * order. Be sure to choose the right format for printf(). The
     * `rating` should be printed with one decimal place.
     */

    printf("<div class='rTableCell'>%s</div>\n",  monster.film);
    printf("<div class='rTableCell'>%d</div>\n",  monster.year);
    printf("<div class='rTableCell'>%s</div>\n",  monster.weakness);
    printf("<div class='rTableCell'>%s</div>\n",  monster.defeatedBy);
    printf("<div class='rTableCell'>%.1lf</div>\n",  monster.rating);

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
	    
    printf("</body>\n"
    "</html>\n");
}

int main(void)
{
    monster_printHtmlHeader();

    printf("<div class= 'rTableRow'>");
    monster_printHtmlTableHeader(); 
    
    for(int i = 0; monsters[i].name[0] != 0; i++) {
        monster_printHtmlTableRow(monsters[i]);
    }
    /*
     * print HTML header
     * print "<div class="rTable">" to begin the HTML table
     * print the HTML table header using monster_printHtmlTableHeader()
     */


    /* for each monster in the `monsters` array (as long as name[0] != '\0')
     *     print it as a row in the table using monster_printHtmlTableRow()
     * print "</div>" to end the HTML table
     */

    printf("</div");
    monster_printHtmlBottom();

    return 0;
}


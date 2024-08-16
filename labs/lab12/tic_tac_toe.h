#ifndef _INCLUDED_TIC_TAC_TOE_H /* effectively prevents multiple #includes */

/*
 * This header file describes the Board struct and all accessible
 * functions in the Tic Tac Toe library.
 */

#define MAXELEMENT 3


/* ASSIGNMENT
 * Add structure definitions for the library (Board and Cell)
 */

typedef struct
{
    int occupied; // 0 means unoccupied, 1 means occupied
    char symbol; //'X' or 'O' or ' '
} Cell;

typedef struct
{
    Cell cells[MAXELEMENT][MAXELEMENT]; // 9 spaces in our board
    int winner; // 1 if the currentPlayer has won, 0 otherwise
    int counter; // for how many turns have been played in total
    int size; // should match the dimensions of the `cells` array
    int currentPlayer; // 0 for 'O's and 1 for 'X's
} Board;

/*
 * ASSIGNMENT
 *
 * Add extern prototypes for all functions in "tic_tac_toe_demo.c"
 */
  
Cell initializeCell(char, int);
void getPosition(Board, int[2]);
Board updateBoard(int, int, Board);
int isWinningMove(int, int, Board);
void printBoard(Board);

#define _INCLUDED_TIC_TAC_TOE_H
#endif

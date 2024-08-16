#include<stdio.h>
#include<time.h> //time()
#include<stdlib.h> //srand() and rand()

#include "tic_tac_toe.h"

// ASSIGNMENT
// #include the header that corresponds to this library file. You should
// do this in the source file for every library you write. Also include
// any other headers you might need to write the bodies of the functions.
// Recall that if you're including a header file you created, you need to
// surround the file name with string quotes, i.e. "", instead of <>, which is
// reserved for C standard libraries.

// ASSIGNMENT
// Define the bodies of all the functions you prototyped in the header file.

Cell initializeCell(char sym, int isOccupied)
{
    // TODO: Create a local variable of type Cell and initialize its
    // members according to the arguments passed into this function.
    // Then return the local variable.
    //
    // This function is here mainly to show you that you can return structs
    // from a function.
    Cell Thing;

    Thing.symbol=sym;
    Thing.occupied=isOccupied;

    return Thing;
}

void getPosition(Board board, int pos[2])
{
    int r, c; // Remember, these are local variables to the function
    do
    {
        printf("Enter the row and column: ");
        scanf("%d%d", &r, &c);
    } while (r>2 || r<0 || c>2 || c<0 || board.cells[r][c].occupied==1);
    pos[0] = r;
    pos[1] = c;
}

Board updateBoard(int r, int c, Board board)
{
	board.cells[r][c].occupied=1;
    board.counter++;

	if (board.currentPlayer == 0)
		board.cells[r][c].symbol = 'O';
	else
		board.cells[r][c].symbol = 'X';

    return board;
}

int isWinningMove(int r, int c, Board board)
{
    int possibleWin = 0;
    char playerSymbol;

    if (board.currentPlayer == 0)
	    playerSymbol='O';
    else
	    playerSymbol='X';

    for (int column = 0; column < board.size; column++)
    {
        if (board.cells[r][column].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
            break;
        }
    }

    if (possibleWin == 1)
        return possibleWin;;

    for (int row = 0; row < board.size; row++)
    {
        if (board.cells[row][c].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
            break;
        }
    }

    if (possibleWin)
        return possibleWin;

    /* Check the column */

    /* If `possibleWin` is a 1, the current player won. Return that player. */

    if (c == r)
    {
      for (int diagonal = 0; diagonal < board.size; diagonal++)
      {
        if (board.cells[diagonal][diagonal].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
            break;
        }
      }
    }

    if (possibleWin==1)
      return possibleWin;

    /* If `possibleWin` is a 1, the current player won. Return that player. */
    if (c == board.size - 1 - r)
    {
	    for (int otherdiagonal = 0; otherdiagonal < board.size; otherdiagonal++)
      {
        if (board.cells[otherdiagonal][board.size-1-otherdiagonal].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
            break;
        }
      }
    }

    if (possibleWin==1)
	    return possibleWin;

    return 0;
    /* Check if `possibleWin` is a 1. If it is, return the current player.
     * Otherwise, return 0 to indicate no one won on that move.
     */
}

void printBoard(Board board)
{
    // Don't touch this function. It already prints things nicely for you.
    // Note that here, I'm treating the first index of the cells array
    // as the row, and the second as the column.
    for (int row = 0; row < board.size; row++)
    {
        printf("| ");
        for (int column = 0; column < board.size; column++)
        {
            printf("%c | ", board.cells[row][column].symbol);
        }
        printf("\n");
    }

    printf("\n");
}
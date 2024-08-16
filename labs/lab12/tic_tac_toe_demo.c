#include<stdio.h>
#include<time.h> //time()
#include<stdlib.h> //srand() and rand()

#define MAXELEMENT 3

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

// In function prototypes, just the type of each argument is sufficient.
Cell initializeCell(char, int);
void getPosition(Board, int[2]);
Board updateBoard(int, int, Board);
int isWinningMove(int, int, Board);
void printBoard(Board);

int main(void)
{
    srand(time(NULL));
    Board mainBoard;

    // TODO: Initialize the members of the mainBoard to appropriate values.
    // You must choose a random player to start.
	mainBoard.counter=0;
	mainBoard.size=3;
	mainBoard.winner=0;
	mainBoard.currentPlayer=rand() % 2;

    // TODO: Initialize each cell in the mainBoard to an unoccupied cell
    // with a single space for the symbol. Note that you'll need a nested
    // for loop to do this, since the cells array inside mainBoard is 2D.
    // Use your initializeCell() function to do this.
	for(int i=0; i<mainBoard.size; i++)
	{
		for(int n=0; n<mainBoard.size; n++)
		{
			mainBoard.cells[i][n]=initializeCell(' ', 0);
		}
	}

    while ((mainBoard.winner == 0) && (mainBoard.counter < 9))
    {
        // TODO:
        // 1) Alternate the mainBoard.currentPlayer
        // 2) Create an array that holds 2 ints called `position`
        // 3) call the getPosition() function, passing in the `mainBoard`
        //    and the `position` array. getPosition() "returns" two
        //    values by using this array to hold the output values.
        // 4) call updateBoard(), passing in the row and column which
        //    were stored in the `position` array by getPosition() and
        //    the `mainBoard`. Assign its return value to mainBoard, effectively
        //    updating main()'s local mainBoard variable.
        // 5) set `mainBoard.winner` to the return value of isWinningMove().
        //    Pass in the row and column of the cell that was just played
        //    and the `mainBoard`.
        // 6) call printBoard()
        int position[2];
        mainBoard.currentPlayer = 1 - mainBoard.currentPlayer;
        printf("Player %d's turn. ", mainBoard.currentPlayer);
        getPosition(mainBoard, position);
        mainBoard = updateBoard(position[0], position[1], mainBoard);
        mainBoard.winner = isWinningMove(position[0], position[1], mainBoard);
        printBoard(mainBoard);
    }

	if (mainBoard.winner==0)
		printf("Tie Game\n");
	else
		printf("Player %d won\n", mainBoard.currentPlayer);

    return 0;
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

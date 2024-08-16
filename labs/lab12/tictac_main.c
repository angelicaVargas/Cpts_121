#include<stdio.h>
#include<time.h> //time()
#include<stdlib.h> //srand() and rand()

#include "tic_tac_toe.h"

int main(void)
{
    srand(time(NULL));
    Board mainBoard;

	mainBoard.counter=0;
	mainBoard.size=3;
	mainBoard.winner=0;
	mainBoard.currentPlayer=rand() % 2;

	for(int i=0; i<mainBoard.size; i++)
	{
		for(int n=0; n<mainBoard.size; n++)
		{
			mainBoard.cells[i][n]=initializeCell(' ', 0);
		}
	}

    while ((mainBoard.winner == 0) && (mainBoard.counter < 9))
    {
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
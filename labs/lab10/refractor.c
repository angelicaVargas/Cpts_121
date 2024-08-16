#include <stdio.h>

void printStatus(int player, int heapCount1, int heapCount2, int heapCount3) {

    printf("player %d's turn\n", player);
        /* print out the counts */
    printf("heap 1: %d\n", heapCount1);
    printf("heap 2: %d\n", heapCount2);
    printf("heap 3: %d\n", heapCount3);
    }

int getHeap(void) {

    int heap;
    for (;;) {
        printf("heap to take stones from (1 - 3): ");
        scanf("%d", &heap);
        if (1 <= heap && heap <= 3) {
            break;
        }
        printf("illegal heap value -- try again\n");
    }
    return heap;
}

int *getHeapCountPointer(int heap, int *heapCount1, int *heapCount2, int *heapCount3) {

    int *heapCount_p;

    switch(heap) {

        case 1:
            heapCount_p = heapCount1;
            break;

        case 2:
            heapCount_p = heapCount2;
            break; 

        case 3:
            heapCount_p = heapCount3;
            break;
        }
    return heapCount_p;
}

int getTake(int heap, int *heapCount_p) {

    int take;
    for (;;)
    {
        printf("count of stones to take from heap %d (1 - %d): ",
        heap, (*heapCount_p));
        scanf("%d", &take);
        /*
        * If the take is in the proper range, the move is legal,
        * so break out of the loop.
        */
        if (1 <= take && take <= (*heapCount_p))
        {
            break;
        }
        printf("illegal heap count -- try again\n");
    }
    return take;
}

int playNim(void) {

    int heapCount1, heapCount2, heapCount3;
    int heap, player, take = 0;
    int *heapCount_p = NULL;

    /* initialize heap counts */
    heapCount1 = 3;
    heapCount2 = 4;
    heapCount3 = 5;

    player = 2; // first player will be player 1 (see below)

    /* while any stones remain, */
    while (heapCount1 + heapCount2 + heapCount3 > 0) {
        /* select the next player */
        player = 3 - player; // player 1 -> 2 and 2 -> 1
        printStatus(player, heapCount1, heapCount2, heapCount3);

        for (;;) {
            heap = getHeap();
                /* let the player select a heap */
    /*
    * At this point, we know that `heap` is valid, so we
    * check to make sure it's not empty.
    */
    heapCount_p = getHeapCountPointer(heap, &heapCount1, &heapCount2, &heapCount3);
    /* make heapCount_p point at the relevant heap */
        if ((*heapCount_p) > 0) {
            break;
            }
        printf("heap %d contains no stones -- try again\n", heap);
        }
    /* let the player select a "take" -- a count of stones to remove */
    take = getTake(heap, heapCount_p);
    /* deduct those stones */

    (*heapCount_p) -= take;
    printf("\n"); // blank line for cosmetic purposes
    }
    return player;
}

int main(void) {
    int winner;
    winner = playNim();
    printf("player %d wins\n", winner);
    return 0;
}

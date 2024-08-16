#include <stdio.h>

int main(void)
{
    int heapCount1, heapCount2, heapCount3;
    int heap, player, take, i;
    int *heapCount_p;
    /* initialize heap counts */
    heapCount1 = 3;
    heapCount2 = 4;
    heapCount3 = 5;

    player = 2; // first player will be player 1 (see below)
    
    /* while any stones remain, */
    while (heapCount1 + heapCount2 + heapCount3 > 0)
    /* select the next player */
    {
        player = 3 - player; // player 1 -> 2 and 2 -> 1
        printf("player %d's turn\n", player);
        /* print out the counts */
        printf("(1) ");for (i=0;i<heapCount1;i++){ printf("O ");}
        printf(" \n");
        printf("(2) ");for (i=0;i<heapCount2;i++){ printf("O ");}
        printf(" \n");
        printf("(3) ");for (i=0;i<heapCount3;i++){ printf("O ");}
        printf(" \n");

        /* let the player select a heap that contains at least one stone */
        for (;;)
        {
        /* let the player select a heap */
            for (;;)
            {
            printf("heap to take stones from (1 - 3): ");
            scanf("%d", &heap);
            if (1 <= heap && heap <= 3)
            {
            break;
            }
            printf("illegal heap value -- try again\n");
        }

    /*
    * At this point, we know that `heap` is valid, so we
    * check to make sure it's not empty.
    */

 /* make `heapCount_p` point at the relevant heap */
            switch (heap)
            {
            case 1:
                heapCount_p = &heapCount1;
                break;

            case 2:
                heapCount_p = &heapCount2;
                break; 

            case 3:
                heapCount_p = &heapCount3;
                break;
            }
/*
 * If there are stones in it, the move is legal, so break
 * out of the loop.
 */
        if ((*heapCount_p) > 0)
        {
            break;
        }

        printf("heap %d contains no stones -- try again\n", heap);
    }
/* let the player select a "take" -- a count of stones to remove */
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

/* deduct those stones */
    (*heapCount_p) -= take;

    printf("\n"); // blank line for cosmetic purposes
}
/* declare the last player the winner */
printf("player %d wins\n", player);
return 0;
}
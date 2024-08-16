/* Programmer: Angelica Vargas
* Class: CptS 121, Fall 2021
* Programming Assignment: Homework 05
* Date: October 15, 2021
* Description: This program implements a variation of the dice
* game, Cee-lo. 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_game_rules(void);
int is_number_in_die(int die[3], int num);
int has_pair(int die[3]);

double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
void roll_die(int die[3]);
int get_rank(int die[3]);
int user_won_lost_or_neither(int user_die[3], int cpu_die[3]);
double adjust_balance(double balance, double wager, int add_or_subtract);


int main(void) {

    int i;
    int user_die[3], cpu_die[3];
    char continue_or_quit;
    double balance, wager;

    srand(time(0)); 
    print_game_rules();

do {
    balance = get_bank_balance();
    printf("Your current balance is %.2lf\n", balance);

    wager = get_wager_amount();

    if(check_wager_amount(wager, balance) == 0) {
        printf("Your wager is greater than your balance. Please enter a value again\n");
    
    } else {

        for(i = 0; i < 3; i++) {
            roll_die(user_die);
            printf("You rolled (%d, %d, %d)\n", user_die[0], user_die[1], user_die[2]);
        }

        for(i = 0; i < 3; i++) {
            roll_die(cpu_die);
            printf("CPU rolled (%d, %d, %d)\n", cpu_die[0], cpu_die[1], cpu_die[2]);
        }

        if(user_won_lost_or_neither(user_die, cpu_die) == 1) {
            printf("You won!\n");
            balance = adjust_balance(balance, wager, 1);
        }
        else if(user_won_lost_or_neither(user_die, cpu_die) == 0) {
            printf("You lost!\n");
            balance = adjust_balance(balance, wager, 0);
        }
        else {
            printf("(Unrecginized combo)\n");
        }
    }

    printf("Do you want to continue playing or quit and take your money ($%.2lf)\n", balance);
    printf("('c' to continue, 'q' to quit): ");
    scanf(" %c", &continue_or_quit);
    
} 
    while (continue_or_quit == 'c');

    printf("You left with ($%.2lf)\n", balance);

    return 0;
}


void print_game_rules(void)
{
    printf("Cee-lo rules:\n"
           "This is a battle of the player against the CPU. Both roll three\n"
           "dice each until both have a recognized combination. Whoever rolls\n"
            "the better combination wins! A tie results in both player and CPU\n"
            "rerolling their die until they each have a new combination.\n"
            "Combinations are ranked from best to worst as:\n"
            "\t4-5-6:\n\t\tThe die values are 4, 5, and 6 (any order)\n"
            "\tTrips:\n\t\tThe three die values are all the same. Higher trips\n"
            "\t\tbeats lower trips (but still note that trips beats \"point\"\n"
            "\t\t(see below).\n"
            "\tPoint:\n\t\tA pair is rolled. The non-matching dice is the\n"
            "\t\t\"point\". A higher point beats a lower point (so 1-1-5 beats\n"
            "\t\t6-3-6)\n"
            "\t1-2-3:\n\t\tThe die values are 1, 2, and 3 (any order)\n"
            "The above are the only recognized combinations. A player must\n"
            "reroll until they have one of the above combinations\n");
}

//checks if one of the numbers is in the die
int is_number_in_die(int die[3], int num) {
    for (int i = 0; i < 3; i++) {
        if (num == die[i])
            return 1;
    }
    return 0; 
}

//checks if a pair is rolled (returns the unmatched die)
int has_pair(int die[3]) {

    if (die[0] == die[1])
        return die[2];

    else if (die[1] == die[2])
        return die[0];

    else if (die[0] == die[2])
        return die[1];

    else
        return 0;
}

//prompts player for initial bank balance
double get_bank_balance(void) { 

    double balance;
    printf("Enter in an initial bank balance (in dollars): ");
    scanf("%lf", &balance);

    return balance;
}

//prompts player for a wager
double get_wager_amount(void) {

    double wager;
    printf("Enter in a wager amount (in dollars): ");
    scanf("%lf", &wager);

    return wager;
}

//checks if wager amount is within player's limits
int check_wager_amount(double wager, double balance) {

    if (wager > balance) {
        return 0;
    } else {
        return 1;
    }
}

//rolls three dice and generates a random number
void roll_die(int die[3]) {

    for(int i = 0; i < 3; i++) {
        die[i] = rand() % 6 + 1; 
    }
}

//returns the rank of the combination for the dice values passed in
int get_rank(int die[3]) {

    if(is_number_in_die(die, 4) && is_number_in_die(die, 5) && is_number_in_die(die, 6))
        return 4;
    
    else if(die[0] == die[1] == die[2]) 
        return 3;
    
    else if(has_pair(die)) 
        return 2;
    
    else if(is_number_in_die(die, 1) && is_number_in_die(die, 2) && is_number_in_die(die, 3))
        return 1;

    else
        return 0;
}

int user_won_lost_or_neither(int user_die[3], int cpu_die[3]) {

    int user_sum = 0, cpu_sum = 0;
    int user_rank = get_rank(user_die);
    int cpu_rank = get_rank(cpu_die);

    if(user_rank > cpu_rank) {
        return 1;

        if(user_rank < cpu_rank)
            return 0;

    } else {
        user_sum = user_die[0] + user_die[1] + user_die[2];
        cpu_sum = cpu_die[0] + cpu_die[1] + cpu_die[2];

        if(user_sum > cpu_sum)
            return 1;

        else if(user_sum < cpu_sum)
            return 0;

        else
            return -1;
    }
}

double adjust_balance(double balance, double wager, int add_or_subtract) {
    
    double sum = 0, difference = 0;
    
    if(add_or_subtract == 1) {
        sum = balance + wager;
        return sum;

    } else {
        difference = balance - wager;
        return difference;
    }
}

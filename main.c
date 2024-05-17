#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int checkInput(char buffer[256]);
int checkWinner(int userChoice, int computerChoice);
void printStats(int ties, int wins, int loses);

int main()
{
    srand(time(NULL));

    char buffer[256];
    int ties = 0, wins = 0, loses = 0;

    // Beginning of the game loop
    printf("Type two or more characters to exit!\n\n");
    while(true)
    {
        // Initializes an int value with the range of 1-3.
        int computerChoice = rand() % 3 + 1;

        printf("(1-3): Rock, Paper, Scissors! ");
        fgets(buffer, 256, stdin);

        if(strlen(buffer) > 2)
        {
            printf("You've exited the game!\n");
            break;
        }
        // Sanitize the user's input
        buffer[strcspn(buffer, "\n")] = '\0';

        int userChoice = checkInput(buffer);
        if(userChoice > 0)
        {
            printf("%i, %i\n", userChoice, computerChoice);
            switch(checkWinner(userChoice, computerChoice))
            {
                case 0:
                    printf("\nTie!\n"); ties ++;
                    break;
                case 1:
                    printf("\nYou win!\n"); wins ++;
                    break;
                case 2:
                    printf("\nYou lose!\n"); loses ++;
                    break;
                default:
                    printf("\nThere was an unexpected error!\n");
                    break;
            }
        }
    }
    printStats(ties, wins, loses);
    return 0;
}
int checkInput(char buffer[256])
{
    // Checks whether is the first buffer character is within the 1-3 range. 
    if(isdigit(buffer[0]) && ((int) buffer[0] > 48 && (int) buffer[0] < 52))
    {
        return (int) buffer[0] - 48;
    }
    return 0;
}
int checkWinner(int userChoice, int computerChoice)
{
    // 1 = Rock, 2 = Paper, 3 = Scissors
    if(userChoice == computerChoice)
    {
        return 0;
    }
    else if((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
    {
        return 1;
    }
    return 2;
}
void printStats(int ties, int wins, int loses)
{
    printf("\nHere are your stats!\n");
    printf("Draws: %i\nWins: %i\nloses: %i\n", ties , wins, loses);
}
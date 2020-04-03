#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for random number generator seed
#include <conio.h> //used to clear the command prompt

void game()
{
    int  maximumNumberOfGuesses =0, gess = 0, randomNumber = 0;
    time_t t;
    srand((unsigned)time(&t));
    randomNumber = rand() %21;

    printf("\n*********************** THIS IS THE GUESSING GAME ***********************\n");
    printf("\nCOMPUTER: I have chosen a number between 0 and 20 which you must guess!!!\n");

    for (maximumNumberOfGuesses = 5; maximumNumberOfGuesses > 0; --maximumNumberOfGuesses)
    {
        printf("\nYou have %d tr%s left!\n", maximumNumberOfGuesses, maximumNumberOfGuesses == 1 ? "y" : "ies");
        printf("Enter a guess: ");
        scanf("%d", &gess);

        if (gess == randomNumber){
            printf("\nCongratulations! You guessed it!\n");
            return;
        }
        else if (gess < 0 || gess > 20){ //checking for a valid guess
            printf("\nPlease! Type a number between 0 and 20.");
            ++maximumNumberOfGuesses;
        }
        else if (gess > randomNumber){
            printf("\nSorry, %d is wrong. My number is less than that.\n", gess);
        }
        else if (gess < randomNumber){
            printf("\nSorry, %d is wrong. My number is greater than that.\n", gess);
        }
    }
    printf("\nYou tried five times and fail. The number was %d!\n", randomNumber);
}
int main(void)
{
    int again = 1;
    game();
    while (again == 1){
        printf("\nWould you like to play again? (1=YES, 2=NO)\n");
        scanf("%d", &again);
    if (again == 1){
        system("cls");
        game();
    }
    }
    printf("\nBYE!\n");
    printf("\n****************** THIS IS THE END OF THE GUESSING GAME ******************\n");
    return 0;
}

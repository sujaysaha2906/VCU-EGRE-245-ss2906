/*
 * EGRE 245 Engineering Programming
 * Fall 2025 - Lab 5: Guessing Game
 */

#include <stdio.h>

int main(void)
{
    const int SECRET_NUMBER = 17;
    int choice;
    int numAttempts;
    int guess;
    int guessedCorrectly = 0;

    printf("Lab #5 - Solution\n");
    printf("EGRE 245: Introduction to Programming Using C, September 30, 2025\n\n");
    printf("Welcome to the Guessing Game!\n");
    printf("1. Play Game\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("How many attempts would you like? ");
            scanf("%d", &numAttempts);

            if (numAttempts <= 0) {
                printf("The number of attempts must be positive.\n");
                break;
            }

            for (int attempt = 1; attempt <= numAttempts; ++attempt) {
                printf("Guess the number (between 1 and 50): ");
                scanf("%d", &guess);

                if (guess > SECRET_NUMBER) {
                    printf("Too high! Try again.\n");
                } else if (guess < SECRET_NUMBER) {
                    printf("Too low! Try again.\n");
                } else {
                    printf("Congratulations! You guessed it in %d attempt(s)!\n", attempt);
                    guessedCorrectly = 1;
                    break;
                }
            }

            if (!guessedCorrectly) {
                printf("Sorry, you're out of attempts. The number was %d.\n", SECRET_NUMBER);
            }
            break;
        case 2:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid menu choice.\n");
    }

    return 0;
}

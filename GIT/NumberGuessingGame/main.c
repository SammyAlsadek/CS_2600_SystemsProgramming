//=====================================================================================================
// Name: Sammy Alsadek
// File: main.c
// Date: Sep 29th 2021, 9:16PM
// Description: An interactive program that allows a user to try and guess a randomly generated number
//=====================================================================================================

// Included files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void menu(unsigned char *);
void game(int *, int *, int *);
void getMax(int *);

int main()
{
    // Initialize random number generator
    time_t t;
    srand((unsigned)time(&t));

    // Declare variables
    unsigned char choice;   // Users inputed value for the menu option
    _Bool isContinue = '1'; // Flag that controls the game loop
    int gameMax = 10;       // Max value for game (initialized at 10)
    int guess;              // Users guessed value
    int randNum;            // Random number to guess

    // Open text file containing gameMax value from previous gamesand load it into variable
    FILE *maxValIn = fopen("maxVal.txt", "r");
    if (maxValIn != NULL) // if file exists and contains a value then use that value for the game
    {
        fscanf(maxValIn, "%d", &gameMax);
    }
    fclose(maxValIn);

    // Main game loop
    while (isContinue)
    {
        // Display menu and get users menu choice
        menu(&choice);

        // Depending on the users choice run the required code
        switch (choice)
        {
        // Start the game for the user
        case '1':
            game(&guess, &randNum, &gameMax);
            break;

        // Have user input a new max value for the game
        case '2':
            getMax(&gameMax);
            break;

        // Thank user for playing and end the game
        case '3':
            printf("Thank you for playing!\n");
            printf("\n");
            isContinue = 0;
            break;
        }
    }

    // Open text file cfor gameMax and store the current gameMax value to the file
    FILE *maxValOut = fopen("maxVal.txt", "w");
    fprintf(maxValOut, "%d", gameMax); 
    fclose(maxValOut);

    return 0;
}

// Displays menu and allows the user to input their menu option
void menu(unsigned char *choice)
{
    // Display menu
    printf("+=====================================+\n");
    printf("|              GAME MENU              |\n");
    printf("+=====================================+\n");
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n\n");

    // Get users choice
    _Bool isValid; // validity flag for valid user inputs
    do
    {
        printf("Enter choice: ");
        *choice = getchar();
        fflush(stdin); // clear input buffer
        printf("\n");
        isValid = 1;

        // Prints error for when user inputs an invalid option
        if (*choice < '1' || *choice > '3')
        {
            printf("ERROR: Invalid input. Enter values 1, 2, or 3\n");
            printf("\n");
            isValid = 0;
        }

    } while (!isValid); // Loop until valid input is given

    printf("+=====================================+\n\n");
}

// Main game function
void game(int *guess, int *randNum, int *gameMax)
{
    *randNum = (rand() % *gameMax) + 1; // get random number for the game
    _Bool isGuessed = 0;                // flag for if the user guessed the right number

    // keep looping until the user guesses correct of enters 'q'
    do
    {
        // Get users input
        _Bool isValid;      // validity flag for valid user inputs
        char temp[50] = ""; // temporarily hold the user input

        do
        {
            printf("Enter a number (Valid range [1 - %d]): ", *gameMax);
            scanf("%s", temp);
            fflush(stdin); // clear input buffer
            printf("\n");
            isValid = 1;

            // Return to menu if user inputs 'q' else store the input as an integer
            if (strcmp(temp, "q") == 0)
            {
                return;
            }
            else
            {
                *guess = atoi(temp);
            }

            // Prints error for when user inputs an invalid option
            if (*guess < 1 || *guess > *gameMax)
            {
                printf("ERROR: Invalid input.\n");
                printf("\n");
                isValid = 0;
            }

        } while (!isValid); // Loop until valid input is given

        // Inform user they won if they guessed the correct value
        if (*guess == *randNum)
        {
            printf("You Win!\n");
            printf("\n");
            isGuessed = 1; // set flag to guessed
        }
        // Inform user they if their guess is too high and let them guess again
        else if (*guess > *randNum)
        {
            printf("Guess too high. Try again\n");
            printf("\n");
        }
        // Inform user they if their guess is too low and let them guess again
        else
        {
            printf("Guess too low. Try again\n");
            printf("\n");
        }
    } while (!isGuessed);
}

// Allows user to pick a new max value for the game
void getMax(int *gameMax)
{
    // Get users input
    _Bool isValid; // validity flag for valid user inputs
    do
    {
        printf("Enter a new max value (Valid range [1 - %d]): ", RAND_MAX);
        scanf("%d", gameMax);
        fflush(stdin); // clear input buffer
        printf("\n");
        isValid = 1;

        // Prints error for when user inputs an invalid option
        if (*gameMax < 1 || *gameMax > RAND_MAX)
        {
            printf("ERROR: Invalid input.\n");
            printf("\n");
            isValid = 0;
        }

    } while (!isValid); // Loop until valid input is given
}
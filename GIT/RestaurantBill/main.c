//=====================================================================================================
// Name: Sammy Alsadek
// File: main.c
// Date: Sep 29th 2021, 7:41PM
// Description: This is a program that will compute the tax and tip on a restaurant bill for a patron.
//              The program should accept the tax and tip both as percentages from the command line.
//              Display the meal cost, tax amount, tip amount, and total bill on the screen.
//=====================================================================================================

// Included files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Initialize random number generator
    time_t t;
    srand((unsigned)time(&t));

    // Declare variables
    float taxPercent = strtof(argv[1], NULL) / 100;                             // tax percent from command line converted to decimal for calculations
    float tipPercent = strtof(argv[2], NULL) / 100;                             // tip percent from command line converted to decimal for calculations
    const int NUMOFMEALS = 4;                                                   // total number of possible meals
    const char *mealNames[NUMOFMEALS] = {"Salad", "Soup", "Sandwich", "Pizza"}; // names of available meals
    const float mealCosts[NUMOFMEALS] = {9.95, 4.55, 13.25, 22.35};             // cost of available meals
    int randMeal = rand() % NUMOFMEALS;                                         // variable that holds the value of the random meal chosen

    // calculate the tax, tip, and total of the meal
    float taxValue = mealCosts[randMeal] * taxPercent;       // calculated value of tax
    float tipValue = mealCosts[randMeal] * tipPercent;       // calculated value of tip
    float total = mealCosts[randMeal] + taxValue + tipValue; // calculated total of meal

    // Display the meal cost, tax amount, tip amount, and total bill on the screen.
    printf("+=====================================+\n");
    printf("|           RESTAURANT BILL           |\n");
    printf("+=====================================+\n");
    printf("%s: $%.2f\n", mealNames[randMeal], mealCosts[randMeal]);
    printf("--------------------------------------\n");
    printf("Tax: $%.2f\n", taxValue);
    printf("Tip: $%.2f\n", tipValue);
    printf("--------------------------------------\n");
    printf("Total: $%.2f\n", total);
    printf("+=====================================+\n");
    printf("|              Thank You!             |\n");
    printf("+=====================================+\n");

    return 0;
}
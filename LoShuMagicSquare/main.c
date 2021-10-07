#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// GLOBAL DECLARATION
const int SIZE = 3;

// FUNCTION PROTOTYPES
int checkLoShuMagicSquare(const int square[][SIZE]);

int main(void)
{
    //Square declarations
    int square1[SIZE][SIZE] = {{4, 9, 2},
                               {3, 5, 7},
                               {8, 1, 6}},
        square2[SIZE][SIZE] = {{2, 7, 6},
                               {4, 5, 1},
                               {9, 3, 8}};

    //Example is a magic square
    if (checkLoShuMagicSquare(square1))
        printf("Square is a Lo Shu Magic Square.\n");
    else
        printf("Square is NOT a Lo Shu Magic Square.\n");

    //Example is NOT a magic square
    if (checkLoShuMagicSquare(square2))
        printf("Square is a Lo Shu Magic Square.\n");
    else
        printf("Square is NOT a Lo Shu Magic Square.\n");

    /*
    * Create and populate a two-dimensional array with random numbers from 1-9.
    * Recall no number should repeat when populating the array. Then check if it is a Lo Shu Magic Share.
    * Put this random number placement in a loop until you do get a Lo Shu Magic Square
    */

    //seed random number generator
    time_t t;
    srand((unsigned)time(&t));

    int isAvailable[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; //array to keep track of chosen values
    int randSquare[SIZE][SIZE];                       //randomly generated array
    int count = 0;                                    //number of randomly generater arrays

    //keep looping until a lo shu magic square is created
    do
    {
        //fill array randomly
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                int randNum = rand() % 9;
                if (isAvailable[randNum])
                {
                    randSquare[i][j] = randNum + 1;
                    isAvailable[randNum] = 0;
                }
                else
                    j--;
            }
        }

        //reset availability array
        for (int i = 0; i < 9; i++)
            isAvailable[i] = 1;

        count++;
    } while (!checkLoShuMagicSquare(randSquare));

    //Print total number of squares generated and tested before success, the count
    printf("Total number of squares generated and tested before success = %d\n", count);

    //Print the Lo Shu Magic Square
    for (int i = 0; i < SIZE; i++)
        printf("[%d %d %d]\n", randSquare[i][0], randSquare[i][1], randSquare[i][2]);
}
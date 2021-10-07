//Checks to see is horizontals equate to 15
static int horizontalSum(const int square[][3])
{
    int row1 = square[0][0] + square[0][1] + square[0][2];
    int row2 = square[1][0] + square[1][1] + square[1][2];
    int row3 = square[2][0] + square[2][1] + square[2][2];

    if (row1 == 15 && row2 == 15 && row3 == 15)
        return 15;
    else
        return 0;
}

//Checks to see is verticals equate to 15
static int verticalSum(const int square[][3])
{
    int col1 = square[0][0] + square[1][0] + square[2][0];
    int col2 = square[0][1] + square[1][1] + square[2][1];
    int col3 = square[0][2] + square[1][2] + square[2][2];

    if (col1 == 15 && col2 == 15 && col3 == 15)
        return 15;
    else
        return 0;
}

//Checks to see is diagonals equate to 15
static int diagonalSum(const int square[][3])
{
    int daig1 = square[0][0] + square[1][1] + square[2][2];
    int diag2 = square[2][0] + square[1][1] + square[0][2];

    if (daig1 == 15 && diag2 == 15)
        return 15;
    else
        return 0;
}

//Function that accepts a two-dimensional array as an argument and determines whether the array is a Lo Shu Magic Square
int checkLoShuMagicSquare(const int square[][3])
{
    if (horizontalSum(square) == 15 && verticalSum(square) == 15 && diagonalSum(square) == 15)
        return 1;
    else
        return 0;
}
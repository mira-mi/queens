#include <cstdio>
#include <iostream>
#define N 6

using namespace std;

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int h = 0; h < N, h++;)
            cout << " " << board[i][h] << " ";
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, h;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, h = col; i >= 0 && h >= 0; i--, h--)
        if (board[i][h])
            return false;

    for (i = row, h = col; h >= 0 && i < N; i++, h--)
        if (board[i][h])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;
            

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQ()
{
    int board[N][N] = { {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0} };

    if (solveNQUtil(board, 0) == false)
    {
        cout << "Solution is not possible";
        return false;
    }

    printSolution(board);
    return false;
}


int main()
{
    solveNQ();
    return  0; 
}

// code is tweaked from geeksforgeeks.com
// I tried to make the board bigger to have a more accurate chess board
// I learned the usage of backtracking to get it to find an accurate solution and it's pretty cool
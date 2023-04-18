#include <stdio.h>
#include <stdbool.h>
#define N 10
bool isSafe(int board[N][N], int row, int col);
bool solve_n_queens_util(int board[N][N], int col, int *solutionCount);

int main()
{
    int board[N][N] = {0};
    int solutionCount = 0;

    solve_n_queens_util(board, 0, &solutionCount);
    printf("Number of solutions for %d x %d board: %d\n", N, N, solutionCount);
    return 0;
}

bool isSafe(int board[N][N], int row, int col)
{
    // check whether any queen on same row to the left -> so iterate through the columns
    // no need to check right
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // check upper diagonal on the left side
    int i, j;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // check lower diagonal on the left
    for (i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solve_n_queens_util(int board[N][N], int col, int *solutionCount)
{
    // Base case -> found solution - when the column we are at is greater than N
    if (col >= N)
    {
        (*solutionCount)++;
        return true;
    }

    bool found = false; // keep track of whether we found a queen for current col
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;                                                   // place queen
            found = solve_n_queens_util(board, col + 1, solutionCount) || found; // recursively call on next col
            board[i][col] = 0;                                                   // Backtrack
        }
    }

    return found;
}
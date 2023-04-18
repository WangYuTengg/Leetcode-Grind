#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int knapSack(int C, int sizes[], int values[], int n);

int main()
{
    int values[] = {60, 100, 120};              // value array
    int sizes[] = {10, 20, 30};                 // size array
    int C = 50;                                 // capacity of knapsack
    int N = sizeof(values) / sizeof(values[0]); // number of items
    printf("Maximum value in knapsack: %d\n", knapSack(C, sizes, values, N));
    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int C, int sizes[], int values[], int n)
{
    int i, w;
    int M[n + 1][C + 1]; // initialise n+1 X C+1 matrix

    // start filling up matrix
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= C; w++)
        {
            // fill up first row and first col with zeroes
            if (i == 0 || w == 0)
                M[i][w] = 0;

            // if size of (i-1)th item is less than equal to capacity w
            else if (sizes[i - 1] <= w)
                M[i][w] = max(M[i - 1][w], values[i - 1] + M[i - 1][w - sizes[i - 1]]);

            else
                M[i][w] = M[i - 1][w];
        }
    }

    // return last cell for maximum value
    return M[n][C];
}
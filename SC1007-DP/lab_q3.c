#include <stdio.h>
#include <stdlib.h>

int waysToScore(int n, int *score)
{

    // initialise DP array
    int r[n + 1];
    for (int i = 0; i <= n; i++)
    {
        r[i] = 0;
    }
    r[0] = 1; // 1 way to score 0 points

    for (int i = 1; i <= n; i++)
    {
        if (i - score[0] >= 0)
            r[i] += r[i - score[0]];
        if (i - score[1] >= 0)
            r[i] += r[i - score[1]];
        if (i - score[2] >= 0)
            r[i] += r[i - score[2]];
    }

    return r[n];
}

void main()
{
    int n;

    int score[3] = {3, 5, 10};

    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("The number of ways to reach to a score of %d is: %d \n", n, waysToScore(n, score));
}

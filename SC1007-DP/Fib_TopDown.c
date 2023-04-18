#include <stdio.h>
#define N 8

int fib_topDown(int M[N], int n);

int main()
{
    // initialise array
    int memoArray[N];
    for (int i = 0; i < N; i++)
    {
        memoArray[i] = 0;
    }

    int res = fib_topDown(memoArray, N);
    printf("Fib of %d = %d\n", N, res);
    return 0;
}

// memoization approach
int fib_topDown(int M[N], int n)
{

    // base cases n = 1 , n = 0
    if (n == 0)
    {
        M[0] = 0;
        return 0;
    }

    if (n == 1)
    {
        M[1] = 1;
        return 1;
    }

    if (!M[n - 1])
        M[n - 1] = fib_topDown(M, n - 1);
    if (!M[n - 2])
        M[n - 2] = fib_topDown(M, n - 2);

    M[n] = M[n - 1] + M[n - 2];
    return M[n];
}
#include <stdio.h>

int fib_bottomUp(int n);

int main()
{
    int n = 6;
    int res = fib_bottomUp(n);
    printf("Fib of %d = %d\n", n, res);
    return 0;
}

int fib_bottomUp(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int fib_minus_2 = 0;
    int fib_minus_1 = 1;
    int fib_n;

    for (int i = 2; i <= n; i++)
    {
        fib_n = fib_minus_1 + fib_minus_2;
        fib_minus_2 = fib_minus_1;
        fib_minus_1 = fib_n;
    }

    return fib_n;
}

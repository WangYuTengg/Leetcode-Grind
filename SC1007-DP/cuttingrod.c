#include <stdio.h>
#define INT_MIN -9999
#define N 4

int rodCuttingUtil(int *r, int *prices);
int main()
{

    // prices array
    int prices[] = {1, 5, 7, 8};

    // initialise array to store maximum revenue for each length
    int r[N + 1];
    r[0] = 0;

    int max = rodCuttingUtil(r, prices);
    printf("Maximum revenue from selling rod: %d \n", max);
    return 0;
}

int rodCuttingUtil(int *r, int *prices)
{
    // finding the max revenue for a rod of length i
    for (int i = 1; i <= N; i++)
    {
        int max_val = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            // calculate revenue for cut j and remaining rod i-j
            int revenue = prices[j - 1] + r[i - j];
            max_val = (revenue > max_val) ? revenue : max_val;
        }
        r[i] = max_val;
    }
    return r[N];
}
#include <stdio.h>
#include <stdlib.h>

// memory
int *r;

// No DP involved -> exponential time complexity
int cr_recursive(int *p, int n)
{
    // base case
    if (n == 0)
        return 0;

    int max_val = -999;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        temp = p[i] + cr_recursive(p, n - i);
        max_val = (max_val > temp) ? max_val : temp;
    }
    return max_val;
}

// Like recursion but with memory now
int cr_top_down_dp(int *p, int n)
{
    // base case
    if (n == 0)
        return 0;

    // check memory
    if (r[n] > 0)
        return r[n];

    int max_val = -999;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        temp = p[i] + cr_top_down_dp(p, n - i);
        if (temp > max_val)
        {
            max_val = temp;
        }
    }

    // write to memory
    r[n] = max_val;
    return r[n];
}

int cr_bottom_up_dp(int *p, int n)
{
    r[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int max_val = -999;
        for (int j = 1; j <= i; j++)
        {
            int revenue = p[j] + r[i - j];
            max_val = (revenue > max_val) ? revenue : max_val;
        }
        r[i] = max_val;
    }
    return r[n];
}

void main()
{
    int n; // length of  rod
    int function;
    int i;
    int *p; // price list

    int price_list[10] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24}; // declare one more value to cover the index 0;

    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;

    // allocate the memory array
    r = malloc(sizeof(int) * (n + 1));

    printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
    scanf("%d", &function);
    while (function != 0)
    {
        if (function == 1)
        {
            printf("The maximum value is: %d \n", cr_recursive(p, n));
        }
        else if (function == 2)
        {
            // set all memory elements to -1
            for (i = 0; i <= n; i++)
                r[i] = -1;

            printf("The maximum value is: %d \n", cr_top_down_dp(p, n));
        }
        else if (function == 3)
        {
            // set all memory elements to -1
            for (i = 0; i <= n; i++)
                r[i] = -1;

            printf("The maximum value is: %d \n", cr_bottom_up_dp(p, n));
        }
        printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
        scanf("%d", &function);
    }
}
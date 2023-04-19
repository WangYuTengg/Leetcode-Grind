#include <stdio.h>
#include <stdlib.h>

// memory
int *r;

int cr_bottom_up_dp_print(int *p, int n)
{
    r[0] = 0;

    // to store the optimal cut position for each rod length i
    int s[n + 1];
    for (int i = 0; i <= n; i++)
    {
        s[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        int max_val = -999;
        int cut_position = 0;
        for (int j = 1; j <= i; j++)
        {
            int revenue = p[j] + r[i - j];
            if (revenue > max_val)
            {
                max_val = revenue;
                cut_position = j;
            }
        }
        s[i] = cut_position;
        r[i] = max_val;
    }

    int len = n;
    printf("Optimal rod lengths: \n");
    while (len > 0)
    {
        printf("%d ", s[len]);
        len -= s[len];
    }
    printf("\n");

    return r[n];
}

void main()
{
    int n; // length of  rod
    int function;
    int i;
    int *p; // price list

    int price_list[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 22, 26}; // declare one more value to cover the index 0;

    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;

    // allocate the memory array
    r = malloc(sizeof(int) * (n + 1));

    // set all memory elements to -1
    for (i = 0; i <= n; i++)
        r[i] = -1;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p, n));
}
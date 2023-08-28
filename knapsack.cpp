#include <stdio.h>

#include <stdlib.h>

int maximum(int a, int b)
{

    if (a > b)

        return a;

    return b;
}

int main()
{

    int m, n, w[20], p[20], v[21][101], x[20];

    int i, j;

    printf("Enter the number of objects: ");

    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");

    scanf("%d", &m);

    printf("Enter the weights of each object:\n");

    for (i = 1; i <= n; i++)
    {

        scanf("%d", &w[i]);
    }

    printf("Enter the profits of each object:\n");

    for (i = 1; i <= n; i++)
    {

        scanf("%d", &p[i]);
    }

    printf("Computing...\n");

    for (i = 0; i <= n; i++)
    {

        for (j = 0; j <= m; j++)
        { // Corrected the loop termination condition

            if (i == 0 || j == 0)

                v[i][j] = 0;

            else if (w[i] > j)

                v[i][j] = v[i - 1][j];

            else

                v[i][j] = maximum(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
        }
    }

    for (i = 0; i <= n; i++)
    {

        for (j = 0; j <= m; j++)
        { // Corrected the loop termination condition

            printf("%d\t", v[i][j]);
        }

        printf("\n");
    }

    printf("Maximum profit is %d\n", v[n][m]);

    for (i = 1; i <= n; i++)

    {

        x[i] = 0;
    }

    i = n;

    j = m;

    while (i != 0 && j != 0)

    {

        if (v[i][j] != v[i - 1][j])

        {

            x[i] = 1;

            j = j - w[i];
        }

        i = i - 1;
    }

    printf("Solution vector\n");

    for (i = 1; i <= n; i++)

    {

        printf("%d\t", x[i]);
    }

    return 0;
}
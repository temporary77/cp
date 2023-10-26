#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j <= i && j >= i - n)
            {
                if (c > 9)
                {
                    c = c % 10;
                }
                else if (c < 0)
                {
                    c = (10 + (c % 10)) % 10;
                }
                printf("%d ", c);
                if (j != i && j != n - 1)
                {
                    c += ((i / n) * ((n + 1) % 2) + i) % 2 * -2 + 1;
                }
            }
            else
            {
                printf("  ");
            }
        }
        if (i == n - 1)
        {
            c += (n - 1) * (i % 2);
        }
        else
        {
            c += (1 - (i / n)) * (i / 2 + 1) * 2 - (i / n) * (((n * 2 - i + (n + 1) % 2) / 2 * 2) - (n + 1) % 2);
        }
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c, mode;
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; ++i)
    {
        c = 1, mode = 1;
        for (int j = 0; j < 3 * n; ++j)
        {
            if (((j >= n + i && j <= 2 * n - 1 - i) || (j >= 4 * n - 1 - i && j <= i - n)) || ((i >= n + j && i <= 2 * n - 1 - j) || (i >= 4 * n - 1 - j && i <= j - n)))
            {
                printf(" ");
            }
            else
            {
                printf("%d", c % 10);
            }
            if (j == i)
            {
                --mode;
            }
            if (j == 3 * n - 1 - i)
            {
                --mode;
            }
            c += mode;
        }
        printf("\n");
    }
    return 0;
}